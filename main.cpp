#include "ParaMenu.h"
#include "PreConfiguracion.h"

int main(){

	///Informar quién realiza la acción
	ReconocerSolicitud(admin);
	
	///Contenido Actual
	VerContenido(resultadoTest);

{	///Test Agregar libros 
	cout<<endl<<"Preciona para continuar ";
	cin.get();
	system("cls");
	cout<<"LIbros a agregar: ";cin>>Nlibros;
	if(!Nlibros==0){
	AgregarLibros(admin,resultadoTest, archiTest, Nlibros);
	///Recarga del vector desde bin
	resultadoTest = admin.VerLibros(archiTest);
	
	system("cls");
	ReconocerSolicitud(admin);
	VerContenido(resultadoTest);
	cin.ignore();
	}
}
	
{	///Buscar libro

	cin.get();
	system("cls");
	cout<<"Buscar libro, indica ID: ";cin>>idLibro;
	BuscarLibro(admin, idLibro, resultadoTest);
}	
	
	
{	///Borrar
	cin.ignore();
	cin.get();
	system("cls");
	cout<<"ID a eliminar: ";cin>>idLibro;
	BorrarLibro(admin, resultadoTest, archiTest, idLibro);
		
	ReconocerSolicitud(admin);
	VerContenido(resultadoTest);
}	
	

	
	///Podría prestar libros: Necesitaria Usuario , a quien prestar
	
	/// Iniciar devolucion: Inciar Tramite, dar "informe" de la devolucion
	
	
	///¿?
	
	return 0;
}
	
