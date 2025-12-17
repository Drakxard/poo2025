#include "base.h"
#include "Libro.h"
#include "System.h"
#include "Funciones-Test.h"
#include <iomanip>
using namespace std;


int main(){
	Libro aux;
	int Nlibros= 5;
	string archiTest = "Test.bin";
	vector<Libro> resultadoTest = genLibros(Nlibros);
	System admin("Rafael",1); 
	admin.GuardarLibros(archiTest,resultadoTest);
	vector<Libro> mostrar = admin.VerLibros(archiTest);
	cout<<"Entidad: "<< admin.VerNombre()<< " con ID: "<< admin.VerID()<<endl;
	for(Libro &x: mostrar)
		cout
		<<"Test: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 
	
	return 0;
}
