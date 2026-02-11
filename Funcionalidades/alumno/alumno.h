#ifndef ALUMNO_H  // 1. Si no est� definido PERSONA_H
#define ALUMNO_H
#include "../Persona/persona.h"
class Alumno: public Persona{
    bool sancion;
    vector<Alumno> resultadoAlumnos;
    public:
		Alumno(){}
	    Alumno(size_t id, const char *nombre,size_t DNI):Persona(id,nombre,DNI){
        this-> sancion=false;
        };
        //Propios para uso del bibliotecario
        //No darle acceso al alumno (No en botones)
        bool VerEstadoDeSancion() const { return sancion; };
        void Sancionar(bool desicion) { sancion =desicion;};
};
#endif // 3. Fin de la condici�n
