#include "Tags.h"
#include "../system/system.h"
#include "../login/login.h"

using namespace std;

void Tags::AgregarNuevoTag(string NombreTag){
	Tag nuevoTag;
	nuevoTag.IdTag = ++CantidadTags;
	nuevoTag.NombreTag = NombreTag;
	
	nuevoTag.InicioBloque = UltimaDireccion;
	cout<<"Bloque Inicia en:"<<nuevoTag.InicioBloque<<endl;
	UltimaDireccion += TamBloque;
	cout<<"Bloque Finaliza en:"<<UltimaDireccion-1<<endl;
	///Asignar Bloque
	Bloque bloqueNuevo;
	bloqueNuevo.CantidadElementos=0;
	bloqueNuevo.SiguienteBloque=-1;
	cout<<endl<<"Tam asignado: "<<sizeof(bloqueNuevo)<<endl;
	///EscribirTagAlFinal(nuevoTag);
	///EscribirBloqueAlFinal(bloqueNuevo);
	
}

size_t Tags::AgregarNuevoBloque(){
	cout<<"Bloque Inicia en:"<<UltimaDireccion<<endl;
	UltimaDireccion += TamBloque;
	cout<<"Bloque Finaliza en:"<<UltimaDireccion-1<<endl;
	///Asignar Bloque
	Bloque bloqueNuevo;
	bloqueNuevo.CantidadElementos=0;
	bloqueNuevo.SiguienteBloque=-1;
	cout<<endl<<"Tam asignado: "<<sizeof(bloqueNuevo)<<endl;
	///EscribirBloqueAlFinal(bloqueNuevo);
	return UltimaDireccion;
}
	

bool Tags::AgregarNuevoElemento(size_t IdTag, size_t idLibro){
	Bloque aux = sistema->VerContenido(allTags,IdTag);
	size_t nuevoBloque;
	vector<size_t> resultado;
	if(aux.CantidadElementos != 0){
	///Caso bloque con elementos
	for(size_t i = 0; i < aux.CantidadElementos; ++i){
		resultado.push_back(aux.Elementos[i]);
	}
		resultado.push_back(idLibro);
	}
	if(aux.CantidadElementos == 0){
		resultado.push_back(idLibro);
	}
	
	if(aux.CantidadElementos == resultado.size()){///Bloque lleno
		nuevoBloque = AgregarNuevoBloque();
		AgregarNuevoElemento(nuevoBloque,idLibro);
	}
	
	///Ajustar para usar Guardar
	++aux.CantidadElementos;
	vector<Bloque> Bloques;
	Bloques.push_back(aux);
	sistema->Guardar<Bloque>(allTags,Bloques);
	
	return true;
}
vector<size_t> Tags::LeerTodosLosElementos(size_t IdTag){
	Bloque aux = sistema->VerContenido(allTags,IdTag);
	vector<size_t> resultado;
	bool parar = false;
	while(!parar){
	
		for(size_t i = 0; i < aux.CantidadElementos; ++i){
			resultado.push_back(aux.Elementos[i]);
		}
		if(aux.CantidadElementos == resultado.size()){
			if(aux.SiguienteBloque!= -1){
				///Tomar siguiente bloque
				aux = sistema->VerContenido(allTags,aux.SiguienteBloque);
			}
		}
		if(aux.SiguienteBloque== -1)
			parar = true;

	}
	
	return resultado;
}
