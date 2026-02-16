#include "Historial.h"
#include <cstdlib>
//#include <vector>
#include "../system/system.h"
using namespace std;

vector<Registro>Historial:: Mostrar_Historial(size_t id_usuario, string nombreArchivo){
	ifstream archi(nombreArchivo,ios::binary);
	if(!archi.is_open()){
		throw runtime_error("No se pudo abrir el archivo "+nombreArchivo);
	}
	
	vector<Registro>resultado;
	Registro a;
	while(archi.read(reinterpret_cast<char*>(&a), sizeof(Registro)))
	{
		if(a.id_usuario == id_usuario)
		{
			resultado.push_back(a);
		}
	}
	
	archi.close();
	return resultado;
}
vector<Registro>Historial:: Mostrar_Historial_libro(size_t id_libro, string nombreArchivo){
	ifstream archi(nombreArchivo,ios::binary);
	if(!archi.is_open()){
		throw runtime_error("No se pudo abrir el archivo "+nombreArchivo);
	}
	
	vector<Registro>resultado;
	Registro a;
	while(archi.read(reinterpret_cast<char*>(&a), sizeof(Registro)))
	{
		if(a.id_libro == id_libro)
		{
			resultado.push_back(a);
		}
	}
	
	archi.close();
	return resultado;
}
void Historial::Cargar_Historial(size_t idLibro, size_t idAlumno,string nom_usu,string nom_lib,int dia,int mes,int anio, string nombreArchivo ){
	Registro a;
	a.id_usuario=idAlumno; a.id_libro=idLibro;
	strncpy(a.nombre_usuario,nom_usu.c_str(),48);
	a.nombre_usuario[48] = '\0';
	strncpy(a.nombre_libro,nom_lib.c_str(),49);
	a.nombre_libro[49] = '\0';
	a.dia=dia;a.mes=mes;a.anio=anio;
	
	vector<Registro>aux;
	aux.push_back(a);
	System sistema;
	sistema.Guardar(nombreArchivo,aux,true);
}
 
