#include "buscador.h"
#include "../libro/libro.h"
#include <algorithm>
using namespace std;
vector<Libro>::const_iterator Buscador::Buscar(int idLibro, const vector<Libro> &v)
{
	vector<Libro>::const_iterator it = find_if(v.begin(), v.end(), [idLibro](const Libro a)
											   { return a.VerID() == idLibro; });
	if (it != v.end())
	{
		return it;
	}
	else
	{
		return v.end();
	}
}




