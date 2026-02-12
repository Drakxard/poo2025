#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "../preConfiguracion/preConfiguracion.h"
#include "../bibliotecario/bibliotecario.h"
#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"

//prestados.bin ->registro de los prestamos
struct Registro{
size_t id_libro, id_usuario;
string nombre_usuario, nombre_libro;
int anio,mes,dia;
};
class Historial{
    System sistema;
    public:
        Historial(size_t id){
        }
		
        template<typename S>
		void Ver_Historial(int actual, vector<S>& v);
		void Ver_Historial_libros(int actual, vector<Libro>& v);
};
#endif
