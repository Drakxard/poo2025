#include <iostream>
#include "Funcionalidades/preConfiguracion/preConfiguracion.h" // Solo una vez

// Importar Clases
#include "Funcionalidades/system/system.h"
#include "Funcionalidades/buscador/buscador.h"
#include "Funcionalidades/libro/libro.h"
#include "Funcionalidades/bibliotecario/bibliotecario.h"
#include "Funcionalidades/alumno/alumno.h"
#include "Funcionalidades/login/login.h" // Si vas a usar login
#include "Funcionalidades/Bloques/Bloques.h"

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
string palabra;

vector<Libro> resultadoLibros;
vector<Alumno> resultadoAlumnos;
vector<Alumno> resultadoBibliotecarios;
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
vector<Alumno> vectorAlumnos = sistema.VerContenido<Alumno>(alumnos, 1);
vector<Bibliotecario> vectorBibliotecario = sistema.VerContenido<Bibliotecario>(bibliotecarios, 1);
int idLibro, idAlumno, idBibliotecario;
int cant;	

///Iteradores para los metodos
vector<Libro>::const_iterator it;
vector<Libro>::const_iterator itBorrar;
int c; //ya apareci

vector<Tags> Etiquetas;
Tags auxTags;
vector<Tags> tagsActuales;


void menuBibliotecario();
void menuAlumno();
Bloques allTags;

