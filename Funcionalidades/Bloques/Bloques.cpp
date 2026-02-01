#include "Bloques.h"
#include "../system/system.h"
#include "../login/login.h"


#include <vector>
#include <cstring>
using namespace std;

Bloques::Bloques(){
	UltimaDireccion= actual.VerUltimaDireccion();
	CantidadTags = actual.VerCantidadTags();
	cout<<"Construido con: "<<endl<<
		"UltimaDireccion: "<<UltimaDireccion<<endl<<
		"CantidadTags: "<<CantidadTags;
}

Bloques::~Bloques(){
	actual.AsignarUltimaDireccion(UltimaDireccion);
	actual.AsignarCantidadTags(CantidadTags);
}


Tags Bloques::AgregarNuevoTag(){
	string nombreTag;
	cin.ignore();
	cout<<"Nombre para el nuevo tag: ";
	getline(cin,nombreTag);
	
	
	Tags nuevoTag;
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

size_t Bloques::AgregarNuevoBloque(){
	UltimaDireccion += TamBloque;

	Bloque bloqueNuevo;
	bloqueNuevo.CantidadElementos=0;
	bloqueNuevo.SiguienteBloque=-1;
	return UltimaDireccion;
}
	

bool Bloques::AgregarNuevoElemento(size_t IdTag, size_t idLibro){
	Bloque aux = sistema->VerContenido(allTags_data,IdTag);
	

	aux.Elementos[aux.CantidadElementos]=idLibro;
	++aux.CantidadElementos;
	cout<<endl<<"Nueva cantidad de elementos: "<<aux.CantidadElementos;
	
	sistema->Guardar(allTags_data,aux,IdTag);
	
	return true;
}
vector<size_t> Bloques::LeerTodosLosElementos(size_t IdTag){
	Bloque aux = sistema->VerContenido(allTags_data,IdTag);
	vector<size_t> resultado;
	bool parar = false;
	while(!parar){
	
		for(size_t i = 0; i < aux.CantidadElementos; ++i){
			resultado.push_back(aux.Elementos[i]);
			cout<<"["<<i<<"] "<<aux.Elementos[i]<<endl;
		}
		
		if(aux.SiguienteBloque!= 0){
			aux = sistema->VerContenido(allTags_data,aux.SiguienteBloque);
		}else{parar = true;}
	}
	return resultado;
}
