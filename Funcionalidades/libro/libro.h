#ifndef LIBRO_H
#define LIBRO_H
#include <cstring>
#include <iostream>

using namespace std;

class Libro
{
	size_t id;
	char nombre[50];
	int diasRestantes;
	bool disponible; // Quitamos la inicializaci�n aqu� para hacerlo en el constructor
	bool caduco;
	vector<Libro> resultadoLibros;
public:
	Libro()
	{
		id = -1;
		disponible = true;
		diasRestantes = 0;
	};
	
	Libro(size_t id, const char* nombre)
	{
		this->id = id;
		strncpy(this->nombre, nombre, 49);
		this->nombre[49] = '\0';
		this->disponible = true; // Por defecto disponible
		this->caduco = false;
		this->diasRestantes = 0;
	}
	
	size_t VerID() const;
	const char* VerNombre() const;
	void CambiarNombre(const char* NuevoNombre);
	
	// M�todos corregidos
	bool EstadoDisponibilidad() const; 
	void SetDisponible(bool d); // Nuevo m�todo necesario para PrestarLibros
	
	void CambiarEstado(bool estado); // 1 expirado, 0 no expirado
	void RestarDia(); 
	void DiasRestantes(int dias);
	
	bool operator==(const Libro& otro) const;
};
#endif
