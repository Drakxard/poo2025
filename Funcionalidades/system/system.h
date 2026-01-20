#ifndef SYSTEM_H  // 1. Si no est? definido PERSONA_H
#define SYSTEM_H
#include "../preConfiguracion/preConfiguracion.h"
#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../Tags/tags.h"


#include <vector>
using namespace std;
//template<typename K>

class System{
	string pathalumnos ="../../Recursos/Binarios/alumnos.bin";
	
	
public:
	System(){};
	template<typename T>
	void Guardar(string nombreArhivo, vector<T> &A_Guardar);
	//Falta codear Eliminar, tempalte
	vector<Tags> etiquetas(const string& path);
	bool actualizar_disponibilidad( string nombreArchivo, int id);
	
	template<typename S>
	void EliminarLibro(vector<S>::const_iterator Eliminar,vector<S>&v);
	template<typename S>
	int Verificar_Existencia_Vector(int dni, vector<S>&v);
	template<typename S>
	bool Verificar_Existencia_Binario(int Id,string nombreArchivo);
	
	/// Cambiar a solo leer N cosas
	template <typename T>
	int VerUltimo(string nombreArchivo);
	template <typename T> 
	vector<T> VerContenido(string nombreArchivo, bool crear);
	template <typename T>
	vector<T> LeerDelBin(vector<int> &IdARecuperar, string nombreArchivo);
	template <typename T>
	bool EscribirEnBin(vector<int> &IdARecuperar, vector<T>&elementos, string nombreArchivo);
	string alumnos(){return pathalumnos;}


	
};


#endif // 3. Fin de la condici?n
