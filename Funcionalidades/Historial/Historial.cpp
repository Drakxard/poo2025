#include "Funcionalidades/bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../libro/libro.h"
#include "Historial.h"


template <typename S>
//Recibir vector entero con N-ID, pueden ser de lo que necesites

bool Historial::Verificar_Existencia( vector<S>&v){,//string nombreArchivo){
        //IdAlumno o IdLibro
//-> 2, 4, ,8, 248

        // ID: 2, existe registro
        //----------------------
        // ID: 4, No existe,,...
        // ID: 5, No existe,,...
        // ID: 6, No existe,,...
        // ID: 7, No existe,,...

        // Buscador->Abre bin, devolveme vector
        // Recursos/Binarios/Historial/libros.bin
        // Recursos/Binarios/Historial/alumnos.bin
}



bool Historial::AgregarNuevoRegistro(int IdBibliotecario){}//se debe agregar automaticamente                                                          //una vez prestado el libro
bool Historial::EliminarRegistro(int IdRegistro){};//Si quiere eliminar un libro o
                                                    //un alumno
void Historial::Ver_Registro(int actual,string nombreArchivo)
{
}
