#ifndef PRECONFIGURACION_H
#define PRECONFIGURACION_H

///Binario Donde Trabajar
string libros = "libros.bin";

///Carga en vector
///EL segundo argumento (VerLibros(archiTest,1))es un parche temporal, debe 
///arreglarse la funcion
///Así andar para cuando hay o no contenido en el binario correctamente
vector<Libro> vectorLibros = admin.VerLibros(libros,1);	

/// Variable/s simples
int idLibro;
int Nlibros;	


#endif
