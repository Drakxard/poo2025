#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../Tags/Tags.h"

using namespace std;

//template<typename T>
class System;
class Buscador{
	System *sistema;
	Tags diccionario;
public:
	Buscador(){}
	vector<size_t> BusquedaSimple(string nombreBuscado);
	vector<size_t> BusquedaAmpliada(string nombreBuscado);
	vector<string> ExtraerPalabras(string nombreBuscado);
	
	vector<size_t> OrdenarAscendente(vector<size_t>v);
	vector<Libro> Relacionados(string palabraBuscada, vector<Libro>&vectorLibros);
	vector<size_t> Ordenar(vector<Libro>&vectorLibros);
};
#endif
