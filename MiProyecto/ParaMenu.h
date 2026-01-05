#ifndef PARAMENU_H
#define PARAMENU_H
///Objetos
#include "Libro.h"
#include "System.h"

///Librerias
#include "base.h"


///Funciones

void ReconocerSolicitud(System &admin);
	
void VerContenido(vector<Libro>& resultadoTest);

void AgregarLibros(System &admin, vector<Libro>&resultadoTest, string& archiTest,int Nlibros);
	
	
void BuscarLibro(System &admin, int& idLibro, vector<Libro>&resultadoTest);
		
void BorrarLibro(System &admin, vector<Libro>& resultadoTest, string& archiTest, int& idLibro);

#endif
