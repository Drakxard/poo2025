#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../Bloques/Bloques.h"

using namespace std;

//template<typename T>
class System;
class Buscador{
	System *sistema;
	Bloques diccionario;
public:
	Buscador(){}
	vector<size_t> Buscar(string nombreBuscado);
	vector<size_t> Ordenar(vector<size_t>v);
	vector<Libro> Relacionados(string palabraBuscada, vector<Libro>&vectorLibros);
	
};
#endif
