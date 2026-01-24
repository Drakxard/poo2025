#ifndef TAGS_H
#define TAGS_H
#include <iostream>
#include <cstring>
#include <vector>
#include "../persistencia/Persistencia.h"
using namespace std;
struct TagUnitario{
	size_t IdTag;
	string NombreTag;
	size_t InicioBloque;
};

struct Bloque{
	uint32_t CantidadElementos=0;
	uint32_t SiguienteBloque=0;
	uint32_t Elementos[1022];
};
class System;
class Tags {
	System *sistema;
	size_t TamBloque= 4096;
	size_t UltimaDireccion = 0;
	size_t CantidadTags=0;
	string allTags_data= "./Recursos/Binarios/Tags/tags_data.bin";
	string allTags= "./Recursos/Binarios/Tags/tags.bin";
	Persistencia actual;
	
public:
	Tags();
	~Tags();
	TagUnitario AgregarNuevoTag();
	size_t AgregarNuevoBloque();
	vector<size_t>LeerTodosLosElementos(size_t IdTag);
	bool AgregarNuevoElemento(size_t IdTag, size_t idLibro);
	string VerPathEtiquetas(){return allTags;}
	size_t CantTags(){return CantidadTags;}

};

#endif

