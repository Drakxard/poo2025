#ifndef BIBLIOTECARIO_H 
#define BIBLIOTECARIO_H
#include "../preConfiguracion/preConfiguracion.h"
#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"
#include "../Persona/persona.h"

struct Libros_en_Prestamo;
using namespace std;
class System;
class Bibliotecario: public Persona{
	// CAMBIO CRITICO: Array fijo para compatibilidad binaria en Windows y Linux
	int Id_Prestamos[50]; 
	int CantidadPrestamos;
public:
	Bibliotecario():Persona(){
		CantidadPrestamos = 0;
		for(int i=0; i<50; i++) Id_Prestamos[i] = -1;
	}
	Bibliotecario(size_t id, const char *nombre,size_t DNI):Persona(id,nombre,DNI){
		CantidadPrestamos = 0;
		for(int i=0; i<50; i++) Id_Prestamos[i] = -1;
	};
	
	// Pasamos system por referencia
	template<typename T>
	vector<T> AgregarElementos(int Agregar, string nombreArchivo, System& sys);
	
	vector<Libro> AgregarElementos(int Agregar, string nombreArchivo, System& sys);
	
	void EliminarLibro(vector<Libro>::const_iterator Eliminar, vector<Libro>&v);
	
	bool Alumno_quiere_un_libro( Alumno& x );
	
	bool PrestarLibros(size_t idLibro, size_t idAlumno, vector<Libro>&Libros, vector<Alumno>&Alumno, vector<Libros_en_Prestamo>& Prestamos , int dia, int mes, int anio);
	
	int CalcularDiferenciaDias(int dia, int mes, int anio);
	
	void AgregarLibroPrestado(size_t id_LibroPrestado,size_t id_AlumnoPrestado, int dia, int mes, int anio, vector<Libros_en_Prestamo>& Prestamos);
	bool Devolucion_libro(size_t idLibro, size_t idAlumno, vector<Libro> &Libros, vector<Alumno> &Alumnos, vector<Libros_en_Prestamo>& Prestamos, int dia_Devolucion, int mes_Devolucion, int anio_Devolucion);
	
	bool Sancionar(int idAlumno, string nombreArchivo, bool desicion, System& sys);
	bool Actualizar_Disponibilidad( int idLibro, string nombreArchivo, bool decision, System& sys);
	
	template<typename T>
	void CargarNuevos(int cant, string nombreArchivo, System& sys);
	void CargarNuevosLibros(int cant, string nombreArchivo, System& sys);
};
#endif
