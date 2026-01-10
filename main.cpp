#include <iostream>
#include <cstring>
#include <iomanip>
#include "Funcionalidades/system/system.h"
#include "Funcionalidades/buscador/buscador.h"
#include <string>
using namespace std;
//Importar Clases propias
#include "Funcionalidades/libro/libro.h"
#include "Funcionalidades/bibliotecario/bibliotecario.h"


int main(){
	///Login
	string NombreUsuario= "Invitado";
	int codigo = 1;
	/// Variables
	const char *nom = NombreUsuario.c_str();
	///Crear entedidad del sistema de gestion
	Bibliotecario admin(codigo,nom); 
	///Clase encargada de los metodos de bajo nivel
	System sistema; 
	vector<string>Etiquetas;
	///Clase encargada de las busquedas
	Buscador navega(Etiquetas);
	
	///Nombre del Binario de test
	string libros = "Recursos/binarios/libros.bin";
	vector<Libro> vectorLibros = sistema.VerContenido(libros, 1);
	int idLibro;
	int Nlibros;	
	
	///Saludo y estado actual
	cout<<"Buenas "<< admin.VerNombre()<< " tu ID es: "<< admin.VerID()<<endl;
	cout<<endl<<endl<<"Preciona para continuar";
	cin.get();
	system("cls");
	
	
	
	
	
	
	{	///Agregar libros 
		cout<<"Prueba registrar un nuevo libro!! ( 0 _ 0 )"<<endl;
		///Terminal			| Entrada
		
		cin.get();
		system("cls");
		cout<<"LIbros a agregar: ";cin>>Nlibros;
		///Uso del metodo	| Proceso
		if(!Nlibros==0){
			admin.AgregarLibros(Nlibros,vectorLibros);	
			sistema.Guardar(libros,vectorLibros);
			vectorLibros = admin.VerLibros(libros);
			
			system("cls");
			///Muestra			| Salida
			for(Libro &x: vectorLibros)
				cout
				<<"Nombre Libro: " 	<<x.VerNombre()
				<<"  Id: "	<<x.VerID()
				<<endl; 
			cin.ignore();
		}
	}
	{	///Borrar
		///Terminal  		| Entrada
		cin.ignore();
		cin.get();
		system("cls");
		cout<<"ID a eliminar: ";cin>>idLibro;
		
		
		///Uso del metodo 	| Proceso
		vector<Libro>::const_iterator itBorrar = navega.Buscar(idLibro,vectorLibros);
		//<admin.EliminarLibro(itBorrar,vectorLibros);
		//admin.GuardarLibros(libros,vectorLibros);
		
		
		///Muestra			| Salida
		for(Libro &x: vectorLibros)
			cout
			<<"Nombre Libro: " 	<<x.VerNombre()
			<<"  Id: "	<<x.VerID()
			<<endl; 
	}	
		cin.get();
		system("cls");
		
		{	///Buscar libro
			///Terminal			| Entrada
			cout<<"Buscar libro, indica ID: ";cin>>idLibro;
			
			///Buscar Libro		| Proceso
			vector<Libro>::const_iterator it = navega.Buscar(idLibro,vectorLibros);
			
			
			///Muestra 			| Salida
			cout<<"Libro: "<<endl
				<<"Nombre: "<<(*(it)).VerNombre()
				<<endl 
				<<"ID: "<<(*(it)).VerID()
				<<endl;
			
			///Buscar por nombre del libro
			
			///Simulacion de etiquetas existentes
			///Luego recuperar de .bin
			vector<int> etiquetas={1,2,3};
			string nombreBusqueda= "Poo";
			//vector<Libro> ResultadosBusqueda = admin.BuscarLibro(nombreBusqueda,etiquetas,);
			
		}
		
	


	
	cout<<"Sistema de gestion Bibliotecario!!!"<<endl<<endl;
	int opcion=-1;
	while(opcion!=0){
	
	cout<<"Menu de gestion"<<endl;
	cout<<"1. Ver libros"<<endl
	<<"2. Ver Usuarios"<<endl
	<<"3. Ver Bibliotecarios"<<endl
	<<"0. Salir"
	<<endl
	<<"Selecciona: ";cin>>opcion;
	
//	cin.get();
	system("cls");	
	
	switch (opcion){
	case 1:
		while(opcion!=0){
		cout<<"Viendo libros...";
		cout<<"Libros Disponibles: "<<endl;
		
		///Contenido Actual
		for(Libro &x: vectorLibros)
			cout
			<<"Nombre Libro: " 	<<x.VerNombre()
			<<"  Id: "	<<x.VerID()
			<<endl; 
		
		
		cout<<"Preciona 0 para volver";cin>>opcion;
		system("cls");
		}
		break;
	case 2:
		cout<<"Viendo usuarios...";
		break;
	case 3:
		cout<<"Viendo bibliotecarios...";
		break;
	case 0:
		cout<<"Saliendo...";
		break;
	default:
		break;
		
	}
	opcion=-1;
	}
	
	return 0;
}

