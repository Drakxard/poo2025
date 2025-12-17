#include "base.cpp"
#include "libro.cpp"

class System{
public:
    void GuardarLibros(string nombreArhivo, vector<Libro> &A_Guardar);
    vector<Libro> VerLibros(string nombreArchivo);
};
