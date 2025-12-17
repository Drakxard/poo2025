#include "base.h"
#include "Libro.h"
#include "System.h"
#include "Funciones-Test.h"


int main(){
    Libro aux;
    int Nlibros= 5;
    string archiTest = "Test.bin";
    vector<Libro> resultadoTest = genLibros(Nlibros);
    System admin("Rafael",1); 
    admin.GuardarLibros(archiTest,resultadoTest);
    vector<Libro> mostrar = admin.VerLibros(archiTest);
    for(Libro &x: mostrar)
        cout<<x.VerNombre()<< x.VerID() << endl; 

    return 0;
}