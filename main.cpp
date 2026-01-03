#include "base.h"
#include "Libro.h"
#include "System.h"
#include "Funciones-Test.h"
#include <iomanip>
using namespace std;

int main(){
	
	System admin("Rafael",1); 
	
	string archiTest = "Test.bin";
	
	vector<Libro> resultadoTest = admin.VerLibros(archiTest,1);	
	
	
	cout<<"Entidad: "<< admin.VerNombre()<< " con ID: "<< admin.VerID()<<endl;
	for(Libro &x: resultadoTest)
		cout
		<<"Nombre Libro: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 
	
	
	int LibrosAgregar=0;
	cout<<"LIbros a agregar: ";cin>>LibrosAgregar;
	admin.AgregarLibros(LibrosAgregar,resultadoTest);
	
	admin.GuardarLibros(archiTest,resultadoTest);
	resultadoTest = admin.VerLibros(archiTest);
	
	cout<<"Entidad: "<< admin.VerNombre()<< " con ID: "<< admin.VerID()<<endl;
	for(Libro &x: resultadoTest)
		cout
		<<"Nombre Libro: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 	
	
	
	///¿Buscar libros?
	int idLibro;
	cout<<endl<<"Buscar libro, indica ID: ";cin>>idLibro;
	
	vector<Libro>::const_iterator it = admin.BuscarLibro(idLibro,resultadoTest);
	
	cout<<"Libro: "<<endl;
	
	
	
	
	
	///Podría prestar libros: Necesitaria Usuario , a quien prestar
	
	/// Iniciar devolucion: Inciar Tramite, dar "informe" de la devolucion
	
	
	///¿?
	
	return 0;
}
	
