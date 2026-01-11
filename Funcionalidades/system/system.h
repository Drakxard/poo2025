#include <fstream>
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../alumno/alumno.h"
using namespace std;
//template<typename K>
struct Tags{
	string nombre,path;
};
class System{

	///De libro
	string prestados = "Recursos/binarios/prestados.bin";
	string matematica = "Recursos/binarios/matematica.bin";
	string poo = "Recursos/binarios/poo.bin";
	string fisica = "Recursos/binarios/fisica.bin";
	///N-tags
public:
    System(){};
	template<typename T>
	void Guardar(string nombreArhivo, vector<T> &A_Guardar);
	template<typename T>
    vector<T> VerContenido(string nombreArchivo,bool crear);
    template<typename T>
	vector<T> etiquetas(const string& path);
	bool actualizar_disponibilidad( string nombreArchivo, int id);
	
};
/* Sí necesitas clase template y separar code en .cpp
///Instanciación Explícita
///	Esta técnica permite dejar el código en el .cpp 
///y que el compilador no se queje, pero tiene una condición: 
///debes saber de antemano qué tipos de datos vas a usar 
///		(por ejemplo, System<Alumno> o System<Libro>)
/// Al final del archivo, instancia los tipos que vayas a usar:
template class System<Alumno>; 
template class System<Libro>;
*/
