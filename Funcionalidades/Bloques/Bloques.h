#ifndef TAGS_H
#define TAGS_H
#include <iostream>
#include <cstring>
#include <vector>
#include "../persistencia/Persistencia.h"
using namespace std;
struct Tags{
	size_t IdTag;
	size_t VerID(){return IdTag;}
	char NombreTag[50];
	size_t InicioBloque;
};

struct Bloque{
	int CantidadElementos=0;
	int SiguienteBloque=0;
	int Elementos[1022];
};
class System;

class Bloques {
	System *sistema;
	size_t TamBloque= sizeof(Bloque);
	size_t UltimaDireccion = 0;
	size_t CantidadTags=0;
	string allTags_data= "./Recursos/Binarios/Tags/tags_data.bin";
	string allTags= "./Recursos/Binarios/Tags/tags.bin";
	Persistencia actual;
	bool modificacion = false;
public:
	Bloques();
	~Bloques();
	Tags AgregarNuevoTag();
	size_t AgregarNuevoBloque();
	vector<size_t>LeerTodosLosElementos(size_t IdTag);
	bool AgregarNuevoElemento(size_t IdTag, size_t idLibro);
	string VerPathEtiquetas(){return allTags;}
	size_t CantTags(){return CantidadTags;}

};

#endif

