#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "../preConfiguracion/preConfiguracion.h"

#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"

/*prestados.bin ->registro de los prestamos*/
struct Registros{
    int id_usuario, id_libro;
};
class Historial{
    System sistema;  
    int IdUsuario; //puede ser alumno o bibliotecario
    bool ingreso;
    public:
        Historial(int x){
        this->ingreso=false; 
		IdUsuario=x;
        }
		bool AgregarNuevoRegistro(int IdBibliotecario);//trabajo del bibliotecario
		bool EliminarRegistro(int IdRegistro);
//		template<typename S>
//		void Ver_Historial(int actual, vector<S>& v, vector<Registros>& r);
//		void Ver_Historial_Libro(int actual, vector<Libro>& v, vector<Registros>& r);

};
#endif
