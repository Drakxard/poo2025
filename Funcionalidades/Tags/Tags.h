#ifndef TAGS_H
#define TAGS_H
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Tag{
	size_t IdTag;
	string NombreTag;
	size_t InicioBloque;
};

struct Bloque{
	size_t CantidadElementos;
	size_t SiguienteBloque;
	size_t Elementos[1022];
};
class System;
class Tags {
	System *sistema;
	size_t TamBloque= 4096;
	size_t UltimaDireccion = 0;
	size_t CantidadTags=0;
	string allTags= "Recursos/Binarios/Tags/tags_data.bin";
	
public:
	Tags(){};
	void AgregarNuevoTag(string NombreTag);
	size_t AgregarNuevoBloque();
	vector<size_t>LeerTodosLosElementos(size_t IdTag);
	///Usar Como en AgregarNuevoElemento, VerContenido Actualizado
	/// o Sobrecargado para bloques
	bool AgregarNuevoElemento(size_t IdTag, size_t idLibro);
	///VerContenido<Bloque>, me da todo el bloque
	///Pero deberia ser el bloque correcto, 
	///por ende no todo el archivo sino basado en id, asi seek y Leer
	///Luego de tener el bloque ponerlo en vector, 
	///Push_back, x1 elemento
	///volver una posicion
	///Y escribir el bloque actualizado
	///Return true al final, llego bien
	
	size_t CantTags(){return CantidadTags;}
};

#endif

