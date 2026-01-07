#ifndef LIBRO_H
#define LIBRO_H
#include <cstring>
using namespace std;
class Libro
{
    int id;
    char nombre[50];
    int diasRestantes;
	bool disponible=true;
    bool caduco;
public:
    Libro()
    {
        id = -1;
    };
    Libro(int id, const char* nombre)
    {
        this->id = id;
		strncpy(this->nombre, nombre, 49);
		this->nombre[49] = '\0';
    }
    int VerID() const;
	const char* VerNombre() const;
    void CambiarNombre(const char* NuevoNombre);
    bool EstadoDisponibilidad();
	void CambiarEstado(bool estado); //1 expirado, 0 no expirado, 
    void RestarDia(); //Se avanzo otro día y cambia estado
    void DiasRestantes(int dias);
	
	bool operator==(const Libro& otro) const ;
};
#endif
