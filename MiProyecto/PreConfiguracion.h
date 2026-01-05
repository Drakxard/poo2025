#ifndef PRECONFIGURACION_H
#define PRECONFIGURACION_H

System admin("Rafael",1); 

///Binario Donde Trabajar
string archiTest = "Test.bin";

///Carga en vector
///EL segundo argumento (VerLibros(archiTest,1))es un parche temporal, debe 
///arreglarse la funcion
///Así andar para cuando hay o no contenido en el binario correctamente
vector<Libro> resultadoTest = admin.VerLibros(archiTest,1);	

/// Variable/s simples
int idLibro;
int Nlibros;	


#endif
