#include "buscador.h"
#include "../libro/libro.h"
#include "../system/system.h"
#include <algorithm>
#include "../Bloques/Bloques.h"
using namespace std;
vector<size_t> Buscador::BusquedaSimple(string nombreBuscado)
{
	
	string nombreArchivo = diccionario.VerPathEtiquetas();
	vector<Tags> contenedor;
	contenedor = sistema->VerContenido<Tags>(nombreArchivo,true);
	
	vector<Tags>::iterator buscado = find_if(contenedor.begin(),contenedor.end(),[nombreBuscado](const Tags& a){
		return a.NombreTag == nombreBuscado;
	});
	///Para la comparaci�n, si no es la palabra exacta falla
	///estaria bueno hacer por prefijo, truncar diccionario
	///Y palabra ingresada
	vector<size_t>resultado;
	size_t DireccionBloque;
	if(buscado != contenedor.end()){
		DireccionBloque = buscado->IdTag;
		resultado = diccionario.LeerTodosLosElementos(DireccionBloque);
	}
	return resultado;
}
vector<size_t> Buscador::BusquedaAmpliada(string nombreBuscado){
	///Truncar frase a vector de palabras
	vector<string> palabras = ExtraerPalabras(nombreBuscado);
	vector<size_t> resultadoParcial;
	vector<size_t>resultado;
	for(size_t i = 0; i<palabras.size();++i){
		resultadoParcial = BusquedaSimple(nombreBuscado);
		resultado.insert(resultado.end(), resultadoParcial.begin(), resultadoParcial.end());
	}
	return resultado;
}

vector<string> Buscador::ExtraerPalabras(string nombreBuscado){
	vector<string> resultado;
	string palabra;
	for(size_t i= 0; i< nombreBuscado.length(); ++i){
		if(nombreBuscado[i]!=' '){
			palabra += nombreBuscado[i];
		}else{
			resultado.push_back(palabra);
			palabra="";
		}
	}
	return resultado;
}
vector<size_t> Buscador::OrdenarAscendente(vector<size_t>v){
	sort(v.begin(),v.end());
	return v;
	
}

vector<Libro> Relacionados(string palabraBuscada, vector<Libro>&vectorLibros){
	vector<Libro> aux;
	int avanzar=0;
	auto encontrado = vectorLibros.begin();
	while(encontrado!=vectorLibros.end()){
		encontrado = find_if(vectorLibros.begin()+avanzar,vectorLibros.end(),[palabraBuscada](const Libro& a){
			return a.VerNombre() == palabraBuscada;
		});
		if(encontrado== vectorLibros.end()){break;}
		
		aux.push_back(*encontrado);//Devuelve posiciones
		++avanzar;
	}
	return aux;
}
	
	vector<size_t> Buscador:: Repetidos(vector<Libro>&vector_busqueda_apliada){
		vector<size_t> resultado;
		if(vector_busqueda_apliada.empty()) return resultado;
		// Extraer IDs
		vector<size_t> ids;
		ids.reserve(vector_busqueda_apliada.size());
		for(const auto &l : vector_busqueda_apliada){
			ids.push_back(l.VerID());
		}
		// Ordenar para agrupar iguales
		sort(ids.begin(), ids.end());
		// Contar repetidos consecutivos
		vector<pair<size_t,size_t>> conteos; // (count, id)
		size_t actual_id = ids[0];
		size_t cuenta = 1;
		for(size_t i=1;i<ids.size();++i){
			if(ids[i] == actual_id) {
				++cuenta;
			} else {
				conteos.emplace_back(cuenta, actual_id);
				actual_id = ids[i];
				cuenta = 1;
			}
		}
		conteos.emplace_back(cuenta, actual_id);
		// Ordenar por frecuencia descendente; en empate, por id ascendente
		sort(conteos.begin(), conteos.end(), [](const pair<size_t,size_t>& a, const pair<size_t,size_t>& b){
			if(a.first != b.first) return a.first > b.first;
			return a.second < b.second;
		});
		// Construir resultado con los IDs en orden deseado
		for(const auto &p : conteos){
			resultado.push_back(p.second);
		}
		return resultado;
	};
	
	
	
	
	
	
	
	
