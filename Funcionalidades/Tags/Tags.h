#ifndef TAGS_H
#define TAGS_H
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Tag{
	int IdTag;
	string NombreTag;
	int InicioBloque;
};

struct Bloque{
	int CantidadElementos;
	int SiguienteBloque;
	int Elementos[1022];
};
class Tags {
	size_t TamBloque= 4096;
	int UltimaDireccion = 0;
	int CantidadTags=0;
	string allTags= "Recursos/Binarios/Tags/tags_data.bin";
	
public:
	Tags(){};
	void AgregarNuevoTag(string NombreTag);
	vector<int>LeerTodosLosElementos(int IdTag);
	///Usar Como en AgregarNuevoElemento, VerContenido Actualizado
	/// o Sobrecargado para bloques
	bool AgregarNuevoElemento(int IdTag, int idLibro);
	///VerContenido<Bloque>, me da todo el bloque
	///Pero deberia ser el bloque correcto, 
	///por ende no todo el archivo sino basado en id, asi seek y Leer
	///Luego de tener el bloque ponerlo en vector, 
	///Push_back, x1 elemento
	///volver una posicion
	///Y escribir el bloque actualizado
	///Return true al final, llego bien
	
	int CantTags(){return CantidadTags;}
};

#endif

