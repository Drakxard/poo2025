#ifndef BLOQUES_H
#define BLOQUES_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;



struct Bloque{
   
	uint32_t CantidadElementos=0;
	uint32_t SiguienteBloque=0;
	uint32_t Elementos[1022];
};
class System;
class Tags;
class Bloques{
	System *sistema;
	size_t TamBloque= sizeof(Bloque);
	size_t UltimaDireccion = 0;
	size_t CantidadTags=0;
	Tags *etiquetas;
public:
	Bloques(System* sistema, Tags* etiquetas){
		this->sistema=sistema;
		this->etiquetas=etiquetas;
	}
	size_t AgregarNuevoBloque();
	bool AgregarNuevoElemento(size_t IdTag, size_t idLibro);
    vector<size_t> LeerTodosLosElementos(size_t IdTag);
};

#endif
