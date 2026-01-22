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
string alumnos = "Recursos/Binarios/alumnos.bin";
string bibliotecarios = "Recursos/Binarios/bibliotecarios.bin";

///Clase encargada de las busquedas
Buscador navega;
string palabra="Casa";

vector<Libro> resultadoLibros;
///Estados Especiales
///De alumno
string sancionados = "Recursos/binarios/sancionados.bin";
string HistorialPrestamos= "Recursos/binarios/Historial.bin";
///De libro
string prestados = "Recursos/binarios/prestados.bin";
string matematica = "Recursos/binarios/matematica.bin";
string poo = "Recursos/binarios/poo.bin";
string fisica = "Recursos/binarios/fisica.bin";
///N-tags


vector<Libro> vectorLibros = sistema.VerContenido<Libro>(libros, 1);
vector<Alumno> vectorAlumnos = sistema.VerContenido<Alumno>(alumnos, 1);
vector<Bibliotecario> vectorBibliotecario = sistema.VerContenido<Bibliotecario>(bibliotecarios, 1);
int idLibro;
int cant;	

///Iteradores para los metodos
vector<Libro>::const_iterator it;
vector<Libro>::const_iterator itBorrar;
int c; //ya apareci

vector<Tags> Etiquetas;
string etiquetasLibros = "Recursos/binarios/Tags/Libros.bin";
string TagsAlmunos= "Recursos/binarios/Tags/Alumnos.bin";



void menuBibliotecario();
void menuAlumno();
vector<Libro> BuscarLibro;

