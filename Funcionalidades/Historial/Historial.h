#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "../preConfiguracion/preConfiguracion.h"

#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"

//prestados.bin ->registro de los prestamos

class Historial{
    System sistema;  
    int IdUsuario; //puede ser alumno o bibliotecario
    bool ingreso;
    public:
        Historial(int x){
        this->ingreso=false; 
		IdUsuario=x;
        }
        template<typename S>
        bool Verificar_Existencia(int Id,string nombreArchivo);
        
		bool AgregarNuevoRegistro(int IdBibliotecario);//trabajo del bibliotecario
        
		bool EliminarRegistro(int IdRegistro);
		
		template<typename S>
        void Ver_Registro(int actual,vector<S>& v,string nombreArchivo);

};
#endif
