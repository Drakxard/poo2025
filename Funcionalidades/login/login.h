#ifndef LOGIN_H
#define LOGIN_H
#include "../preConfiguracion/preConfiguracion.h"
#include "../bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../system/system.h" // Necesario para conocer los tipos

extern System sistema; 

// Declara las funciones, pero no las variables globales
int BuscarDniEnBibliotecarios(int dni, vector<Bibliotecario>& v);
int BuscarDniEnAlumnos(int dni, vector<Alumno>& v);
Bibliotecario CrearObjetoCorrespondienteBibliotecario(int posBibliotecario, vector<Bibliotecario>& v);
Alumno CrearObjetoCorrespondienteAlumno(int posAlumno, vector<Alumno>& v);

#endif
