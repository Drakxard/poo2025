#ifndef PERSONA_H  // 1. Si no est? definido PERSONA_H
#define PERSONA_H
#include <cstring>
#include <vector>
#include <fstream>
#include "../libro/libro.h"


using namespace std;

class Persona{
	size_t id, DNI;
	char nombre[49]; 
<<<<<<< Updated upstream
	vector<int> Leidos;
=======
//	vector<int> Leidos;
>>>>>>> Stashed changes
public:
	Persona(){}
	Persona(size_t id, const char *nombre,size_t DNI){
		this->id = id;
		this->DNI = DNI;
		
		strncpy(this->nombre, nombre, 49);
		this->nombre[49] = '\0';
	}
		int VerID() const;
		int VerDNI() const;
		const char *VerNombre() const;
		void CambiarNombre(const char *NuevoNombre);
		void Cambiar_Id( int nuevo_id);
<<<<<<< Updated upstream
		void Agregar_Leidos(size_t x);
		const vector<int> Ver_Leidos() const;
=======
//		void Agregar_Leidos(size_t x);
//		const vector<int> Ver_Leidos() const;
>>>>>>> Stashed changes
		vector<Libro> VerLibros(string nombreArchivo,bool crear=false);//usan tanto el Bibliotecario como el Alumno
};
#endif // 3. Fin de la condici?n
