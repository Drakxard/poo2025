#include "buscador.h"
#include "../libro/libro.h"
#include "../system/system.h"
#include <algorithm>
#include "../Tags/Tags.h"
using namespace std;
vector<size_t> Buscador::Buscar(string nombreBuscado)
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
		resultado = GestorBloque.LeerTodosLosElementos(DireccionBloque);
	}
return resultado;
}
vector<size_t> Buscador::Ordenar(vector<size_t>v){
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









