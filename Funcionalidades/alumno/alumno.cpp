#include "alumno.h"
int Alumno::VerID() const  
{
	return id;
}
const char* Alumno::VerNombre() const{
	return this->nombre;
}
void Alumno::CambiarNombre(const char *NuevoNombre){
	strncpy(this->nombre, NuevoNombre,49);
	this->nombre[49]='\0';
}
void Alumno::Cambiar_Id(int nuevo_id){
	cin>>nuevo_id;
	this->id= nuevo_id;
}

