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
	
	
	vector<Libro>::const_iterator it;
	vector<Libro>::const_iterator itBorrar;
	
	
	

	
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
	case 1:
		while(opcion!=5){
		cout<<"Menu Libros"<<endl;
		cout<<"1. Ver libros"<<endl
			<<"2. Buscar libros"<<endl
			<<"3. Eliminar libro"<<endl
			<<"4. Agregar Libro"<<endl
			<<"5. Volver"
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
		it = navega.Buscar(idLibro,vectorLibros);
		
		
		///Muestra 			| Salida
		cout<<"Libro: "<<endl
			<<"Nombre: "<<(*(it)).VerNombre()
			<<endl 
			<<"ID: "<<(*(it)).VerID()
			<<endl;
		
		cout<<endl<<endl<<"Preciona para volver";
		cin.ignore();
		cin.get();
		system("cls");
		
		break;
	case 3:
		cout<<"ID a eliminar: ";cin>>idLibro;
		
		
		///Buscar Libro		| Proceso
		it = navega.Buscar(idLibro,vectorLibros);
		
		if(it!= vectorLibros.end() ){
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
		sistema.Guardar(libros,vectorLibros);
		}
		}else{ cout<<endl<<"Codigo No existente";}
		
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
			admin.AgregarLibros(Nlibros,vectorLibros);	
			sistema.Guardar(libros,vectorLibros);
			vectorLibros = admin.VerLibros(libros);
			cout<<"Agregados Corectamente!"<<endl;
		}	
		cout<<endl<<endl<<"Preciona para volver";
		cin.ignore();
		cin.get();
		system("cls");
		
		break;
	case 5:
		//Volviendo
		break;
	default:
		break;
		
		}///Case
	}///While	
	
  }//Case
}///While


	
	return 0;
}

/*
	{	///Agregar libros 
	cout<<"Prueba registrar un nuevo libro!! ( 0 _ 0 )"<<endl;
	///Terminal			| Entrada
	
	cin.get();
	system("cls");
	
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
	
	}	
	cin.get();
	system("cls");
	
	{	
	///Buscar por nombre del libro
	
	///Simulacion de etiquetas existentes
	///Luego recuperar de .bin
	vector<int> etiquetas={1,2,3};
	string nombreBusqueda= "Poo";
	//vector<Libro> ResultadosBusqueda = admin.BuscarLibro(nombreBusqueda,etiquetas,);
	
	}
	
	
	
	
	*/
	
	
