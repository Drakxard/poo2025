#include "Libro.h"
int Libro::VerID()
{
    return id;
}
string Libro::VerNombre(){
    return nombre;
}
void Libro::CambiarEstado(bool estado)
{
    if (estado)
        caduco = true;
    else
        caduco = false;
}

void Libro::RestarDia()
{
    //Llega hasta 0 dias, cuando se sobrepasa, caduca la devolucion
    //Ya no restar dias (antes de llamar)
    //sino antes preguntar si esta caducada la devolucion
    //Caducado -> Notificacion/Vector caducados
    //Luego al devolver primero buscar en ese vector diria, sino está
    //ahí, marcarlo como devuelto (reset estados)

    if(diasRestantes>=0)
    diasRestantes--;
    else
        CambiarEstado(1);
}

void Libro::DiasRestantes(int dias){
    diasRestantes = dias;
}

void Libro::CambiarNombre(string NuevoNombre){
    nombre=NuevoNombre;
}