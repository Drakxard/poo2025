#include <iostream>
#include <cstring>
#include <iomanip>
#include "Funcionalidades/system/system.h"
#include "Funcionalidades/buscador/buscador.h"
#include <string>
using namespace std;
//Importar Clases propias
#include "Funcionalidades/libro/libro.h"



int main(){
	///Login
	
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
		
	
	vector<Libro> vectorLibros = sistema.VerContenido<Libro>(libros, 1);
	int idLibro;
	int Nlibros;	
	
		///Iteradores para los metodos
	vector<Libro>::const_iterator it;
	vector<Libro>::const_iterator itBorrar;
	int c;


///---------------------------------
	
	cout<<"Sistema de gestion Bibliotecario!!!"<<endl<<endl;

int dni;
cout<<"Ingrese su Documento de Identidad, por favor"<<endl;
cin>>dni;


vector<Bibliotecarios> vectorBibliotecarios = sistema.VerContenido<Bibliotecario>(bibliotecarios,true);
int PosBibliotecario = BuscarDniEnBibliotecarios(dni, vectorBibliotecarios);
Bibliotecario biblio;
Alumno alumn;
if(PosBibliotecario != -1){
	biblio = ObjetoCorrespondienteBibliotecario(PosBibliotecario,biblioterios );
	cout<<"¿Qué Quieres Hacer "<<Biblio.VerNombre()<<" ?"<<endl;
	MenuBibliotecario();

}else{
	vector<Alumno> vectorAlumno = sistema.VerContenido<Alumno>(alumnos,true);
	int PosAlumno = BuscarDniEnAlumnos(dni,vectorAlumno);
	if(PosAlumno!= -1){
		alumn = ObjetoCorrespondienteAlumno(PosAlumno, alumnos); 
			cout<<"¿Qué Quieres Hacer "<<Alumn.VerNombre()<<" ?"<<endl;
			MenuAlumno();
	}else{
		string nombre;
		cout<<"Ingresa tu nombre: ";cin>>nombre;
		int id = sistema.VerUltimo<Alumno>(alumnos);
		alumn = Alumno(id,nombre);
	}
}


//Fin login, tenemos o un Bibliotecario o un Alumno


	return 0;
}


	
	