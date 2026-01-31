#include "buscador.h"
#include "../libro/libro.h"
#include "../system/system.h"
#include <algorithm>
#include "../Bloques/Bloques.h"
using namespace std;
vector<size_t> Buscador::BusquedaSimple(string nombreBuscado)
{
	
	string nombreArchivo = diccionario.VerPathEtiquetas();
	cout<<endl<<"Archivo a abrir: "<<nombreArchivo<<endl;



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
	cout<<endl<<nombreBuscado.length()<<endl;
	for(size_t i= 0; i< nombreBuscado.length(); ++i){
		if(nombreBuscado[i]!=' '){
			palabra += nombreBuscado[i];
		}else{
			resultado.push_back(palabra);
			palabra="";
		}
	}
	resultado.push_back(palabra);
	return resultado;
}
vector<size_t> Buscador::OrdenarAscendente(vector<size_t>v){
	sort(v.begin(),v.end());
	return v;
	
}
template <typename T>
vector<T>Buscador::Relacionados(string palabraBuscada, vector<T>&v){
	vector<T> aux;
	auto encontrado = v.begin();
	size_t pos=0;
	while(encontrado!=v.end()){
		
		encontrado = find_if(v.begin()+pos,v.end(),[palabraBuscada](const T& a){	
			
			return a.VerNombre() == palabraBuscada;
		});
		
		if(encontrado== v.end()){break;}
		
		aux.push_back(*encontrado);//Devuelve posiciones
		pos=(encontrado-v.begin())+1;
	}
	return aux;
}
	
	
	vector<size_t> Buscador:: ResultadoBusqueda(vector<size_t>&All_IDs){
		vector<size_t> resultado;
		if(All_IDs.size()==0) return resultado;
		Ranking aux;
		
		OrdenarAscendente(All_IDs);
		
		///Contar IDs Distintos
		vector<Ranking>resultadosParciales;
		bool primero = true;
		for(size_t i = 0; i < All_IDs.size();++i){
			if(primero){
				primero = false;
				aux.cuenta = count(All_IDs.begin(),All_IDs.end(),All_IDs[i]);
				aux.valor= All_IDs[i];
				resultadosParciales.push_back(aux);
			}else{
				if(All_IDs[i]!=All_IDs[i-1]){
					aux.cuenta = count(All_IDs.begin(),All_IDs.end(),All_IDs[i]);
					aux.valor= All_IDs[i];
					resultadosParciales.push_back(aux);
				}
			}
		}
		
		///Ordenar Descendente
		sort(resultadosParciales.begin(),
			 resultadosParciales.end(),
			 [](const Ranking& a, const Ranking& b){
				 return a.cuenta > b.cuenta;
			 });
		
		///Retornar solo mayor inferencia
		for(Ranking&x:resultadosParciales)
			resultado.push_back(x.valor);
		return resultado;
}
	
	
template vector<Alumno>Buscador:: Relacionados(string palabraBuscada, vector<Alumno>&v)
	
	
	
	
	
