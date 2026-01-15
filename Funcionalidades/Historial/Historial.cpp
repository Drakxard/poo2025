#include "../bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../libro/libro.h"
#include "Historial.h"






bool Historial::AgregarNuevoRegistro(int IdBibliotecario){return true;}//se debe agregar automaticamente                                                          //una vez prestado el libro
bool Historial::EliminarRegistro(int IdRegistro){return true;};//Si quiere eliminar un libro, un alumno o un Bibliotecario
//Alumnos ->nombreArchivo = sistema.alumnos();
//Bibliotecarios  ->nombreArchivo = sistema.bibliotecarios();
//Registro  ->nombreArchivo = sistema.bibliotecarios();
void Historial::Ver_Historial(string nombreArchivo){
	
//		if(sistema.Verificar_Existencia(nombreArchivo)){
//		VerContenido(sistema.libro,bool crear);//muestra todo. pero hay que filtrar
//		}	
}
