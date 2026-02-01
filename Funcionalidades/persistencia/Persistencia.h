#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include <iostream>

using namespace std;
class System;
class Persistencia {
	///Para saber siguiente bloque a crear
	size_t UltimaDireccion=0;
	///Saber Cuantos Tags hay
	size_t CantidadTags=0;
public:
	Persistencia();
	~Persistencia();
	
	void CargarDatos();
	size_t VerUltimaDireccion(){return UltimaDireccion;};
	size_t VerCantidadTags(){return CantidadTags;};
	void AsignarUltimaDireccion(size_t nueva){UltimaDireccion= nueva;};
	void AsignarCantidadTags(size_t nueva){CantidadTags=nueva;};
	
};

#endif