int main(){
	
	/*-----------------Login------------------------
	//Saber los alumnos y bibliotecarios
	vectorAlumnos = sistema.VerContenido<Alumno>(alumnos,true);
	vectorBibliotecario= sistema.VerContenido<Bibliotecario>(bibliotecarios,true);
	
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
			menuBibliotecario();
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
	
	//Fin login, tenemos o un Bibliotecario o un Alumno
*/
	/* ----------------------- Intefaz --------------------
	///Para mostrar los libros antes mostramos sus Cabeceras
	
	/*string indexCabeceras="./Recursos/libros_index.txt";
	
	vector<Cabecera> resultado = sistema.CargarDesdeTxt(indexCabeceras);

	for(Cabecera& x: resultado)
		cout<<
		"Nombre libro: "<<x.nombre<<
		"      "<<
		"path: "<<x.path<<
		endl;
	
	*/
	
	
	/* ----------- Metodos relacionados a Libros --------------

	
	
	//VerLibrosExistentes
	cout<<"Libros Disponibles: "<<endl;
	vectorLibros = sistema.VerContenido<Libro>(libros,true);
	resultadoLibros = navega.Relacionados(palabra,vectorLibros);

	for(Libro& x: vectorLibros){
		cout
			<<"Nombre Libro: " 	<<x.VerNombre()
			<<"/ Id: "	<<x.VerID();
			if(x.EstadoDisponibilidad()==1){
				cout<<"/ Disponible"<<endl;
			}else{
				cout<<"/ No Disponible"
				<<endl;
			}
		}
	cout<<endl<<endl<<"------------------------------"<<endl;
	*/
	
	/* -------------------- Buscar libro palabra -----------------------
	cout<<"Buscar libro, ingrese palabra: ";
	getline(cin,palabra);
	cin.ignore();
	resultadoLibros = navega.Relacionados(palabra,vectorLibros);
	for(Libro &x: vectorLibros){
			cout
			<<"Nombre Libro: " 	<<x.VerNombre()
			<<"/ Id: "	<<x.VerID();
			if(x.EstadoDisponibilidad()==1){
				cout<<"/ Disponible"<<endl;
			}else{
				cout<<"/ No Disponible"
				<<endl;
			}
		} 
	*/
	
	
	
	
	/*----------------------- Eliminar Libros ---------------------								vectorLibros = sistema.VerContenido<Libro>(libros,true);
	cout<<"ID a eliminar: ";cin>>idLibro;
	
	char borrar;
	cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
	if(borrar=='s'){
	///Uso del metodo 	| Proceso
		sistema.Eliminar(idLibro, vectorLibros);
		sistema.Guardar<Libro>(libros,vectorLibros);
		
	}else{
			cout<<endl<<"Codigo No existente";
	}
	*/
	
/*------------Agregar Libros----------------
	cout<<"Libros a agregar: ";cin>>cant;
	admin.CargarNuevosLibros(cant,libros);
*/

// -----------^ Metodos relacionados a Libros ^ --------------
	
	
	
	/* --------------- Flujo de bloques ------------
	//Trabajar con bloques

	//Las etiquetas reservan bloques, al ser creados
	Tags auxTags;
	vector<Tags> tagsActuales;
	auxTags = allTags.AgregarNuevoTag();
	tagsActuales.push_back(auxTags);

	///Guardar tags
	sistema.Guardar<Tags>(allTags.VerPathEtiquetas(),tagsActuales);
	
	tagsActuales = sistema.VerContenido<Tags>(allTags.VerPathEtiquetas(),true);
	cout<<endl<<endl;
	for(Tags& x:tagsActuales)
		cout<<"Nombre Tag: "<<x.NombreTag<<" Inicia en: "<<x.InicioBloque<<
		"   < ------ >  "<<x.IdTag<<  endl;
	
	
	
	size_t IDtag, IDNuevo;
	cout<<"Ingresado IdTag: ";cin>>IDtag;
	cout<<"Id a agregar: ";cin>>IDNuevo;
	
	
	
	
	allTags.AgregarNuevoElemento(IDtag,IDNuevo);
	
	cout<<endl<<"Todos los id de ese bloque son: "<<endl;
	vector<size_t>resultado = allTags.LeerTodosLosElementos(IDtag);
	
	
*/
	

/* ----------- Metodos relacionados a Alumnos --------------

//--------------Ver Alumnos------------
vectorAlumnos = sistema.VerContenido<Alumno>(alumnos,true);
									
	cout<<"Alumnos: "<<endl;
	for(Alumno& x: vectorAlumnos)
		cout<<x.VerNombre()  <<"/   "<<x.VerDNI()  <<"/   "<<x.VerID()<<endl;
	
	cout<<endl<<endl<<"------------------------------"<<endl;

//--------------Agregar Alumnos -----------  
cout<<"Alumnos a agregar: ";cin>>cant;
admin.CargarNuevos<Alumno>(cant,alumnos);

//---------------Eliminar Alumno--------------
cout<<"ID a eliminar: ";cin>>idAlumno;
	char borrar;
	cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
	if(borrar=='s'){
	///Uso del metodo 	| Proceso
		sistema.Eliminar(idAlumno, vectorAlumnos);
		sistema.Guardar<Alumno>(alumnos,vectorAlumnos);
		
	}else{
			cout<<endl<<"Codigo de identificación inexistente";
	}

//---------------Buscar Alummno--------------
cout<<"Buscar Alumno, ingrese el nombre: ";
getline(cin,palabra);
cin.ignore();
	
	resultadoAlumnos = navega.Relacionados(palabra,vectorAlumnos);
	for(Alumno &x: vectorAlumnos){
			cout<<"Nombre Alumno: " <<x.VerNombre()
			<<" / Id: "	<<x.VerID()
			<<" / DNI: "<<x.VerDNI();
			if(x.VerEstadoDeSancion()==1){
				cout<<"/ Sancionado"<<endl;
			}else{
				cout<<"/ No Sancionado"
				<<endl;
			}
		} 
	*/


/* -----------^ Metodos relacionados a Alumnos ^ --------------



/* ----------- Metodos relacionados a Bibliotecarios  --------------

//---------------Ver Bibliotecarios--------------

vectorBibliotecario= sistema.VerContenido<Bibliotecario>(bibliotecarios,true);
cout<<"Bibliotecario: "<<endl;
for(Bibliotecario& x: vectorBibliotecario)
	cout<<x.VerNombre()<<" / "<<x.VerDNI()<<" / "<<x.VerID()<<endl;
cout<<endl<<endl<<"------------------------------"<<endl;

//---------------Buscar Bibliotecarios"--------------
cout<<"Buscar Bibliotecario, ingrese el nombre: ";
getline(cin,palabra);
cin.ignore();
	
resultadoBibliotecarios = navega.Relacionados(palabra,vectorBibliotecario);
for(Bibliotecario &x: vectorBibliotecario){
		cout<<"Nombre Bibliotecario: " <<x.VerNombre()
		<<" / Id: "	<<x.VerID()
		<<" / DNI: "<<x.VerDNI();
} 

//--------------Agregar Bibliotecarios -----------
cout<<"Bibliotecarios a agregar: ";cin>>cant;
admin.CargarNuevos<Bibliotecario>(cant,bibliotecarios);


//---------------Eliminar Bibliotecarios"--------------
cout<<"ID a eliminar: ";cin>>idBibliotecario;
char borrar;
cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
if(borrar=='s'){
///Uso del metodo 	| Proceso
	sistema.Eliminar(idBibliotecario, vectorBibliotecario);
	sistema.Guardar<Alumno>(bibliotecarios,vectorBibliotecario);
	
}else{
		cout<<endl<<"Codigo de identificación inexistente";
}

 -----------^ Metodos relacionados a Bibliotecarios ^ --------------
*/

// -----------^ Metodos relacionados a Bibliotecarios ^ --------------
	return 0;
}
	
	
void menuBibliotecario(){
	int opcion=-1;
	while(opcion!=0){
		cout<<"Menu de gestion"<<endl;
		cout<<"1. Libros"<<endl
			<<"2. Alumnos"<<endl
			<<"3. Bibliotecarios"<<endl
			<<"0. Salir"
			<<endl
			<<"Selecciona: ";cin>>opcion;
			
			//	cin.get();
			system("cls");	
			
			switch (opcion){
				///While Menu Libros
			case 2:
						while(opcion!=6){
							cout<<"Gestion de Alumnos"<<endl;
								<<"2. Buscar Alumnos"<<endl
								<<"3. Eliminar Alumnos"<<endl
								<<"6. Volver"
								
								<<endl
								<<"Selecciona: ";cin>>opcion;
								
								system("cls");
								switch (opcion){
								case 1:
									
								case 2:
								cout<<"Buscar alumno"<<e/*ndl;  
									cout<<endl<<endl<<"Presiona para volver";
									cin.ignore();
									cin.get();
									system("cls");
									
									break;
					*/			case 3:
								//  cout<<"ID a eliminar;/*cin>>idLibro;
									
									
									/*if(it!= vectorLibros.e() ){
									///Muestra 			| Salida
							cout<<"Libro: "<<endl
									<<"Nombre: "<<(*(it)).VerNombre()
									<<endl 
									<<"ID: "<<(*(it)).VerID()
									<<endl;
									
									char borrar;
									cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
									if(borrar=='s'){
									///Uso del metodo 	| Proso
									itBorrar = navega.Buscar(idLibro,vectorLibros);
									admin.EliminarLibro(itBorrar,vectorLibros);
									sistema.Guardar<Libro>(libros,vectorLibros);
									}
									}else{ cout<<endl<<"Codigo No existente";}
									
									
									cout<<endl<ndl<<"Presiona para volver";
									cin.ignore();
									cin.get();
									system("cls");
									
									break;
									*/
									case 5:
										opcion=-1;
										while(opcion!=5){
												}///Fin case, etiquetas
										}///Fin While etiquetas
									case 6:
											//Volviendo
											break;
											
											
									default:
										break;
										
								}///Case
						}
			case 3:
							while(opcion!=6){
								cout<<"Gestion de Bibliotecarios"<<endl;
									case 3:
										//  cout<<"ID a eliminar: ";cin>>idLibro;
										
										
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
										cout<<endl<<endl<<"Presiona para volver";
										cin.ignore();
										cin.get();
										system("cls");

}//Fin funcion
		