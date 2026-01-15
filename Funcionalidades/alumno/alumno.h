#ifndef ALUMNO_H  // 1. Si no est� definido PERSONA_H
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
		int VerID() const;
		const char* VerNombre() const;
		void CambiarNombre(const char* NuevoNombre);
		void Cambiar_Id( int nuevo_id);
        //Propios para uso del bibliotecario
        //No darle acceso al alumno (No en botones)
        bool VerEstadoDeSancion(){{return sancion;}};
        void Sancionar(bool desicion) { sancion =desicion;};
        void CrearObjetoCorrespondienteAlumno(int posAlumno, vector<Alumno>&v );
};
#endif // 3. Fin de la condici�n
