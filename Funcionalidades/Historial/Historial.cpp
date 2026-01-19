#include "../bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../libro/libro.h"
#include "Historial.h"


template <typename S>
//Recibir vector entero con N-ID, pueden ser de lo que necesites

bool Historial::Verificar_Existencia(int x, vector<S>&v){//string nombreArchivo){
	
	//Buscar si Alumno/Bibliotecario/Libro por ID si existe
	///usar sistema.verultimo();
	auto verificacion = find_if(v.begin(), v.end(), [x](const S& a) {
		return a.VerID() == x;
	});
	if(verificacion){
		Ver_Registro(x,v); //nombreArchivo);
	}else{
		cout<<"No existe en el sistema"<<endl;
		return false;
	}
	
}



bool Historial::AgregarNuevoRegistro(int IdBibliotecario){return true;}//se debe agregar automaticamente                                                          //una vez prestado el libro
bool Historial::EliminarRegistro(int IdRegistro){return true;};//Si quiere eliminar un libro o
                                                    //un alumno
Registro Historial::Ver_Registro(int actual,string nombreArchivo)
{	Registro aux;
	return aux;
}
