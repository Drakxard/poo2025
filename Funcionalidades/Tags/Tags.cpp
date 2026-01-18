#include "Tags.h"

using namespace std;


int Tags::VerID() const
{
	return id;
}

const char *Tags::VerNombre() const
{
	return this->nombre;
}
void Tags::CambiarNombre(const char *NuevoNombre)
{
	strncpy(this->nombre, NuevoNombre, 49);
	this->nombre[49] = '\0';
}
void Tags::Cambiar_Id(int nuevo_id){
	cin>>nuevo_id;
	this->id= nuevo_id;
}


