#ifndef ALUMNO_H  // 1. Si no está definido PERSONA_H
#define ALUMNO_H
#include "../Persona/persona.h"
class Alumno: public Persona{
    char nombre[49];
    int id;
    bool sancion;
    public:
		Alumno(){}
	    Alumno(int id, const char *nombre):Persona(id,nombre){
        this-> sancion=false;
        };
        bool Versancion();
};
#endif // 3. Fin de la condición
