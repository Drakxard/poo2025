#include "base.h"
#include "persona.h"
class Alumno: public Persona{
    char nombre[49];
    int id;
    bool sancion;
    public:
	    Alumno(int id, const char *nombre):Persona(id,nombre){
        this-> sancion=false;
        };
        bool Versancion();
};