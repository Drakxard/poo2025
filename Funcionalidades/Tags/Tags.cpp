#include "Tags.h"

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

//bool AgregarNuevoElemento(int IdTag, int idLibro);
//vector<int>LeerTodosLosElementos(int IdTag);
