#ifndef PERSONA_H  // 1. Si no est� definido PERSONA_H
#define PERSONA_H
#include <cstring>
#include <vector>
#include <fstream>
#include "../libro/libro.h"


using namespace std;

class Persona{
    int id, DNI;
    char nombre[49]; 
    public:
		Persona(){}
        Persona(int id, const char *nombre, int actual_DNI){
			this->id = id;
			strncpy(this->nombre, nombre, 49);
			this->nombre[49] = '\0';
            DNI=actual_DNI;
        }
        int VerID() const;
        const char *VerNombre() const;
        void CambiarNombre(const char *NuevoNombre);
        void CambiarDni(int nuevo_DNI);
        
};
#endif // 3. Fin de la condici�n
