#include "system.h"
#include "../bibliotecario/bibliotecario.h"
#include "../Tags/Tags.h"
#include "../bloques/bloques.h"

#include <fstream>

using namespace std;
template <typename T>  ///Cambiar a Guardar al final
void System::Guardar(string nombreArhivo, vector<T> &A_Guardar)
{
	ofstream archi(nombreArhivo, ios::binary|ios::app);

	if (!archi)
		throw runtime_error("Error al guardar en " + nombreArhivo);

	T aux;
	for (size_t i = 0; i < A_Guardar.size(); ++i)
	{
		aux = A_Guardar[i];
		//cout<<endl<<"En guardar :"<<aux.VerNombre()<<endl;
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




Bloque System::VerContenido(string nombreArchivo,size_t NroBloque){
	ifstream archi(nombreArchivo,ios::binary);
	if(!archi)
		throw runtime_error("Error al Recuperar de " + nombreArchivo);

Bloque aux;
archi.seekg(sizeof(Bloque)*NroBloque);
archi.read(reinterpret_cast<char*>(&(aux)),sizeof(aux));
archi.close();
return aux;
}
void System::Guardar(string nombreArhivo, Bloque &A_Guardar, size_t Pos)
{
	fstream archi(nombreArhivo, ios::binary | ios::in | ios::out);
	
	if (!archi) {
		ofstream crear(nombreArhivo, ios::binary);
		crear.close();
		archi.open(nombreArhivo, ios::binary | ios::in | ios::out);
		
	}
	
	if (!archi)
		throw runtime_error("Error al guardar en " + nombreArhivo);
	
	archi.seekp(sizeof(Bloque) * Pos);
	archi.write(reinterpret_cast<const char *>(&(A_Guardar)), sizeof(Bloque));
	archi.close();
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
	for (size_t i = 0; i < IdARecuperar.size()-1;++i)
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

	
	if(IdARecuperar.size() != 0){
		ofstream archi(nombreArchivo, ios::binary);
		if (!archi)
			throw runtime_error("Error al Recuperar de " + nombreArchivo);
		
		T aux;
		int actual;
		bool primero = true; // Ajustar puntero, para iniciar
		for (size_t i = 0; i < IdARecuperar.size() - 1; ++i)
	{
		if (primero)
		{
			actual = IdARecuperar[i];
			primero = false;
		}
		else
		{
			actual = IdARecuperar[i + 1] - IdARecuperar[i];
		}
		aux = elementos[i];
		archi.seekp((actual) * (sizeof(T))); // vamos a la posicion
		archi.write(reinterpret_cast<const char *>(&aux), sizeof(aux));
	}
		archi.close();
	}else{
		
		Guardar<T>(nombreArchivo,elementos);
		
	}
	return true;	
};


template<typename T>
	int System::VerUltimo(string nombreArchivo){

	ifstream archi(nombreArchivo,ios::binary|ios::ate);
	if(archi.tellg()<=0){
		archi.close();
		return -1;
	}
	if(!archi)
		throw runtime_error("error al abrir para VerUltimo-> "+nombreArchivo);
	int resultado;
	int tam = static_cast<int>(sizeof(T));///Antes desfases por esto
	///Size_of convierte a size_t, el cual solo tiene positivos, por ello
	///no podiamos retroceder antes
	archi.seekg(-tam,ios::end);
	T aux;
	archi.read(reinterpret_cast<char*>(&aux),sizeof(aux));
	resultado = aux.VerID();
	cout<<endl<<"Desde VerUltimo: "<<resultado<<endl;
	archi.close();
	return resultado;
}


template<typename S >
int System::Verificar_Existencia_Vector(int dni,vector<S>&v){
	
	auto encontrar = find_if(v.begin(), v.end(), [dni](const S& x) {
		return x.VerDNI() == dni;
	});
	if(encontrar !=v.end())
		return encontrar->VerID();
	
	return -1;
}

template< typename S>
bool Verificar_Existencia_Binario(int Id,string nombreArchivo){
	//Buscar si Alumno/Bibliotecario/Libro por ID si existe
	ifstream archi(nombreArchivo, ios::binary| ios::ate);
	if(!archi)
		throw runtime_error("no se pudo abrir el archivo, "+nombreArchivo);
	
	S aux;
	archi.read(reinterpret_cast<char*>(&aux),sizeof(aux));
	if(aux.VerID()==Id){
		archi.close();
		return true;
	}
	archi.close();
	return false;
}

template <typename T> /// Cuando terminas las modificacines lo sobreescribes
bool EscribirEnBin(vector<T> &aEscribir, string nombreArchivo) {return true;};





// Instanciaci�n para Guardar
template void System::Guardar<Alumno>(string, vector<Alumno>&);
template void System::Guardar<Libro>(string, vector<Libro>&);
template void System::Guardar<Bibliotecario>(string, vector<Bibliotecario>&);
template void System::Guardar<TagUnitario>(string, vector<TagUnitario>&);


// Instanciaci�n para VerContenido
template vector<Alumno> System::VerContenido<Alumno>(string, bool);
template vector<Libro> System::VerContenido<Libro>(string, bool);
template vector<Bibliotecario> System::VerContenido<Bibliotecario>(string, bool);
template vector<int> System::VerContenido<int>(string, bool);
template vector<TagUnitario> System::VerContenido<TagUnitario>(string, bool);

// Instanciaci�n para LeerDelBin y EscribirDelBin
template vector<Alumno> System::LeerDelBin(vector<int> &IdARecuperar, string nombreArchivo);
template bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<Alumno>& elementos, string nombreArchivo);

template vector<Libro> System::LeerDelBin(vector<int> &IdARecuperar, string nombreArchivo);
template bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<Libro>&elementos, string nombreArchivo);

template vector<Tags> System::LeerDelBin(vector<int> &IdARecuperar, string nombreArchivo);
template bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<Tags>&elementos, string nombreArchivo);

template int System::Verificar_Existencia_Vector(int dni,vector<Bibliotecario>&v);
template int System::Verificar_Existencia_Vector(int dni,vector<Alumno>&v);


template int System::VerUltimo<Alumno>(string nombreArchivo);
template int System::VerUltimo<Libro>(string nombreArchivo);

template int System::VerUltimo<Bibliotecario>(string nombreArchivo);
// funcion para saltar al lugar que quieras, de libro, alumno o incluso bibl!
// vector<Registro> resultado = Saltar<Registro>(vector<int>IdARecuperar);
