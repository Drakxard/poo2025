
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../system/system.h"

using namespace std;

//template<typename T>

class Buscador{
	System sistema;
	vector<Tags> Etiquetas;
public:
	Buscador(){}
	Buscador(vector<Tags>Etiquetas){
		this->Etiquetas = Etiquetas;
	}
	//vector<Libro>::const_iterator Buscar(string nombreBuscado, int Cantidad);
	vector<Libro> Buscar(string &nombreBuscado, vector<Tags> &etiquedasUsadas, int cantidad);
	
	void AgregarEtiqueta(string& nombre);
	void EliminarEtiqueta(int& idEtiqueta);

};
