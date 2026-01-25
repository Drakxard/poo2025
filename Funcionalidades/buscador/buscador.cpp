#include "buscador.h"
#include "../libro/libro.h"
#include "../system/system.h"
#include <algorithm>
#include "../Tags/Tags.h"
using namespace std;
vector<size_t> Buscador::BusquedaSimple(string nombreBuscado)
{
	
	string nombreArchivo = diccionario.VerPathEtiquetas();
	vector<TagUnitario> contenedor;
	contenedor = sistema->VerContenido<TagUnitario>(nombreArchivo,true);
	
	vector<TagUnitario>::iterator buscado = find_if(contenedor.begin(),contenedor.end(),[nombreBuscado](const TagUnitario& a){
		return a.NombreTag == nombreBuscado;
	});
	///Para la comparación, si no es la palabra exacta falla
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
	for(size_t i= 0; i< sizeof(nombreBuscado); ++i){
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
	
	vector<size_t> Buscador:: Ordenar(vector<Libro>&vectorLibros){
		
	};
	
	
	
	
	
	
	
	
