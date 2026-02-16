#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

//prestados.bin ->registro de los prestamos
struct Registro{
size_t id_libro, id_usuario;
char nombre_usuario[49], nombre_libro[50];
int anio,mes,dia;
};
class Historial{
    public:
        Historial(){}
		vector<Registro> Mostrar_Historial(size_t id_usuario,string nombreArchivo="Recursos/Binarios/Historial.bin");
		vector<Registro> Mostrar_Historial_libro(size_t id_libro,string nombreArchivo="Recursos/Binarios/Historial.bin");
		void Cargar_Historial(size_t idLibro, size_t idAlumno,string nom_usu, string nom_lib,int dia,int mes,int anio, string nombreArchivo="Recursos/Binarios/Historial.bin" );
};


#endif