int main(){

	vectorAlumnos = sistema.VerContenido<Alumno>(alumnos,true);
	vectorBibliotecario= sistema.VerContenido<Bibliotecario>(bibliotecarios,true);
	vectorLibros = sistema.VerContenido<Libro>(libros,true);
	
	
	
	//Login
	//menuBibliotecario();
	cout<<"Sistema de gestion Bibliotecario!!!"<<endl<<endl;
	
	int dni;
	cout<<"Ingrese su Documento de Identidad, por favor: ";
	cin>>dni;
	

	int PosBibliotecario = BuscarDniEnBibliotecarios(dni, vectorBibliotecario);
	cout<<"PosBibliotecario: "<<PosBibliotecario<<endl;
	//Declarar Variables para ser usadas en la ejecucion
	Alumno alumn;
	Bibliotecario biblio;

	
	
	if(PosBibliotecario != -1){
		biblio = ObjetoCorrespondienteBibliotecario(PosBibliotecario, vectorBibliotecario);
		cout<<"�Que Quieres Hacer "<<biblio.VerNombre()<<" ?"<<endl;
//			menuBibliotecario();
	}
	else{
		int PosAlumno = BuscarDniEnAlumnos(dni,vectorAlumnos);
		if(PosAlumno!= -1){
			alumn = ObjetoCorrespondienteAlumno(PosAlumno, vectorAlumnos); 
			cout<<"PosAlumno: "<<PosAlumno<<endl;

			cout<<"�Que Quieres Hacer "<<alumn.VerNombre()<<" ?"<<endl;
			cout<<"Menu alumno..";
		}else{
			cout<<"No est�s en el sistema... Registrandote"<<endl;
			cant=1;
			admin.CargarNuevos<Alumno>(cant,alumnos);
		}
	}
	
	//Fin login, tenemos  un Bibliotecario o un Alumno
///	Busqueda de libros basado en una palabra
	//vector<Libro> encontrar = posiciones(palabraBuscada, vectorLibros);

/*Agregar Nuevos
	cant=1;
	admin.CargarNuevosLibros(cant,libros);
*/	///Actualizar
	
	return 0;
}
	
	
//	void menuBibliotecario(){
//	
//		int opcion=-1;
//		while(opcion!=0){
//			
//			cout<<"Menu de gestion"<<endl;
//			cout<<"1. Libros"<<endl
//				<<"2. Alumnos"<<endl
//				<<"3. Bibliotecarios"<<endl
//				<<"0. Salir"
//				<<endl
//				<<"Selecciona: ";cin>>opcion;
//				
//				//	cin.get();
//				system("cls");	
//				
//				switch (opcion){
//				case 1://Menu libro
//					while(opcion!=6){
//						cout<<"Menu Libros"<<endl;
//						cout<<"1. Ver libros"<<endl
//							<<"2. Buscar libros"<<endl
//							<<"3. Eliminar libro"<<endl
//							<<"4. Agregar Libro"<<endl
//							<<"5. Etiquetas"<<endl
//							<<"6. Volver"
//							
//							<<endl
//							<<"Selecciona: ";cin>>opcion;
//							
//							system("cls");
//							switch (opcion){
//							case 1:
//								cout<<"Libros Disponibles: "<<endl;	
//								///Contenido Actual
//								vectorLibros = sistema.VerContenido<Libro>(libros,true);
//								
//								for(Libro& x: vectorLibros)
//									cout<<x.VerNombre()<<"   "<<x.VerID()<<endl;
//								
//								cout<<endl<<endl<<"------------------------------"<<endl;
//								
//								
//								
//								cout<<endl<<endl<<"Presiona para volver";
//								cin.ignore();
//								cin.get();
//								system("cls");
//								break;
//							case 2:
//								///Buscar libro
//								///Terminal			| Entrada
//								cout<<"Buscar libro, indica ID: ";cin>>idLibro;
//								
//								///Buscar Libro		| Proceso
//								
//								resultadoLibros = navega.Buscar(palabra,Etiquetas,50);
//								
//								
//								cout<<endl<<endl<<"Presiona para volver";
//								cin.ignore();
//								cin.get();
//								system("cls");
//								
//								break;
//							case 3:
//								cout<<"ID a eliminar: ";cin>>idLibro;
//								
//								
//								///Buscar Libro		| Proceso
//								resultadoLibros = navega.Buscar(palabra,Etiquetas,50);
//								
//								/*if(it!= vectorLibros.end() ){
//								///Muestra 			| Salida
//								cout<<"Libro: "<<endl
//								<<"Nombre: "<<(*(it)).VerNombre()
//								<<endl 
//								<<"ID: "<<(*(it)).VerID()
//								<<endl;
//								
//								char borrar;
//								cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
//								if(borrar=='s'){
//								///Uso del metodo 	| Proceso
//								itBorrar = navega.Buscar(idLibro,vectorLibros);
//								admin.EliminarLibro(itBorrar,vectorLibros);
//								sistema.Guardar<Libro>(libros,vectorLibros);
//								}
//								}else{ cout<<endl<<"Codigo No existente";}
//								
//								*/
//								cout<<endl<<endl<<"Presiona para volver";
//								cin.ignore();
//								cin.get();
//								system("cls");
//								
//								break;
//								case 4:
//									cout<<"Libros a agregar: ";cin>>cant;
//									admin.CargarNuevosLibros(cant,libros);
//									
//									
//									cout<<endl<<endl<<"Presiona para volver";
//									cin.ignore();
//									cin.get();
//									system("cls");
//									
//									break;
//								case 5:
//									opcion=-1;
//									while(opcion!=5){
//										cout<<"Menu Etiquetas"<<endl;
//										cout<<"1. Ver Etiquetas"<<endl
//											<<"2. Buscar Etiquetas"<<endl
//											<<"3. Eliminar Etiquetas"<<endl
//											<<"4. Agregar Etiquetas"<<endl
//											<<"5. Volver"
//											
//											<<endl
//											<<"Selecciona: ";cin>>opcion;
//											
//											system("cls");
//											switch (opcion){
//											case 1:
//												
//												cout<<"Etiquetas Existentes: "<<endl;
//												cout<<"De Libros: "<<endl;
//												Etiquetas = sistema.etiquetas(etiquetasLibros);
//												c=0;
//												for(Tags& x : Etiquetas)
//													cout<<++c<<" ) "<<x.VerNombre()<<endl;
//												cout<<"De Alumnos: "<<endl;
//												Etiquetas = sistema.etiquetas(TagsAlmunos);
//												c=0;
//												for(Tags& x : Etiquetas)
//													cout<<++c<<" ) "<<x.VerNombre()<<endl;
//												
//												cout<<endl<<endl<<"Presiona para volver";
//												cin.ignore();
//												cin.get();
//												system("cls");
//												break;
//											case 2:
//												cout<<"Buscar Etiquetas...";
//												cout<<endl<<endl<<"Presiona para volver";
//												cin.ignore();
//												cin.get();
//												system("cls");
//												break;
//												
//											case 3:
//												cout<<"Eliminar Etiquetas...";
//												cout<<endl<<endl<<"Presiona para volver";
//												cin.ignore();
//												cin.get();
//												system("cls");
//												break;
//												
//											case 4:
//												cout<<"Agregar Etiquetas...";
//												///Carga en memoria N elementos
//												//VectorTags= vacio
//												//bibliotecario.Agregar<Tags>(VectorTags)
//												//VectorTags=lleno
//												///Va al bin a cargarlo
//												//sistema.Guardar<Tags>(VectorTags)
//												cout<<endl<<endl<<"Presiona para volver";
//												cin.ignore();
//												cin.get();
//												system("cls");
//												break;
//												
//											case 5:
//												///volver
//												break;
//												
//											default:
//												break;
//											}///Fin case, etiquetas
//									}///Fin While etiquetas
//								case 6:
//										  //Volviendo
//										  break;
//										  
//										  
//								default:
//									break;
//									
//							}///Case
//					}
//					///While Menu Libros
//				case 2:
//						  while(opcion!=6){
//							  cout<<"Gestion de Alumnos"<<endl;
//							  cout<<"1. Ver Alumnos"<<endl
//								  <<"2. Buscar Alumnos"<<endl
//								  <<"3. Eliminar Alumnos"<<endl
//								  <<"4. Agregar Alumnos"<<endl
//								  <<"5. Etiquetas"<<endl
//								  <<"6. Volver"
//								  
//								  <<endl
//								  <<"Selecciona: ";cin>>opcion;
//								  
//								  system("cls");
//								  switch (opcion){
//								  case 1:
//									  vectorAlumnos = sistema.VerContenido<Alumno>(alumnos,true);
//									  
//									  cout<<"Alumnos: "<<endl;
//									  for(Alumno& x: vectorAlumnos)
//										  cout<<x.VerNombre()<<"   "<<x.VerDNI()<<"   "<<x.VerID()<<endl;
//									  
//									  cout<<endl<<endl<<"------------------------------"<<endl;
//									  
//									  
//									  cout<<endl<<endl<<"Presiona para volver";
//									  cin.ignore();
//									  cin.get();
//									  system("cls");
//									  break;
//								  case 2:
//									cout<<"Buscar alumno"<<endl;  
//									  cout<<endl<<endl<<"Presiona para volver";
//									  cin.ignore();
//									  cin.get();
//									  system("cls");
//									  
//									  break;
//								  case 3:
//									//  cout<<"ID a eliminar: ";cin>>idLibro;
//									  
//									  
//									  /*if(it!= vectorLibros.end() ){
//									  ///Muestra 			| Salida
//									  cout<<"Libro: "<<endl
//									  <<"Nombre: "<<(*(it)).VerNombre()
//									  <<endl 
//									  <<"ID: "<<(*(it)).VerID()
//									  <<endl;
//									  
//									  char borrar;
//									  cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
//									  if(borrar=='s'){
//									  ///Uso del metodo 	| Proceso
//									  itBorrar = navega.Buscar(idLibro,vectorLibros);
//									  admin.EliminarLibro(itBorrar,vectorLibros);
//									  sistema.Guardar<Libro>(libros,vectorLibros);
//									  }
//									  }else{ cout<<endl<<"Codigo No existente";}
//									  
//									  */
//									  cout<<endl<<endl<<"Presiona para volver";
//									  cin.ignore();
//									  cin.get();
//									  system("cls");
//									  
//									  break;
//									  case 4:
//										  cout<<"Alumnos a agregar: ";cin>>cant;
//										  admin.CargarNuevos<Alumno>(cant,alumnos);
//										  
//										  
//										  cout<<endl<<endl<<"Presiona para volver";
//										  cin.ignore();
//										  cin.get();
//										  system("cls");
//										  
//										  break;
//									  case 5:
//										  opcion=-1;
//										  while(opcion!=5){
//											  cout<<"Menu Etiquetas"<<endl;
//											  cout<<"1. Ver Etiquetas"<<endl
//												  <<"2. Buscar Etiquetas"<<endl
//												  <<"3. Eliminar Etiquetas"<<endl
//												  <<"4. Agregar Etiquetas"<<endl
//												  <<"5. Volver"
//												  
//												  <<endl
//												  <<"Selecciona: ";cin>>opcion;
//												  
//												  system("cls");
//												  switch (opcion){
//												  case 1:
//													  
//													  cout<<"Etiquetas Existentes: "<<endl;
//													  cout<<"De Libros: "<<endl;
//													  Etiquetas = sistema.etiquetas(etiquetasLibros);
//													  c=0;
//													  for(Tags& x : Etiquetas)
//														  cout<<++c<<" ) "<<x.VerNombre()<<endl;
//													  cout<<"De Alumnos: "<<endl;
//													  Etiquetas = sistema.etiquetas(TagsAlmunos);
//													  c=0;
//													  for(Tags& x : Etiquetas)
//														  cout<<++c<<" ) "<<x.VerNombre()<<endl;
//													  
//													  cout<<endl<<endl<<"Presiona para volver";
//													  cin.ignore();
//													  cin.get();
//													  system("cls");
//													  break;
//												  case 2:
//													  cout<<"Buscar Etiquetas...";
//													  cout<<endl<<endl<<"Presiona para volver";
//													  cin.ignore();
//													  cin.get();
//													  system("cls");
//													  break;
//													  
//												  case 3:
//													  cout<<"Eliminar Etiquetas...";
//													  cout<<endl<<endl<<"Presiona para volver";
//													  cin.ignore();
//													  cin.get();
//													  system("cls");
//													  break;
//													  
//												  case 4:
//													  cout<<"Agregar Etiquetas...";
//													  ///Carga en memoria N elementos
//													  //VectorTags= vacio
//													  //bibliotecario.Agregar<Tags>(VectorTags)
//													  //VectorTags=lleno
//													  ///Va al bin a cargarlo
//													  //sistema.Guardar<Tags>(VectorTags)
//													  cout<<endl<<endl<<"Presiona para volver";
//													  cin.ignore();
//													  cin.get();
//													  system("cls");
//													  break;
//													  
//												  case 5:
//													  ///volver
//													  break;
//													  
//												  default:
//													  break;
//												  }///Fin case, etiquetas
//										  }///Fin While etiquetas
//									  case 6:
//												//Volviendo
//												break;
//												
//												
//									  default:
//										  break;
//										  
//								  }///Case
//						  }
//				case 3:
//								while(opcion!=6){
//									cout<<"Gestion de Bibliotecarios"<<endl;
//									cout<<"1. Ver Bibliotecarios"<<endl
//										<<"2. Buscar Bibliotecarios"<<endl
//										<<"3. Eliminar Bibliotecarios"<<endl
//										<<"4. Agregar Bibliotecarios"<<endl
//										<<"5. Etiquetas"<<endl
//										<<"6. Volver"
//										
//										<<endl
//										<<"Selecciona: ";cin>>opcion;
//										
//										system("cls");
//										switch (opcion){
//										case 1:
//											vectorBibliotecario= sistema.VerContenido<Bibliotecario>(bibliotecarios,true);
//											cout<<"Bibliotecario: "<<endl;
//											for(Bibliotecario& x: vectorBibliotecario)
//												cout<<x.VerNombre()<<"   "<<x.VerDNI()<<"   "<<x.VerID()<<endl;
//											cout<<endl<<endl<<"------------------------------"<<endl;
//											
//											
//											cout<<endl<<endl<<"Presiona para volver";
//											cin.ignore();
//											cin.get();
//											system("cls");
//											break;
//										case 2:
//											cout<<"Buscar alumno"<<endl;  
//											cout<<endl<<endl<<"Presiona para volver";
//											cin.ignore();
//											cin.get();
//											system("cls");
//											
//											break;
//										case 3:
//											//  cout<<"ID a eliminar: ";cin>>idLibro;
//											
//											
//											/*if(it!= vectorLibros.end() ){
//											///Muestra 			| Salida
//											cout<<"Libro: "<<endl
//											<<"Nombre: "<<(*(it)).VerNombre()
//											<<endl 
//											<<"ID: "<<(*(it)).VerID()
//											<<endl;
//											
//											char borrar;
//											cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
//											if(borrar=='s'){
//											///Uso del metodo 	| Proceso
//											itBorrar = navega.Buscar(idLibro,vectorLibros);
//											admin.EliminarLibro(itBorrar,vectorLibros);
//											sistema.Guardar<Libro>(libros,vectorLibros);
//										}
//										}else{ cout<<endl<<"Codigo No existente";}
//											
//											*/
//											cout<<endl<<endl<<"Presiona para volver";
//											cin.ignore();
//											cin.get();
//											system("cls");
//											
//											break;
//										case 4:
//											cout<<"Bibliotecarios a agregar: ";cin>>cant;
//											admin.CargarNuevos<Bibliotecario>(cant,bibliotecarios);
//											
//											cout<<endl<<endl<<"Presiona para volver";
//											cin.ignore();
//											cin.get();
//											system("cls");
//											opcion = -1;
//											break;
//										case 5:
//											opcion=-1;
//											while(opcion!=5){
//												cout<<"Menu Etiquetas"<<endl;
//												cout<<"1. Ver Etiquetas"<<endl
//													<<"2. Buscar Etiquetas"<<endl
//													<<"3. Eliminar Etiquetas"<<endl
//													<<"4. Agregar Etiquetas"<<endl
//													<<"5. Volver"
//													
//													<<endl
//													<<"Selecciona: ";cin>>opcion;
//													
//													system("cls");
//													switch (opcion){
//													case 1:
//														
//														cout<<"Etiquetas Existentes: "<<endl;
//														cout<<"De Libros: "<<endl;
//														Etiquetas = sistema.etiquetas(etiquetasLibros);
//														c=0;
//														for(Tags& x : Etiquetas)
//															cout<<++c<<" ) "<<x.VerNombre()<<endl;
//														cout<<"De Alumnos: "<<endl;
//														Etiquetas = sistema.etiquetas(TagsAlmunos);
//														c=0;
//														for(Tags& x : Etiquetas)
//															cout<<++c<<" ) "<<x.VerNombre()<<endl;
//														
//														cout<<endl<<endl<<"Presiona para volver";
//														cin.ignore();
//														cin.get();
//														system("cls");
//														break;
//													case 2:
//														cout<<"Buscar Etiquetas...";
//														cout<<endl<<endl<<"Presiona para volver";
//														cin.ignore();
//														cin.get();
//														system("cls");
//														break;
//														
//													case 3:
//														cout<<"Eliminar Etiquetas...";
//														cout<<endl<<endl<<"Presiona para volver";
//														cin.ignore();
//														cin.get();
//														system("cls");
//														break;
//														
//													case 4:
//														cout<<"Agregar Etiquetas...";
//														///Carga en memoria N elementos
//														//VectorTags= vacio
//														//bibliotecario.Agregar<Tags>(VectorTags)
//														//VectorTags=lleno
//														///Va al bin a cargarlo
//														//sistema.Guardar<Tags>(VectorTags)
//														cout<<endl<<endl<<"Presiona para volver";
//														cin.ignore();
//														cin.get();
//														system("cls");
//														break;
//														
//													case 5:
//														///volver
//														break;
//														
//													default:
//														break;
//													}///Fin case, etiquetas
//											}///Fin While etiquetas
//										case 6:
//												  //Volviendo
//												  break;
//												  
//												  
//										default:
//											break;
//											
//										}///Case
//									
//								}
//				
//				default:
//						  break;
//						  
//				}//Case
//		}///While Principal
//	}//Fin funcion
		
		
//	void menuAlumno(){
//			cout<<"Sistema de Aluno"<<endl<<endl;
//			int opcion=-1;
//			while(opcion!=0){
//				
//				cout<<"Menu para Alumno"<<endl
//					<<"1. BuscarLibro()"<<endl
//					<<"2. VerLibros()"<<endl
//					<<"3. VerHistorial()"<<endl
//					<<"4. LibrosPrestadosActualmente()"<<endl
//					<<"0. Salir"
//					<<endl
//					<<"Selecciona: ";
//					cin>>opcion;
//					
//					//	cin.get();
//					system("cls");	
//					
//					switch (opcion){
//					case 1://Buscar Libro
//						///Buscar libro
//									///Terminal			| Entrada
//									cout<<"Buscar libro, indica ID: ";cin>>idLibro;
////									BuscarLibro =navega.Relacionados( palabraBuscada,vectorLibros);
//									for (auto &&i : BuscarLibro)
//									{
//										cout<<"Nombre Libro: " 	<<i.VerNombre()<<"  Id: "	<<i.VerID()<<endl<<i.VerDisponible()<<endl;
//									}
//									
//									
//									cout<<endl<<endl<<"Presiona para volver";
//									cin.ignore();
//									cin.get();
//									system("cls");
//									
//									break;
//////					case 2: // VerLibros
////					cout<<"Libros Disponibles: "<<endl;	
////									///Contenido Actual
////									for(Libro &x: vectorLibros)
////										cout
////										<<"Nombre Libro: " 	<<x.VerNombre()
////										<<"  Id: "	<<x.VerID()
////										<<endl; 
////									
////									
////									cout<<endl<<endl<<"Presiona para volver";
////									cin.ignore();
////									cin.get();
////									system("cls");
////									break;
//////					case 3:// Ver Historial 	
////						cout<<"Historial de Prestamos"<<endl;
//////						Ver_Historial(alumno.VerID(),vectorLibros,HistorialPrestamos);
////					break;
//					
//					}//Case
//			
//			
//				}///While Principal
//		
//		
//		
//		
//		}//Fin funcion
			
			
			
	
