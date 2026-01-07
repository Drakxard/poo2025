#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
//Importar Clases propias
#include "Funcionalidades/libro/libro.h"
#include "Funcionalidades/bibliotecario/bibliotecario.h"


int main(){

	///Login
	string NombreUsuario;
	int codigo = 1;
	
	cout<<"Sistema de gesti�n Bibliotecario!!!"<<endl<<endl;
	
	cout<<"Nombre: "<<NombreUsuario;
	/// Variables
	char *nom = NombreUsuario.c_str();
	Bibliotecario admin(nom,codigo); 
	string libros = "libros.bin";
	vector<Libro> vectorLibros = admin.VerLibros(libros, 1);
	int idLibro;
	int Nlibros;	
	
	///Saludo y estado actual
	cout<<"Buenas "<< admin.VerNombre()<< " ID: "<< admin.VerID()<<endl;
	cin.get();
	system("cls");
	
	cout<<"Libros Disponibles: "<<endl;
	
	///Contenido Actual
	for(Libro &x: vectorLibros)
		cout
		<<"Nombre Libro: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 
	

		
		
	
{	///Agregar libros 
	cout<<"Prueba registrar un nuevo libro!! ( 0 _ 0 )"<<endl;
	///Terminal			| Entrada

	cin.get();
	system("cls");
	cout<<"LIbros a agregar: ";cin>>Nlibros;
	///Uso del metodo	| Proceso
	if(!Nlibros==0){
		admin.AgregarLibros(Nlibros,vectorLibros);	
		admin.GuardarLibros(libros,vectorLibros);
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
    
{	///Buscar libro
	///Terminal			| Entrada
	cin.get();
	system("cls");
	cout<<"Buscar libro, indica ID: ";cin>>idLibro;
	
	///Buscar Libro		| Proceso
	vector<Libro>::const_iterator it = admin.BuscarLibro(idLibro,vectorLibros);
	
	
	///Muestra 			| Salida
	cout<<"Libro: "<<endl
		<<"Nombre: "<<(*(it)).VerNombre()
		<<endl 
		<<"ID: "<<(*(it)).VerID()
		<<endl;
	
	///falta que busque por nombre del libro
}	
	
	
{	///Borrar
	///Terminal  		| Entrada
	cin.ignore();
	cin.get();
	system("cls");
	cout<<"ID a eliminar: ";cin>>idLibro;
	
	
	///Uso del metodo 	| Proceso
	vector<Libro>::const_iterator itBorrar = admin.BuscarLibro(idLibro,vectorLibros);
	admin.EliminarLibro(itBorrar,vectorLibros);
	admin.GuardarLibros(libros,vectorLibros);

	
	///Muestra			| Salida
	for(Libro &x: vectorLibros)
		cout
		<<"Nombre Libro: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 
}	
	return 0;
}
	
