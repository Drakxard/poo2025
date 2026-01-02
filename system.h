#include "base.h"
#include "Libro.h"
class System{
 string nombre;
 int id;
public:
    System(string nombre, int id){
        this->nombre=nombre;
        this->id=id;
    }
	int VerID();
	string VerNombre();
    void GuardarLibros(string nombreArhivo, vector<Libro> &A_Guardar);
    vector<Libro> VerLibros(string nombreArchivo);
	void AgregarLibros(int LibrosAgregar,vector<Libro>&resultadoTest);
	void EliminarLibro(Libro Eliminar,vector<Libro>&resultadoTest);
};
