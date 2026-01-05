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
    vector<Libro> VerLibros(string nombreArchivo,bool crear=false);
	void AgregarLibros(int LibrosAgregar,vector<Libro>&resultadoTest);
	void EliminarLibro(vector<Libro>::const_iterator Eliminar,vector<Libro>&v);
	vector<Libro>::const_iterator BuscarLibro(int idLibro,const vector<Libro>&v);
	bool PrestarLibros(int idLibro,vector <libro>&v,int cantDiasPrestar);
	///ayrton proy final
};
