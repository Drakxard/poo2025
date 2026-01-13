#include "../bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../libro/libro.h"
#include "Historial.h"


template <typename S>
//Recibir vector entero con N-ID, pueden ser de lo que necesites

bool Historial::Verificar_Existencia( vector<S>&v){//string nombreArchivo){
	
	//Buscar si Alumno/Bibliotecario/Libro por ID si existe
	auto verificacion = find_if(v.begin(), v.end(), [LeerRegistro](const S& a) {
		return S.VerID() == LeerRegistro;
	});
	if(verificacion){
		Ver_Registro(LeerRegistro, vector<S>&v) //nombreArchivo);
	}else{
		cout<<"No existe en el sistema"<<endl;
		return false;
	}
	
}



bool Historial::AgregarNuevoRegistro(int IdBibliotecario){}//se debe agregar automaticamente                                                          //una vez prestado el libro
bool Historial::EliminarRegistro(int IdRegistro){};//Si quiere eliminar un libro o
                                                    //un alumno
Registro Historial::Ver_Registro(int actual,string nombreArchivo)
{
}
