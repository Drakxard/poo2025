#include "system.h"
#include <vector>
#include <fstream>
using namespace std;
template <typename T>  ///Cambiar a Guardar al final
void System::Guardar(string nombreArhivo, vector<T> &A_Guardar)
{
	ofstream archi(nombreArhivo, ios::binary|ios::ate);

	if (!archi)
		throw runtime_error("Error al guardar en " + nombreArhivo);

	T aux;
	for (size_t i = 0; i < A_Guardar.size(); ++i)
	{
		aux = A_Guardar[i];
		archi.write(reinterpret_cast<const char *>(&(aux)), sizeof(aux));
	}
	archi.close();
}

template <typename T> ///Cambiar a solo leer N cosas
vector<T> System::VerContenido(string nombreArchivo,bool crear){
    ifstream archi(nombreArchivo,ios::binary);
    if(crear){
		//nada
	}
	else{
		if(!archi)
			throw runtime_error("Error al Recuperar de " + nombreArchivo);
    }
	vector<T>Resultado;
	T aux;
    while(archi.read(reinterpret_cast<char*>(&(aux)),sizeof(aux))){
        Resultado.push_back(aux);
    }
    archi.close();
    return Resultado;
}


vector<Tags> System::etiquetas(const string& path){
	///Segun el tipo un path?
	string AllTags= path;
	
	vector<Tags> resultado;
	resultado = VerContenido<Tags>(AllTags,1);
	return resultado;

}

template <typename T>
vector<T> System::LeerDelBin(vector<int> &IdARecuperar, string nombreArchivo)
{   //3 4 7 8 9

	ifstream archi(nombreArchivo, ios::binary);
	if (!archi)
		throw runtime_error("Error al Recuperar de " + nombreArchivo);


	T aux;
	vector<T>resultado;
	int actual;
	bool primero=true; //Ajustar puntero, para iniciar 
	for (int i = 0; i < IdARecuperar.size()-1;++i)
	{
		//Está ordenado, logica para 2 -> n (seguir pensando)
		//  2 4 6 8
		//primero -> 0 + primerID, hacer,
		// 4 - 2 = 2, cursor en 2 -> 4, saltar 2 lugares
		//6 -4 = 2, cursor en 4 -> 6, saltar 2 lugares
		// 8 - 6 = 2, cursor en 6 -> 8, saltar 2 lugares 
		if(primero){
			actual = IdARecuperar[i];
			primero = false;
		}else{
		actual = IdARecuperar[i + 1] - IdARecuperar[i];
		}
		archi.seekg((actual) * (sizeof(T))); // vamos a la posicion
		archi.read(reinterpret_cast<char*>(&aux), sizeof(aux));
		resultado.push_back(aux);
	}
	return resultado;
};

template <typename T>
bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<T>&elementos, string nombreArchivo)
{ 	// 3 4 7 8 9

	ofstream archi(nombreArchivo, ios::binary);
	if (!archi)
		throw runtime_error("Error al Recuperar de " + nombreArchivo);

	T aux;
	vector<T> resultado;
	int actual;
	bool primero = true; // Ajustar puntero, para iniciar
	for (int i = 0; i < IdARecuperar.size() - 1; ++i)
	{
		// Está ordenado, logica para 2 -> n (seguir pensando)
		//   2 4 6 8
		// primero -> 0 + primerID, hacer,
		//  4 - 2 = 2, cursor en 2 -> 4, saltar 2 lugares
		// 6 -4 = 2, cursor en 4 -> 6, saltar 2 lugares
		//  8 - 6 = 2, cursor en 6 -> 8, saltar 2 lugares
		if (primero)
		{
			actual = IdARecuperar[i];
			primero = false;
		}
		else
		{
			actual = IdARecuperar[i + 1] - IdARecuperar[i];
		}
		archi.seekg((actual) * (sizeof(T))); // vamos a la posicion
		archi.write(reinterpret_cast<const char *>(&aux), sizeof(aux));
		resultado.push_back(aux);
	}
	return true;	
};

template <typename T> /// Cuando terminas las modificacines lo sobreescribes
bool EscribirEnBin(vector<T> &aEscribir, string nombreArchivo) {};

// Instanciaci�n para Guardar
template void System::Guardar<Alumno>(string, vector<Alumno>&);
template void System::Guardar<Libro>(string, vector<Libro>&);



// Instanciaci�n para VerContenido
template vector<Alumno> System::VerContenido<Alumno>(string, bool);
template vector<Libro> System::VerContenido<Libro>(string, bool);

// Instanciaci�n para LeerDelBin y EscribirDelBin
template vector<Alumno> System::LeerDelBin(vector<int> &IdARecuperar, string nombreArchivo);
template bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<Alumno>& elementos, string nombreArchivo);

template vector<Libro> System::LeerDelBin(vector<int> &IdARecuperar, string nombreArchivo);
template bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<Libro>&elementos, string nombreArchivo);

// funcion para saltar al lugar que quieras, de libro, alumno o incluso bibl!
// vector<Registro> resultado = Saltar<Registro>(vector<int>IdARecuperar);
