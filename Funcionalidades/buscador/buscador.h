
#include <string>
#include <vector>
#include "../libro/libro.h"
using namespace std;

//template<typename T>
struct Tags{
	string nombre,path;
};
class Buscador{
	vector<Tags> Etiquetas;
public:
	Buscador(){}
	Buscador(vector<Tags>Etiquetas){
		this->Etiquetas = Etiquetas;
	}
	//vector<Libro>::const_iterator Buscar(string nombreBuscado, int Cantidad);
	vector<Libro>::const_iterator Buscar(string& nombreBuscado, vector<Tags>&etiquedasUsadas);
	
	void AgregarEtiqueta(string& nombre);
	void EliminarEtiqueta(int& idEtiqueta);

};
