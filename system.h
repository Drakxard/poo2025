#include "base.h"
#include "Libro.h"
#include "persona.h"

class Bibliotecario: public Persona{
 char nombre[49];
 int id;
public:
	Bibliotecario(int id, const char *nombre):Persona(id,nombre){};

	void GuardarLibros(string nombreArhivo, vector<Libro> &A_Guardar);
    vector<Libro> VerLibros(string nombreArchivo,bool crear=false);
	void AgregarLibros(int LibrosAgregar,vector<Libro>&resultadoTest);
	void EliminarLibro(vector<Libro>::const_iterator Eliminar,vector<Libro>&v);
	vector<Libro>::const_iterator BuscarLibro(int idLibro,const vector<Libro>&v);
	bool PrestarLibros(int idLibro,vector<Libro>&v,int cantDiasPrestar);
	
	
<<<<<<< Updated upstream
=======
	///ayrton sanciones
>>>>>>> Stashed changes
};
