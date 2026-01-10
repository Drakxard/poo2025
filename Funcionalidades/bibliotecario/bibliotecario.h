#include <string>
#include <vector>
#include "../libro/libro.h"

#include <ctime>
#include "../alumno/alumno.h"
#include "../Persona/persona.h"
using namespace std;
class Bibliotecario: public Persona{
 char nombre[49];
 int id;
public:
	Bibliotecario(int id, const char *nombre):Persona(id,nombre){};
	
	
	int CalcularDiferenciaDias(int dia, int mes, int anio);
	void AgregarLibros(int LibrosAgregar,vector<Libro>&resultadoTest);
	void EliminarLibro(vector<Libro>::const_iterator Eliminar,vector<Libro>&v);
	bool Alumno_quiere_un_libro( Alumno& x );
	bool PrestarLibros(int idLibro, vector<Libro>&v, int dia, int mes, int anio);

};
