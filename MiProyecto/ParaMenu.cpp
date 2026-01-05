#include "ParaMenu.h"

void ReconocerSolicitud(System &admin){
	cout<<"Entidad: "<< admin.VerNombre()<< " con ID: "<< admin.VerID()<<endl;
}
	
	
void VerContenido(vector<Libro>& resultadoTest){
	for(Libro &x: resultadoTest)
		cout
		<<"Nombre Libro: " 	<<x.VerNombre()
		<<"  Id: "	<<x.VerID()
		<<endl; 
}
void AgregarLibros(System &admin, vector<Libro>&resultadoTest, string& archiTest,int Nlibros){
	
	admin.AgregarLibros(Nlibros,resultadoTest);	
	admin.GuardarLibros(archiTest,resultadoTest);
	
}
	
	
void BuscarLibro(System &admin, int& idLibro, vector<Libro>&resultadoTest){
	vector<Libro>::const_iterator it = admin.BuscarLibro(idLibro,resultadoTest);
	
	cout<<"Libro: "<<endl
		<<"Nombre: "<<(*(it)).VerNombre()
		<<endl 
		<<"ID: "<<(*(it)).VerID()
		<<endl;
	
}
		
		
void BorrarLibro(System &admin, vector<Libro>& resultadoTest, string& archiTest, int& idLibro){
	
	vector<Libro>::const_iterator itBorrar = admin.BuscarLibro(idLibro,resultadoTest);
	admin.EliminarLibro(itBorrar,resultadoTest);
	admin.GuardarLibros(archiTest,resultadoTest);
	
	
}
