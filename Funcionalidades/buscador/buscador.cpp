#include "buscador.h"
vector<Libro>::const_iterator Buscador::BuscarLibro(int idLibro, const vector<Libro> &v)
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




