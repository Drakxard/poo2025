#include <fstream>
#include <string>
#include <vector>
#include "../libro/libro.h"
using namespace std;
//template<typename K>
struct Tags{
	string nombre,path;
};
class System{
	string AllTags= "../../Recursos/binarios/etiquetas.bin";
	
	///De libro
	string prestados = "Recursos/binarios/prestados.bin";
	string matematica = "Recursos/binarios/matematica.bin";
	string poo = "Recursos/binarios/poo.bin";
	string fisica = "Recursos/binarios/fisica.bin";
	///N-tags
public:
    System(){};
    void Guardar(string nombreArhivo, vector<Libro> &A_Guardar);
    vector<Libro> VerContenido(string nombreArchivo,bool crear);
    bool actualizar_disponibilidad( string nombreArchivo, int id);
	vector<Tags> etiquetas();
};
