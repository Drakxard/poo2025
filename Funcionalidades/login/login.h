#include "../preConfiguracion/preConfiguracion.h"

System sistema;
int BuscarDniEnBibliotecarios(int dni,vector<Bibliotecario>& v);
int BuscarDniEnAlumnos(int dni,vector<Alumno>&v);
Bibliotecario CrearObjetoCorrespondienteBibliotecario(int posBibliotecario, vector<Bibliotecario>&v );
Alumno CrearObjetoCorrespondienteAlumno(int posAlumno, vector<Alumno>&v );
