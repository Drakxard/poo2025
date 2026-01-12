#ifndef SYSTEM_H  // 1. Si no est� definido PERSONA_H
#define SYSTEM_H
#include <fstream>
#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../alumno/alumno.h"
using namespace std;
//template<typename K>
struct Tags{
	string nombre,path;
};
class System{

	int UltimoIdLibro;
	int UltimoIdAlumno;
	int UltimoIdBibliocario;
	
	///De libro
	string prestados = "Recursos/binarios/prestados.bin";
	string matematica = "Recursos/binarios/matematica.bin";
	string poo = "Recursos/binarios/poo.bin";
	string fisica = "Recursos/binarios/fisica.bin";
	///N-tags
public:
    System(){};
	template<typename T>
	void Guardar(string nombreArhivo, vector<T> &A_Guardar);
	//Falta codear Eliminar, tempalte
	template<typename T>
    vector<T> VerContenido(string nombreArchivo,bool crear);
	vector<Tags> etiquetas(const string& path);
	bool actualizar_disponibilidad( string nombreArchivo, int id);
	
	int VerUltimoIdLibro(){return UltimoIdLibro;}
	void SumarUltimoIdLibro() { UltimoIdLibro++;}
	int VerUltimoIdAlumno(){return UltimoIdAlumno;}
	void SumarUltimoIdAlumno() { UltimoIdAlumno++;}
	int VerUltimoIdBibliotecario() { return UltimoIdBibliocario; }
	void SumarUltimoIdBibliotecario() { UltimoIdBibliocario++; }
};


#endif // 3. Fin de la condici�n
