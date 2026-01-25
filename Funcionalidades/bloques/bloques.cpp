#include "bloques.h"
#include "../system/system.h"
#include "../Tags/Tags.h"
size_t Bloques::AgregarNuevoBloque(){
	UltimaDireccion += TamBloque;

	Bloque bloqueNuevo;
	bloqueNuevo.CantidadElementos=0;
	bloqueNuevo.SiguienteBloque=-1;
	return UltimaDireccion;
}
	

bool Bloques::AgregarNuevoElemento(size_t IdTag, size_t idLibro){
	Bloque aux = sistema->VerContenido(etiquetas->VerPathDataEtiquetas(),IdTag);
	

	aux.Elementos[aux.CantidadElementos]=idLibro;
	++aux.CantidadElementos;
	cout<<endl<<"Nueva cantidad de elementos: "<<aux.CantidadElementos;
	
	sistema->Guardar(etiquetas->VerPathDataEtiquetas(),aux,IdTag);
	
	return true;
}
vector<size_t> Bloques::LeerTodosLosElementos(size_t IdTag){
	Bloque aux = sistema->VerContenido(etiquetas->VerPathDataEtiquetas(),IdTag);
	vector<size_t> resultado;
	bool parar = false;
	while(!parar){
	
		for(size_t i = 0; i < aux.CantidadElementos; ++i){
			resultado.push_back(aux.Elementos[i]);
			cout<<"["<<i<<"] "<<aux.Elementos[i]<<endl;
		}
		
		if(aux.SiguienteBloque!= 0){
			aux = sistema->VerContenido(etiquetas->VerPathDataEtiquetas(),aux.SiguienteBloque);
		}else{parar = true;}
	}
	return resultado;
}
