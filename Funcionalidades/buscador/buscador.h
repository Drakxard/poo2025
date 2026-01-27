#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../Bloques/Bloques.h"

using namespace std;

//template<typename T>
class System;

struct Ranking{
	size_t cuenta, valor;
};
class Buscador{
	System *sistema;
	Bloques diccionario;
public:
	Buscador(){}
	vector<size_t> BusquedaSimple(string nombreBuscado);
	vector<size_t> BusquedaAmpliada(string nombreBuscado);
	vector<string> ExtraerPalabras(string nombreBuscado);
	
	vector<size_t> OrdenarAscendente(vector<size_t>v);
	template <typename T>
	vector<T> Relacionados(string palabraBuscada, vector<T>&v);
	vector<size_t> ResultadoBusqueda(vector<size_t>&All_IDs);
};
#endif
