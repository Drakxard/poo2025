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
	
	vector<string>listaTags;
	///Clase encargada de las busquedas
	Buscador navega(listaTags);
	
	///Nombre del Binario de test
	string libros = "Recursos/binarios/libros.bin";
	string usuarios = "Recursos/binarios/usuarios.bin";
	string bibliotecarios = "Recursos/binarios/bibliotecarios.bin";

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
	int c;
	
	vector<Libro> Etiquetas;
	vector<Alumno>EtiquetasAlumnos;
	string pathLibros = "Recursos/binarios/Tags/Libros.bin";
	string pathAlumnos= "Recursos/binarios/Tags/Alumnos.bin";
	
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
				Etiquetas = sistema.etiquetas<Libro>(pathLibros);
				c=0;
				for(Libro& x : Etiquetas)
					cout<<++c<<" ) "<<x.VerNombre()<<endl;
				cout<<"De Alumnos: "<<endl;
				EtiquetasAlumnos = sistema.etiquetas<Alumno>(pathAlumnos);
				c=0;
				for(Alumno& x : EtiquetasAlumnos)
					cout<<++c<<" ) "<<x.VerNombre()<<endl;
				
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
	}///While Menu Libros
		//Casos Usuarios, Bibliotecarios, ...
		default:
		break;
			  
		}//Case
}///While Principal


	
	return 0;
}

/*

	///Buscar por nombre del libro
	
	///Simulacion de etiquetas existentes
	///Luego recuperar de .bin
	vector<int> etiquetas={1,2,3};
	string nombreBusqueda= "Poo";
	//vector<Libro> ResultadosBusqueda = 	admin.BuscarLibro(nombreBusqueda,etiquetas,);
	
	}
	
	
	
	
	*/
	
	
