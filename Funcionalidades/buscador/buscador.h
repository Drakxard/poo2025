
#include <string>
#include <vector>
#include "../libro/libro.h"
using namespace std;
struct Tags{
	string nombre;
	vector<int>registrados;
};
//template<typename T>
class Buscador{
	vector<Tags> Etiquetas;
public:
	Buscador(vector<Tags>Etiquetas){
		this->Etiquetas = Etiquetas;
	}
	//vector<Libro>::const_iterator Buscar(string nombreBuscado, int Cantidad);
	vector<Libro>::const_iterator Buscar(int idLibro, const vector<Libro> &v);
};
