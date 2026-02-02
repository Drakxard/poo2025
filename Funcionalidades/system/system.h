#ifndef SYSTEM_H  // 1. Si no est? definido PERSONA_H
#define SYSTEM_H
#include "../preConfiguracion/preConfiguracion.h"
#include "../libro/libro.h"
#include "../alumno/alumno.h"



using namespace std;
//template<typename K>

struct Cabecera{
	char nombre[50], path[50];
};
struct Tags;
struct Bloque;
class System{
	string pathalumnos ="../../Recursos/Binarios/alumnos.bin";
	
	
public:
	System(){};
	template<typename T>
	bool Guardar(string nombreArhivo, vector<T> &A_Guardar, bool sobreEscribir=false);
	
	bool Guardar(string nombreArhivo, Bloque &A_Guardar, size_t Pos);
	//Falta codear Eliminar, tempalte
	template<typename T>
	bool Eliminar(size_t id, vector<T>&v);
	vector<Tags> etiquetas(const string& path);
	bool actualizar_disponibilidad( string nombreArchivo, int id);
	
	/// Cambiar a solo leer N cosas
	template <typename T>
	int VerUltimo(string nombreArchivo);
	template <typename T> 
	vector<T> VerContenido(string nombreArchivo, bool crear);
	Bloque VerContenido(string nombreArchivo,size_t NroBloque);
	template <typename T>
	vector<T> LeerDelBin(vector<size_t> &IdARecuperar, string nombreArchivo);
	template <typename T>
	bool EscribirEnBin(vector<int> &IdARecuperar, vector<T>&elementos, string nombreArchivo);
	string alumnos(){return pathalumnos;}
	
	template<typename S>
		int Verificar_Existencia_Vector(int dni, vector<S>&v);
	template<typename S>
	bool Verificar_Existencia_Binario(int Id,string nombreArchivo);
	
	
	
	///Cabeceras para libros
	vector<Cabecera> CargarDesdeTxt(string nombreArchivo);
	
};


#endif // 3. Fin de la condici?n
