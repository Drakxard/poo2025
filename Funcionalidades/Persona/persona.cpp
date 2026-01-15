#include "persona.h"

using namespace std;

int Persona::VerID() const
{
    return id;
}
const char *Persona::VerNombre() const
{
    return this->nombre;
}
void Persona::CambiarNombre(const char *NuevoNombre)
{
    strncpy(this->nombre, NuevoNombre, 49);
    this->nombre[49] = '\0';
}
void Persona:: CambiarDni(int nuevo_DNI){
    //por si se confundió en algo
    this-> DNI=nuevo_DNI;
}

