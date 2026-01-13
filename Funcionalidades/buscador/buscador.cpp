#include "buscador.h"
#include "../libro/libro.h"
#include <algorithm>
using namespace std;
vector<Libro> Buscador::Buscar(string &nombreBuscado, vector<Tags> &etiquedasUsadas, int cantidad)
{
	bool tags= false;
	if(etiquedasUsadas.size()>0){ tags=true;}
	
	//OrdenarIDs
	vector<int> AllID = Ordenar(etiquedasUsadas);
	
	
	
	
	
	
	
vector<Libro>resultado;
return resultado;

}
vector<int> Buscador::Ordenar(vector<Tags>v){
	
	vector<string> paths;
	for(int i = 0 ; i < v.size(); ++i)
		paths.push_back(v[i].path);
	
	
	//A cada path (Recursos/Binarios/Tags/Libros/prestados.bin), etc
	vector<int> Ids;
	vector<int> aux;
	for(int i = 0; i < paths.size(); ++i){
		aux= sistema.VerContenido<int>(paths[i],true);
		Ids.insert(Ids.end(),aux.begin(),aux.end());
	
	}
	
	
	
	vector<int>resultado;
	return resultado;
	
}

void Buscador::AgregarEtiqueta(string& nombre){}


