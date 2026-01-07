#include "Libro.h"
int Libro::VerID() const  
{
    return id;
}
const char* Libro::VerNombre() const{
    return this->nombre;
}

bool Libro::EstadoDisponibilidad(){
	if (disponibilidad)
		disponibilidad = true;
	else
		disponibilidad = false;
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
    //Luego al devolver primero buscar en ese vector diria, sino estÃ¡
    //ahÃ­, marcarlo como devuelto (reset estados)

    if(diasRestantes>=0)
    diasRestantes--;
    else
        CambiarEstado(1);
}

void Libro::DiasRestantes(int dias){
    diasRestantes = dias;
}

void Libro::CambiarNombre(const char *NuevoNombre){
	strncpy(this->nombre, NuevoNombre,49);
	this->nombre[49]='\0';
}

bool Libro::operator==(const Libro& otro) const {
	// Comparamos si los IDs son iguales.
	// Si tus variables se llaman diferente, cámbialas aquí.
	return this->id == otro.id; 
}


