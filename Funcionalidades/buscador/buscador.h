
#include <string>
#include <vector>
#include "../libro/libro.h"
using namespace std;

//template<typename T>
class Buscador{
	vector<string> Etiquetas;
public:
	Buscador(){}
	Buscador(vector<string>Etiquetas){
		this->Etiquetas = Etiquetas;
	}
	//vector<Libro>::const_iterator Buscar(string nombreBuscado, int Cantidad);
	vector<Libro>::const_iterator Buscar(int idLibro, const vector<Libro> &v);
};
