#include <iostream>
#include "Funcionalidades/preConfiguracion/preConfiguracion.h" // Solo una vez

// Importar Clases
#include "Funcionalidades/system/system.h"
#include "Funcionalidades/buscador/buscador.h"
#include "Funcionalidades/libro/libro.h"
#include "Funcionalidades/bibliotecario/bibliotecario.h"
#include "Funcionalidades/alumno/alumno.h"
#include "Funcionalidades/login/login.h" // Si vas a usar login

using namespace std; // Importante si usas string sin std::


string NombreUsuario= "Invitado";
int codigo = 1;
/// Variables
const char *nom = NombreUsuario.c_str();
///Crear entedidad del sistema de gestion
int DNI=12345;
Bibliotecario admin(codigo,nom,DNI); 
///Clase encargada de los metodos de bajo nivel
System sistema;

/// Nombre del Binario de test
string libros = "Recursos/Binarios/libros.bin";
string usuarios = "Recursos/Binarios/usuarios.bin";
string bibliotecarios = "Recursos/Binarios/bibliotecarios.bin";

///Clase encargada de las busquedas
Buscador navega;
string palabra="Casa";

vector<Libro> resultadoLibros;
///Estados Especiales
///De alumno
string sancionados = "Recursos/binarios/sancionados.bin";
///De libro
string prestados = "Recursos/binarios/prestados.bin";
string matematica = "Recursos/binarios/matematica.bin";
string poo = "Recursos/binarios/poo.bin";
string fisica = "Recursos/binarios/fisica.bin";
///N-tags


vector<Libro> vectorLibros = sistema.VerContenido<Libro>(libros, 1);
int idLibro;
int Nlibros;	

///Iteradores para los metodos
vector<Libro>::const_iterator it;
vector<Libro>::const_iterator itBorrar;
int c; //ya apareci

vector<Tags> Etiquetas;
string etiquetasLibros = "Recursos/binarios/Tags/Libros.bin";
string TagsAlmunos= "Recursos/binarios/Tags/Alumnos.bin";



void menuBibliotecario();
void menuAlumno();


