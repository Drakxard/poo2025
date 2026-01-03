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
	 /*
	///Eliminar
	int idLibro;
	cout<<"Eliminar libro: ";cin>>idLibro;
	//Libro Eliminar = admin.Buscar(idLibro);
	Libro Eliminar;
	admin.EliminarLibro(Eliminar,resultadoTest);
	
	admin.GuardarLibros(archiTest,resultadoTest);
	
	mostrar= admin.VerLibros(archiTest);
	
	///Salida por terminal simulada de una posible interaccion en la
	///IU, Mostrar quien realizo algo, vector como tal
	cout<<"Entidad: "<< admin.VerNombre()<< " con ID: "<< admin.VerID()<<endl;
	for(Libro &x: mostrar)
		cout
		<<"Nombre Libro: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 
	
	*/
	
	///Podría prestar libros: Necesitaria Usuario , a quien prestar
	
	/// Iniciar devolucion: Inciar Tramite, dar "informe" de la devolucion
	
	
	///¿?
	
	return 0;
}
	
