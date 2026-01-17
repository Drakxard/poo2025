#ifndef BIBLIOTECARIO_H  // 1. Si no est� definido PERSONA_H
#define BIBLIOTECARIO_H
#include "../preConfiguracion/preConfiguracion.h"
#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../Persona/persona.h"

using namespace std;
class System;
class Bibliotecario: public Persona{
 System* sistema; vector<int>Id_Prestamos;
public:
	Bibliotecario(){}
	Bibliotecario(int id, const char *nombre,int DNI):Persona(id,nombre,DNI){};

<<<<<<< Updated upstream
	template<typename T>
	vector<T> AgregarElementos(int Agregar,string nombreArchivo);
=======
	
	vector<Libro> AgregarLibros(int LibrosAgregar);
>>>>>>> Stashed changes
	void EliminarLibro(vector<Libro>::const_iterator Eliminar,vector<Libro>&v);

//	1) Verificar si no es narco para poder prestarle el libro(es para la funcion Prestar Libro)
	bool Alumno_quiere_un_libro( Alumno& x );
	//este es la funcion grande que inicia el proceso de prestamo
	bool PrestarLibros(size_t idLibro,size_t idAlumno, vector<Libro>&Libros,vector<Alumno>&Alumno, int dia, int mes, int anio);
	// calcula la candtidad de dias de la diferencia entre hoy y la fecha de cuando se iene que devolver el libro(esta funcion se creo para la funcion prestar un libro y para ir actualizando los dias restantes del libro)
	int CalcularDiferenciaDias(int dia, int mes, int anio);

	void AgregarLibroPrestado(int libro_prestado,Vector<int>Id_Prestamos);
	bool Devolucion_libro(int idlibro);

	//LibrosPrestado.bin -> idLibro y IdAlumno 
	bool Sancionar(int idAlumno, string nombreArchivo, bool desicion);
	bool Actualizar_Disponibilidad( int idLibro, string nombreArchivo, bool decision);
	
};
#endif // 3. Fin de la condici�n
