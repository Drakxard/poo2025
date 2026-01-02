#include "base.h"
#include "Libro.h"
#include "System.h"
#include "Funciones-Test.h"
#include <iomanip>
using namespace std;
///Por hacer
///Linea 58, funcion y usar en 63, luego prestar libros, agregar eso
int main(){
	///Se crea una Entidad del Sistema, de nombre admin
	System admin("Rafael",1); 
	
	///Inicializa un nombre de binario de Test
	string archiTest = "Test.bin";
	
	///Simulamos un vector de Libros Lleno
	vector<Libro> resultadoTest = admin.VerLibros(archiTest);	
	
	
	
	
	
	///Admin puede ver los cambios realizados o antes de cambiarlos
	vector<Libro> mostrar = admin.VerLibros(archiTest);
	
	///Salida por terminal simulada de una posible interaccion en la
	///IU, Mostrar quien realizo algo, vector como tal
	cout<<"Entidad: "<< admin.VerNombre()<< " con ID: "<< admin.VerID()<<endl;
	for(Libro &x: mostrar)
		cout
		<<"Nombre Libro: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 
	
	
	///Podria, agregar libros a este vector  
	///guardarlo posteriormente
	int LibrosAgregar=0;
	cout<<"LIbros a agregar: ";cin>>LibrosAgregar;
	admin.AgregarLibros(LibrosAgregar,resultadoTest);
	
	admin.GuardarLibros(archiTest,resultadoTest);
	///Se guardar en bin indicado (el inincial)

	mostrar = admin.VerLibros(archiTest);
	
	
	///Salida por terminal simulada de una posible interaccion en la
	///IU, Mostrar quien realizo algo, vector como tal
	cout<<"Entidad: "<< admin.VerNombre()<< " con ID: "<< admin.VerID()<<endl;
	for(Libro &x: mostrar)
		cout
		<<"Nombre Libro: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 	
	
	
	///¿Buscar libros?
	 
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
	
	
	
	///Podría prestar libros: Necesitaria Usuario , a quien prestar
	
	/// Iniciar devolucion: Inciar Tramite, dar "informe" de la devolucion
	
	
	///¿?
	
	return 0;
}
	
