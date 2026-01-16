#include <iostream>
#include <cstring>
#include <iomanip>
#include "Funcionalidades/system/system.h"
#include "Funcionalidades/buscador/buscador.h"
#include "Funcionalidades/bibliotecario/bibliotecario.h"
#include "Funcionalidades/login/login.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
//Importar Clases propias
#include "Funcionalidades/libro/libro.h"


int main(){
	///Login
	
///---------------------------------

cout<<"Sistema de gestion Bibliotecario!!!"<<endl<<endl;

int dni;
cout<<"Ingrese su Documento de Identidad, por favor"<<endl;
cin>>dni;
System sistema;
string AlumnosPath ,BibliotecarioPath;
vector<Bibliotecario> vectorBibliotecario = sistema.VerContenido<Bibliotecario>(BibliotecarioPath,true);
int PosBibliotecario = BuscarDniEnBibliotecarios(dni, vectorBibliotecario);
Alumno alumn;
if(PosBibliotecario != -1){
	Bibliotecario biblio = CrearObjetoCorrespondienteBibliotecario(PosBibliotecario, vectorBibliotecario);
	cout<<"¿Qué Quieres Hacer "<<biblio.VerNombre()<<" ?"<<endl;

}else{
	vector<Alumno> vectorAlumno = sistema.VerContenido<Alumno>(AlumnosPath,true);
	int PosAlumno = BuscarDniEnAlumnos(dni,vectorAlumno);
	if(PosAlumno!= -1){
		alumn = CrearObjetoCorrespondienteAlumno(PosAlumno, vectorAlumno); 
			cout<<"¿Qué Quieres Hacer "<<alumn.VerNombre()<<" ?"<<endl;
	}else{
		string nombre;
		cout<<"Ingresa tu nombre: ";cin>>nombre;
		int id = sistema.VerUltimo<Alumno>(AlumnosPath);
		alumn = Alumno(id, nombre.c_str(), dni);
	}
}


//Fin login, tenemos o un Bibliotecario o un Alumno


	return 0;
}


	
	
