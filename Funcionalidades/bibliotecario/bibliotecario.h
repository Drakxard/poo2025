#ifndef BIBLIOTECARIO_H  // 1. Si no está definido PERSONA_H
#define BIBLIOTECARIO_H
#include <string>
#include <vector>
#include "../libro/libro.h"

#include <ctime>
#include "../alumno/alumno.h"
//#include "../Persona/persona.h"
#include "../system/system.h"
using namespace std;
class Bibliotecario: public Persona{
 char nombre[49];
 int id;
 System sistema;
public:
	Bibliotecario(int id, const char *nombre):Persona(id,nombre){};
	
	
	int CalcularDiferenciaDias(int dia, int mes, int anio);
	vector<Libro> AgregarLibros(int LibrosAgregar);
	void EliminarLibro(vector<Libro>::const_iterator Eliminar,vector<Libro>&v);
	bool Alumno_quiere_un_libro( Alumno& x );
	bool PrestarLibros(size_t idLibro, vector<Libro>&v, int dia, int mes, int anio);

};
#endif // 3. Fin de la condición
