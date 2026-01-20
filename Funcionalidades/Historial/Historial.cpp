#include "../bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../libro/libro.h"
#include "Historial.h"






bool Historial::AgregarNuevoRegistro(int IdBibliotecario){return true;}//se debe agregar automaticamente                                                          //una vez prestado el libro
bool Historial::EliminarRegistro(int IdRegistro){return true;};//Si quiere eliminar un libro o
                                                    //un alumno


//template <typename S>
//void Historial::Ver_Historial(int actual, vector<S>& v, vector<Registros>& r){	
//		System sistema;
//		auto encontrado=find_if(r.begin(), r.end(), [actual](const Registros& a) {
//			return a.VerID() == idLibro;
//
//}
//	
//void Historial::Ver_Historial_Libro(int actual, vector<Libro>& v, vector<Registros>& r){	
//	System sistema;
//	auto encontrado=find_if(r.begin(), r.end(), [actual](const Registros& a) {
//		return a.VerID() == idLibro;
//		
//	}
//}

