#include <fstream>
#include <string>
#include <vector>
#include "../libro/libro.h"
using namespace std;
//template<typename K>
class System{
public:
    System(){};
    void Guardar(string nombreArhivo, vector<Libro> &A_Guardar);
    vector<Libro> VerContenido(string nombreArchivo,bool crear);
    bool actualizar_disponibilidad( string nombreArchivo, int id);

};
