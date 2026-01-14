#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"

//prestados.bin ->registro de los prestamos
template<typename S>
class Historial{
    System sistema;  
    int LeerRegistro; //puede ser alumno/ bibliotecario/libro
    bool ingreso;

    public:
        Historial(int x){
        this->ingreso=false; LeerRegistro=x;
        }
        
        bool AgregarNuevoRegistro(int IdBibliotecario);
        bool EliminarRegistro(int IdRegistro);
        void Ver_Historial(string nombreArchivo);
};