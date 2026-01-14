#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"


struct Registro{
    int IdLibro,IdAlumno, IdBibliotecario;

};
//prestados.bin ->registro de los prestamos

class Historial{
    System sistema;  
    int LeerRegistro; //puede ser alumno o bibliotecario
    bool ingreso;
    public:
        Historial(int x){
        this->ingreso=false; LeerRegistro=x;
        }
        template<typename S>
        bool Verificar_Existencia( vector<S>&v,S LeerRegistro);
        bool AgregarNuevoRegistro(int IdBibliotecario);
        bool EliminarRegistro(int IdRegistro);
        void Ver_Historial(int actual,string nombreArchivo);

};
