#include "buscador.h"
#include "../libro/libro.h"
#include <algorithm>
using namespace std;
vector<Libro>::const_iterator Buscador::Buscar(string &nombreBuscado, vector<Tags> &etiquedasUsadas, int Cant)
{



	vector<Libro>::const_iterator it = find_if(v.begin(), v.end(), [nombreBuscado](const Libro a)
											   { return a.VerNombre() == nombreBuscado; });
	if (it != v.end())
	{
		return it;
	}
	else
	{
		return v.end();
	}
}


void Buscador::AgregarEtiquetas(){}


