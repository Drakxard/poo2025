#include "Tags.h"
#include "../system/system.h"
#include "../login/login.h"
#include "../bloques/bloques.h"


#include <vector>
#include <cstring>
using namespace std;

Tags::Tags(){
	UltimaDireccion= actual.VerUltimaDireccion();
	CantidadTags = actual.VerCantidadTags();
}

Tags::~Tags(){
	actual.AsignarUltimaDireccion(UltimaDireccion);
	actual.AsignarCantidadTags(CantidadTags);
}


TagUnitario Tags::AgregarNuevoTag(){
	string nombreTag;
	cout<<"Nombre para el nuevo tag: ";
	getline(cin,nombreTag);
	
	
	TagUnitario nuevoTag;
	nuevoTag.IdTag = CantidadTags;
	++CantidadTags;

	
	strncpy(nuevoTag.NombreTag, nombreTag.c_str(), 49);
	nuevoTag.NombreTag[49] = '\0';
	nuevoTag.InicioBloque = UltimaDireccion;
	cout<<"Bloque Inicia en:"<<nuevoTag.InicioBloque<<endl;
	UltimaDireccion += TamBloque;
	cout<<"Bloque Finaliza en:"<<UltimaDireccion-1<<endl;
	///Asignar Bloque
	Bloque bloqueNuevo;
	bloqueNuevo.CantidadElementos=0;
	bloqueNuevo.SiguienteBloque=0;
	cout<<endl<<"Tam asignado: "<<sizeof(bloqueNuevo)<<endl;
	sistema->Guardar(allTags_data,bloqueNuevo,nuevoTag.IdTag);
	return nuevoTag;
	
	
}


