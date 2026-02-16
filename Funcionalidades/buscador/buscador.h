#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../Bloques/Bloques.h"
#include "../system/system.h"
#include <algorithm>
#include "../bibliotecario/bibliotecario.h"

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
	vector<Libro> Busqueda_Autor(string autorBuscado, vector<Libro>&v);
	vector<size_t> ResultadoBusqueda(vector<size_t>&All_IDs);
};


template <typename T>
vector<T>Buscador:: Relacionados(string palabraBuscada, vector<T>&v){
	vector<T> aux;
	auto encontrado = v.begin();
	size_t pos=0;
	while(encontrado!=v.end()){
		encontrado = find_if(v.begin()+pos,v.end(),[palabraBuscada](const T& a){
			
			return a.VerNombre() == palabraBuscada;
		});
		if(encontrado== v.end()){break;}
		
		aux.push_back(*encontrado);
		pos=(encontrado-v.begin())+1;
	}
	return aux;
}

#endif
