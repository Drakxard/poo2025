#ifndef ALUMNO_H  // 1. Si no est� definido PERSONA_H
#define ALUMNO_H
#include "../Persona/persona.h"
class Alumno: public Persona{
    bool sancion;
    public:
		Alumno(){}
		Alumno(int id, const char* n, int dni) : Persona(id, n, dni){
        this-> sancion=false;
        };

        //Propios para uso del bibliotecario
        //No darle acceso al alumno (No en botones)
        bool VerEstadoDeSancion(){{return sancion;}};
        void Sancionar(bool desicion) { sancion =desicion;};
        void CrearObjetoCorrespondienteAlumno(int posAlumno, vector<Alumno>&v );
};
#endif // 3. Fin de la condici�n
