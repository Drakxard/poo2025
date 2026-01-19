#include "../bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../libro/libro.h"
#include "Historial.h"


template <typename S>
bool Historial::Verificar_Existencia(int Id, string nombreArchivo){
	//Buscar si Alumno/Bibliotecario/Libro por ID si existe
	ifstream archi(nombreArchivo, ios::binary| ios::ate);
	if(!archi)
		throw runtime_error("no se pudo abrir el archivo, "+nombreArchivo);
	
	S aux;
	archi.read(reinterpret_cast<char*>(&aux),sizeof(aux));
		if(aux.VerID()==Id){
			archi.close();
			return true;
		}
	archi.close();
	return false;
}



bool Historial::AgregarNuevoRegistro(int IdBibliotecario){return true;}//se debe agregar automaticamente                                                          //una vez prestado el libro
bool Historial::EliminarRegistro(int IdRegistro){return true;};//Si quiere eliminar un libro o
                                                    //un alumno

template <typename S>
void Historial::Ver_Registro(int actual, vector<S>& v, string nombreArchivo){	
	if(Verificar_Existencia(actual,nombreArchivo)){
		//mostrar el historial de libros o usuarios
		//pero como lo hago?
	}
	   
}
