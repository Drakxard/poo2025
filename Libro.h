#include "base.cpp"
class Libro
{
    int id;
    string nombre;
    int diasRestantes;
    bool caduco;
public:
    Libro()
    {
        id = -1;
    };
    Libro(int id, string nombre)
    {
        this->id = id;
        this->nombre = nombre;
    }
    void CambiarNombre(string NuevoNombre);
    void CambiarEstado(bool estado); //1 expirado, 0 no expirado, 
    void RestarDia(); //Se avanzo otro día y cambia estado
    void DiasRestantes(int dias);
};