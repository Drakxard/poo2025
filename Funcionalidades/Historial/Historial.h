#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"

struct Registro{
    int IdLibro,IdAlumno;
};
//prestados.bin ->registro de los prestamos
class Historial{
    System sistema;  
    public:
    bool AgregarNuevoRegistro();
    bool EliminarRegistro(int IdRegistro);
    void Ver_Registro(Registro& actual, string nombreArchivo);

};