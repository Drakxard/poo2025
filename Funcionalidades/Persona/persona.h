
#include <cstring>
using namespace std;

class Persona{
    int id;
    char nombre[49]; 
    public:
        Persona(int id, const char *nombre){
                this->id = id;
                strncpy(this->nombre, nombre, 49);
                this->nombre[49] = '\0';
        }
        int VerID() const;
        const char *VerNombre() const;
        void CambiarNombre(const char *NuevoNombre);
        vector<Libro> VerLibros(string nombreArchivo,bool crear=false);
};
