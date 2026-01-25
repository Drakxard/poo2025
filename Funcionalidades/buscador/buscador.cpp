
#include "../bloques/bloques.h"
#include "../system/system.h"
#include "../Tags/Tags.h"


size_t Bloques::AgregarNuevoBloque(){
	// Tu código original...
	// Nota: Asegúrate de que UltimaDireccion esté sincronizada con la persistencia
	UltimaDireccion += TamBloque;
	
	Bloque bloqueNuevo;
	bloqueNuevo.CantidadElementos=0;
	bloqueNuevo.SiguienteBloque=-1; // Ojo: SiguienteBloque es uint32_t (unsigned), -1 será 4294967295
	return UltimaDireccion;
}


bool Bloques::AgregarNuevoElemento(size_t IdTag, size_t idLibro){
	// Ahora 'sistema' y 'etiquetas' son válidos y apuntan a lo creado en main
	Bloque aux = sistema->VerContenido(etiquetas->VerPathDataEtiquetas(),IdTag);
	
	aux.Elementos[aux.CantidadElementos]=idLibro;
	++aux.CantidadElementos;
	cout<<endl<<"Nueva cantidad de elementos: "<<aux.CantidadElementos;
	
	sistema->Guardar(etiquetas->VerPathDataEtiquetas(),aux,IdTag);
	
	return true;
}

vector<size_t> Bloques::LeerTodosLosElementos(size_t IdTag){
	// Tu código original...
	Bloque aux = sistema->VerContenido(etiquetas->VerPathDataEtiquetas(),IdTag);
	vector<size_t> resultado;
	bool parar = false;
	while(!parar){
		
		for(size_t i = 0; i < aux.CantidadElementos; ++i){
			resultado.push_back(aux.Elementos[i]);
			cout<<"["<<i<<"] "<<aux.Elementos[i]<<endl;
		}
		
		if(aux.SiguienteBloque != 0 && aux.SiguienteBloque != -1){ // Ajuste lógico para unsigned
			aux = sistema->VerContenido(etiquetas->VerPathDataEtiquetas(),aux.SiguienteBloque);
		}else{parar = true;}
	}
	return resultado;
}
