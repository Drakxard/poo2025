#include "../bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../libro/libro.h"
#include "Historial.h"


template <typename S>
//Recibir vector entero con N-ID, pueden ser de lo que necesites

bool Historial::Verificar_Existencia( vector<S>&v,S LeerRegistro){//string nombreArchivo){
	
	//Buscar si Alumno/Bibliotecario/Libro por ID si existe
	auto verificacion = find_if(v.begin(), v.end(), [LeerRegistro](const S& a) {
		return a.VerID() == LeerRegistro;
	});
	if(verificacion){
		Ver_Registro(LeerRegistro, v); //nombreArchivo);
	}else{
		cout<<"No existe en el sistema"<<endl;
		return false;
	}
	
}



bool Historial::AgregarNuevoRegistro(int IdBibliotecario){return true;}//se debe agregar automaticamente                                                          //una vez prestado el libro
bool Historial::EliminarRegistro(int IdRegistro){return true;};//Si quiere eliminar un libro, un alumno o un Bibliotecario
Void Historial::Ver_Historial(int actual,string nombreArchivo){
	if(Verificar_Existencia()){
		switch (actual){
		case 1:
			VerContenido(string nombreArchivo,bool crear); break;
		case 2:
			VerContenido(string nombreArchivo,bool crear); break;
		case 3:
			VerContenido(string nombreArchivo,bool crear); break;
			
		}
	}
}
