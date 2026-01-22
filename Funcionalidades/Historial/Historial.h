#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "../preConfiguracion/preConfiguracion.h"

#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"

/*prestados.bin ->registro de los prestamos*/
struct Registros{
<<<<<<< Updated upstream
    int id_usuario, id_libro;
=======
	int id_usuario, id_libro;
>>>>>>> Stashed changes
};
class Historial{
	System sistema;  
	int IdUsuario; //puede ser alumno o bibliotecario
	bool ingreso;
public:
	Historial(int x){
		this->ingreso=false; 
		IdUsuario=x;
<<<<<<< Updated upstream
        }
		bool AgregarNuevoRegistro(int IdBibliotecario);//trabajo del bibliotecario
		bool EliminarRegistro(int IdRegistro);
		template<typename S>
		void Ver_Historial(int actual, vector<S>& v);
		void Ver_Historial_libros(int actual, vector<Libro>& v);

=======
	}
	bool AgregarNuevoRegistro(int IdBibliotecario);//trabajo del bibliotecario
	bool EliminarRegistro(int IdRegistro);
	template<typename S>
	void Ver_Historial(int actual, vector<S>& v);
	void Ver_Historial_libros(int actual, vector<Libro>& v);
	
>>>>>>> Stashed changes
};
#endif
