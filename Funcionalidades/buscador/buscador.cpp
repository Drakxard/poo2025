#include "buscador.h"
#include "../libro/libro.h"
#include <algorithm>
using namespace std;
vector<Libro>::const_iterator Buscador::Buscar(string &nombreBuscado, vector<Tags> &etiquedasUsadas, int cantidad)
{
	while(cantidad>0){
		for(int i = 0 ; i< etiquedasUsadas.size(); ++i){
			Tags actual = etiquedasUsadas[i];
			//actual.path = "Recursos/Tags/Libros.bin"
			//Ids libros correspondientes
			vector<int> elementosAsociados = sistema.VerContenido<int>(actual.path,true);
			for(int j=0;j<elementosAsociados.size();++j){
				int actualJ= elementosAsociados[i];
				vector<Libro>::const_iterator it = Saltar<Libro>();
				if (it != v.end())
				{
					return it;
				}
	else
	{
		return v.end();
	}



}//Fin while Principal
}


void Buscador::AgregarEtiquetas(){}