int main(){
	/*Login
	//menuBibliotecario();
	cout<<"Sistema de gestion Bibliotecario!!!"<<endl<<endl;
	
	int dni;
	cout<<"Ingrese su Documento de Identidad, por favor: ";
	cin>>dni;
	
	string AlumnosPath ="Recursos/Binarios/alumnos.bin";
	string BibliotecarioPath="Recursos/Binarios/bibliotecario.bin";
	

	vector<Bibliotecario> vectorBibliotecario = sistema.VerContenido<Bibliotecario>(BibliotecarioPath,true);
	int PosBibliotecario = BuscarDniEnBibliotecarios(dni, vectorBibliotecario);
	//Declarar Variables para ser usadas en la ejecucion
	Alumno alumn;
	Bibliotecario biblio;
	
	if(PosBibliotecario != -1){
		biblio = ObjetoCorrespondienteBibliotecario(PosBibliotecario, vectorBibliotecario);
		cout<<"�Qu� Quieres Hacer "<<biblio.VerNombre()<<" ?"<<endl;
		
	}
	else{
		vector<Alumno> vectorAlumno = sistema.VerContenido<Alumno>(AlumnosPath,true);
		int PosAlumno = BuscarDniEnAlumnos(dni,vectorAlumno);
		if(PosAlumno!= -1){
			alumn = ObjetoCorrespondienteAlumno(PosAlumno, vectorAlumno); 
			cout<<"�Qu� Quieres Hacer "<<alumn.VerNombre()<<" ?"<<endl;
		}else{
			string nombre;
			cout<<"Ingresa tu nombre: ";cin>>nombre;
			int id = 12;
			alumn = Alumno(id, nombre.c_str(), dni);
		}
	}
	*/
	//Fin login, tenemos o un Bibliotecario o un Alumno
///	Busqueda de libros basado en una palabra
	//vector<Libro> encontrar = posiciones(palabraBuscada, vectorLibros);

//Agregar Libros
	int cant;
	cout<<"�Cuantos elementos?: ";cin>>cant;
	vector<Libro> Agregados= admin.AgregarElementos<Libro>(cant,libros);

	cout<<endl<<"Datos ingresados: "<<endl;

	for(Libro&x : Agregados)
		cout<<x.VerNombre()<<endl;
	char confirmar;
	cout<<"Confirmar?: s/n";cin>>confirmar;


	return 0;
}
	
	
	void menuBibliotecario(){
		cout<<"Sistema de gestion Bibliotecario!!!"<<endl<<endl;
		int opcion=-1;
		while(opcion!=0){
			
			cout<<"Menu de gestion"<<endl;
			cout<<"1. Libros"<<endl
				<<"2. Usuarios"<<endl
				<<"3. Bibliotecarios"<<endl
				<<"0. Salir"
				<<endl
				<<"Selecciona: ";cin>>opcion;
				
				//	cin.get();
				system("cls");	
				
				switch (opcion){
				case 1://Menu libro
					while(opcion!=6){
						cout<<"Menu Libros"<<endl;
						cout<<"1. Ver libros"<<endl
							<<"2. Buscar libros"<<endl
							<<"3. Eliminar libro"<<endl
							<<"4. Agregar Libro"<<endl
							<<"5. Etiquetas"<<endl
							<<"6. Volver"
							
							<<endl
							<<"Selecciona: ";cin>>opcion;
							
							system("cls");
							switch (opcion){
							case 1:
								cout<<"Libros Disponibles: "<<endl;	
								///Contenido Actual
								for(Libro &x: vectorLibros)
									cout
									<<"Nombre Libro: " 	<<x.VerNombre()
									<<"  Id: "	<<x.VerID()
									<<endl; 
								
								
								cout<<endl<<endl<<"Preciona para volver";
								cin.ignore();
								cin.get();
								system("cls");
								break;
							case 2:
								///Buscar libro
								///Terminal			| Entrada
								cout<<"Buscar libro, indica ID: ";cin>>idLibro;
								
								///Buscar Libro		| Proceso
								
								resultadoLibros = navega.Buscar(palabra,Etiquetas,50);
								
								
								cout<<endl<<endl<<"Preciona para volver";
								cin.ignore();
								cin.get();
								system("cls");
								
								break;
							case 3:
								cout<<"ID a eliminar: ";cin>>idLibro;
								
								
								///Buscar Libro		| Proceso
								resultadoLibros = navega.Buscar(palabra,Etiquetas,50);
								
								/*if(it!= vectorLibros.end() ){
								///Muestra 			| Salida
								cout<<"Libro: "<<endl
								<<"Nombre: "<<(*(it)).VerNombre()
								<<endl 
								<<"ID: "<<(*(it)).VerID()
								<<endl;
								
								char borrar;
								cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
								if(borrar=='s'){
								///Uso del metodo 	| Proceso
								itBorrar = navega.Buscar(idLibro,vectorLibros);
								admin.EliminarLibro(itBorrar,vectorLibros);
								sistema.Guardar<Libro>(libros,vectorLibros);
								}
								}else{ cout<<endl<<"Codigo No existente";}
								
								*/
								cout<<endl<<endl<<"Preciona para volver";
								cin.ignore();
								cin.get();
								system("cls");
								
								break;
								case 4:
									cout<<"Agregar Libro...";
									cout<<"LIbros a agregar: ";cin>>Nlibros;
									///Uso del metodo	| Proceso
									if(!Nlibros==0){
										vectorLibros = admin.AgregarElementos<Libro>(Nlibros,libros);	
										sistema.Guardar<Libro>(libros,vectorLibros);
										vectorLibros = sistema.VerContenido<Libro>(libros,true);
										cout<<"Agregados Corectamente!"<<endl;
									}	
									cout<<endl<<endl<<"Preciona para volver";
									cin.ignore();
									cin.get();
									system("cls");
									
									break;
								case 5:
									opcion=-1;
									while(opcion!=5){
										cout<<"Menu Etiquetas"<<endl;
										cout<<"1. Ver Etiquetas"<<endl
											<<"2. Buscar Etiquetas"<<endl
											<<"3. Eliminar Etiquetas"<<endl
											<<"4. Agregar Etiquetas"<<endl
											<<"5. Volver"
											
											<<endl
											<<"Selecciona: ";cin>>opcion;
											
											system("cls");
											switch (opcion){
											case 1:
												
												cout<<"Etiquetas Existentes: "<<endl;
												cout<<"De Libros: "<<endl;
												Etiquetas = sistema.etiquetas(etiquetasLibros);
												c=0;
												for(Tags& x : Etiquetas)
													cout<<++c<<" ) "<<x.nombre<<endl;
												cout<<"De Alumnos: "<<endl;
												Etiquetas = sistema.etiquetas(TagsAlmunos);
												c=0;
												for(Tags& x : Etiquetas)
													cout<<++c<<" ) "<<x.nombre<<endl;
												
												cout<<endl<<endl<<"Preciona para volver";
												cin.ignore();
												cin.get();
												system("cls");
												break;
											case 2:
												cout<<"Buscar Etiquetas...";
												cout<<endl<<endl<<"Preciona para volver";
												cin.ignore();
												cin.get();
												system("cls");
												break;
												
											case 3:
												cout<<"Eliminar Etiquetas...";
												cout<<endl<<endl<<"Preciona para volver";
												cin.ignore();
												cin.get();
												system("cls");
												break;
												
											case 4:
												cout<<"Agregar Etiquetas...";
												///Carga en memoria N elementos
												//VectorTags= vacio
												//bibliotecario.Agregar<Tags>(VectorTags)
												//VectorTags=lleno
												///Va al bin a cargarlo
												//sistema.Guardar<Tags>(VectorTags)
												cout<<endl<<endl<<"Preciona para volver";
												cin.ignore();
												cin.get();
												system("cls");
												break;
												
											case 5:
												///volver
												break;
												
											default:
												break;
											}///Fin case, etiquetas
									}///Fin While etiquetas
								case 6:
										  //Volviendo
										  break;
										  
										  
								default:
									break;
									
							}///Case
					}
					///While Menu Libros	
					//Casos Usuarios, Bibliotecarios, ...
				default:
						  break;
						  
				}//Case
		}///While Principal
	}//Fin funcion
		
		
		void menuAlumno(){
			cout<<"Sistema de Aluno"<<endl<<endl;
			int opcion=-1;
			while(opcion!=0){
				
				cout<<"Menu de gestion"<<endl;
				cout<<"Menu para Alumno"<<endl
					<<"1. BuscarLibro()"<<endl
					<<"2. VerLibros()"<<endl
					<<"3. VerHistorial()"<<endl
					<<"4. VerHistorial()"<<endl
					<<"5. LibrosPrestadosActualmente()"<<endl
					<<"0. Salir"
					<<endl
					<<"Selecciona: ";
					cin>>opcion;
					
					//	cin.get();
					system("cls");	
					
					switch (opcion){
					case 1://Menu libro
						while(opcion!=6){
							cout<<"Menu Libros"<<endl;
							cout<<"1. Ver libros"<<endl
								<<"2. Buscar libros"<<endl
								<<"3. Etiquetas"<<endl
								<<"4. Volver"
								
								<<endl
								<<"Selecciona: ";cin>>opcion;
								
								system("cls");
								switch (opcion){
								case 1:
									cout<<"Libros Disponibles: "<<endl;	
									///Contenido Actual
									for(Libro &x: vectorLibros)
										cout
										<<"Nombre Libro: " 	<<x.VerNombre()
										<<"  Id: "	<<x.VerID()
										<<endl; 
									
									
									cout<<endl<<endl<<"Preciona para volver";
									cin.ignore();
									cin.get();
									system("cls");
									break;
								case 2:
									///Buscar libro
									///Terminal			| Entrada
									cout<<"Buscar libro, indica ID: ";cin>>idLibro;
									
									///Buscar Libro		| Proceso
									
									resultadoLibros = navega.Buscar(palabra,Etiquetas,50);
									
									
									cout<<endl<<endl<<"Preciona para volver";
									cin.ignore();
									cin.get();
									system("cls");
									
									break;
									case 3:
										opcion=-1;
										while(opcion!=5){
											cout<<"Menu Etiquetas"<<endl;
											cout<<"1. Ver Etiquetas"<<endl
												<<"2. Buscar Etiquetas"<<endl
												<<"3. Eliminar Etiquetas"<<endl
												<<"4. Agregar Etiquetas"<<endl
												<<"5. Volver"
												
												<<endl
												<<"Selecciona: ";cin>>opcion;
												
												system("cls");
												switch (opcion){
												case 1:
													
													cout<<"Etiquetas Existentes: "<<endl;
													cout<<"De Libros: "<<endl;
													Etiquetas = sistema.etiquetas(etiquetasLibros);
													c=0;
													for(Tags& x : Etiquetas)
														cout<<++c<<" ) "<<x.nombre<<endl;
													cout<<"De Alumnos: "<<endl;
													Etiquetas = sistema.etiquetas(TagsAlmunos);
													c=0;
													for(Tags& x : Etiquetas)
														cout<<++c<<" ) "<<x.nombre<<endl;
													
													cout<<endl<<endl<<"Preciona para volver";
													cin.ignore();
													cin.get();
													system("cls");
													break;
												case 2:
													cout<<"Buscar Etiquetas...";
													cout<<endl<<endl<<"Preciona para volver";
													cin.ignore();
													cin.get();
													system("cls");
													break;
													
												case 3:
													cout<<"Eliminar Etiquetas...";
													cout<<endl<<endl<<"Preciona para volver";
													cin.ignore();
													cin.get();
													system("cls");
													break;
													
												case 4:
													cout<<"Agregar Etiquetas...";
													///Carga en memoria N elementos
													//VectorTags= vacio
													//bibliotecario.Agregar<Tags>(VectorTags)
													//VectorTags=lleno
													///Va al bin a cargarlo
													//sistema.Guardar<Tags>(VectorTags)
													cout<<endl<<endl<<"Preciona para volver";
													cin.ignore();
													cin.get();
													system("cls");
													break;
													
												case 5:
													///volver
													break;
													
												default:
													break;
												}///Fin case, etiquetas
										}///Fin While etiquetas
									case 6:
											  //Volviendo
											  break;
											  
											  
									default:
										break;
										
								}///Case
						}
						///While Menu Libros	
						//Casos Usuarios, Bibliotecarios, ...
					default:
							  break;
							  
					}//Case
			}///While Principal
		}//Fin funcion
			
			
			
	
