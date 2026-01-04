#include "ParaMenu.h"
#include "PreConfiguracion.h"

int main(){

	///Informar quién realiza la acción
	ReconocerSolicitud(admin);
	
	///Contenido Actual
	VerContenido(resultadoTest);

{	///Test Agregar libros 

	cout<<"LIbros a agregar: ";cin>>Nlibros;
	AgregarLibros(admin,resultadoTest, archiTest, Nlibros);
	///Recarga del vector desde bin
	resultadoTest = admin.VerLibros(archiTest);
	
	ReconocerSolicitud(admin);
	VerContenido(resultadoTest);
}
	
{	///Buscar libro
	cout<<endl<<"Buscar libro, indica ID: ";cin>>idLibro;
	BuscarLibro(admin, idLibro, resultadoTest);
}	
	
	
{	///Borrar
	cout<<endl<<"ID a eliminar: ";cin>>idLibro;
	BorrarLibro(admin, resultadoTest, archiTest, idLibro);

	ReconocerSolicitud(admin);
	VerContenido(resultadoTest);
}	
	

	
	///Podría prestar libros: Necesitaria Usuario , a quien prestar
	
	/// Iniciar devolucion: Inciar Tramite, dar "informe" de la devolucion
	
	
	///¿?
	
	return 0;
}
	
