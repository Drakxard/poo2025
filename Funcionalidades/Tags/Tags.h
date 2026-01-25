#ifndef TAGS_H
#define TAGS_H
#include <iostream>
#include <cstring>
#include <vector>
#include "../persistencia/Persistencia.h"
using namespace std;
class Bloques;
struct TagUnitario{
	size_t IdTag;
	char NombreTag[50];
	size_t InicioBloque;
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

	string VerPathEtiquetas(){return allTags;}
	string VerPathDataEtiquetas(){return allTags_data;}
	
	size_t CantTags(){return CantidadTags;}
};
#endif
