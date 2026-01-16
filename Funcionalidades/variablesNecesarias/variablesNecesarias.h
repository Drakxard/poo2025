#ifndef VARIABLESNECESARIAS_H
#define VARIABLESNECESARIAS_H
//Importar Clases propias
#include "../system/system.h"
#include "../buscador/buscador.h"
#include "../libro/libro.h"
#include "../bibliotecario/bibliotecario.h"

#include "../preConfiguracion/preConfiguracion.h"

string NombreUsuario= "Invitado";
int codigo = 1;
/// Variables
const char *nom = NombreUsuario.c_str();
///Crear entedidad del sistema de gestion
Bibliotecario admin(codigo,nom); 
///Clase encargada de los metodos de bajo nivel
System sistema;

/// Nombre del Binario de test
string libros = "Recursos/Binarios/libros.bin";
string usuarios = "Recursos/Binarios/usuarios.bin";
string bibliotecarios = "Recursos/Binarios/bibliotecarios.bin";

///Clase encargada de las busquedas
Buscador navega;
string palabra="Casa";

vector<Libro> resultadoLibros;
///Estados Especiales
///De alumno
string sancionados = "Recursos/binarios/sancionados.bin";
///De libro
string prestados = "Recursos/binarios/prestados.bin";
string matematica = "Recursos/binarios/matematica.bin";
string poo = "Recursos/binarios/poo.bin";
string fisica = "Recursos/binarios/fisica.bin";
///N-tags


vector<Libro> vectorLibros = sistema.VerContenido<Libro>(libros, 1);
int idLibro;
int Nlibros;	

///Iteradores para los metodos
vector<Libro>::const_iterator it;
vector<Libro>::const_iterator itBorrar;
int c;

vector<Tags> Etiquetas;
string etiquetasLibros = "Recursos/binarios/Tags/Libros.bin";
string TagsAlmunos= "Recursos/binarios/Tags/Alumnos.bin";
#endif
