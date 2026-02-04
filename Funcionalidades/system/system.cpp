#include "system.h"
#include "../bibliotecario/bibliotecario.h"
#include "../Bloques/Bloques.h"

#include <fstream>

#include <cstring>
using namespace std;
template <typename T>  ///Cambiar a Guardar al final
bool System::Guardar(string nombreArhivo, vector<T> &A_Guardar, bool sobreEscribir)
{
	ofstream archi;
		if(sobreEscribir){
			archi.open(nombreArhivo, ios::binary);
		}else{
			archi.open(nombreArhivo, ios::binary|ios::app);
		}
	if (!archi){
	cerr<<"Error al guardar en " + nombreArhivo;
	return false;
	}

	for (size_t i = 0; i < A_Guardar.size(); ++i)
	{
	//cout<<endl<<"En guardar :"<<aux.VerNombre()<<endl;
	archi.write(reinterpret_cast<const char *>(&(A_Guardar[i])), sizeof(A_Guardar[i]));
	}
	archi.close();
	return true;
}



template <typename T>
bool System::Eliminar(size_t id, vector<T>&v){
	typename vector<T>::iterator itBorrar = find_if(v.begin(),v.end(),[id](const T& a){
	return a.VerID() == id;
	});
	if(itBorrar!=v.end()){
	v.erase(itBorrar);
	return true;//borrado
	}else{
	return false;//no se encontro xD
	}
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
bool System::Guardar(string nombreArhivo, Bloque &A_Guardar, size_t Pos)
	{
	fstream archi(nombreArhivo, ios::binary | ios::in | ios::out);

	if (!archi) {
	ofstream crear(nombreArhivo, ios::binary);
	crear.close();
	archi.open(nombreArhivo, ios::binary | ios::in | ios::out);

	}

	if (!archi){
	cerr<<"Error al guardar en " + nombreArhivo;
	return false;
	}
	archi.seekp(sizeof(Bloque) * Pos);
	archi.write(reinterpret_cast<const char *>(&(A_Guardar)), sizeof(Bloque));
	archi.close();
	return true;
}




template <typename T>
vector<T> System::LeerDelBin(vector<size_t> &IdARecuperar, string nombreArchivo)
{  
	ifstream archi(nombreArchivo, ios::binary);
	if (!archi)
	throw runtime_error("Error al Recuperar de " + nombreArchivo);


	T aux;
	vector<T>resultado;
	int ultimo= VerUltimo<T>(nombreArchivo);
	for (size_t i = 0; i < IdARecuperar.size();++i)
	{
	if(IdARecuperar[i]>= 0 and IdARecuperar[i]<= ultimo){
	archi.seekg((IdARecuperar[i]) * (sizeof(T))); // vamos a la posicion
	archi.read(reinterpret_cast<char*>(&aux), sizeof(aux));
	resultado.push_back(aux);
	}
	}
	return resultado;
};

template <typename T>
bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<T>&elementos, string nombreArchivo)
{ 
	if(IdARecuperar.size() != 0){
	ofstream archi(nombreArchivo, ios::binary);
	if (!archi)
		throw runtime_error("Error al Recuperar de " + nombreArchivo);

	T aux;
	for (size_t i = 0; i < IdARecuperar.size(); ++i)
	{
			archi.seekp((IdARecuperar[i]) * (sizeof(T))); // vamos a la posicion
			archi.write(reinterpret_cast<const char *>(&aux), sizeof(aux));
	} 
	archi.close();    
	}else{
	return false;
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
	archi.close();
	return resultado;
}

vector<Cabecera> System::CargarDesdeTxt(string nombreArchivo){
ifstream archi(nombreArchivo);
if(!archi)
    throw runtime_error("Error al leer "+nombreArchivo);

vector<Cabecera>resultado;
string nombre,path;
Cabecera aux;
while((getline(archi,nombre)) and (getline(archi,path))){
    strncpy(aux.nombre,nombre.c_str(),49);
    aux.nombre[49] = '\0';
    
    strncpy(aux.path,path.c_str(),49);
    aux.path[49] = '\0';
    resultado.push_back(aux);
}
archi.close();
return resultado;
}

template<typename S >
int System::Verificar_Existencia_Vector(int dni,vector<S>&v){
	
	auto encontrar = find_if(v.begin(), v.end(), [dni](const S& x) {
		return x.VerDNI() == dni;
	});
	if(encontrar !=v.end())
		return (encontrar-v.begin());
	
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

// Instanciaci?n para Guardar
template bool System::Guardar<Alumno>(string, vector<Alumno>&, bool sobreEscribir);
template bool System::Guardar<Libro>(string, vector<Libro>&, bool sobreEscribir);
template bool System::Guardar<Bibliotecario>(string, vector<Bibliotecario>&, bool sobreEscribir);
template bool System::Guardar<Tags>(string, vector<Tags>&, bool sobreEscribir);
template bool System::Guardar<Persistencia>(string, vector<Persistencia>&, bool sobreEscribir);




// Instanciaci?n para VerContenido
template vector<Alumno> System::VerContenido<Alumno>(string, bool);
template vector<Libro> System::VerContenido<Libro>(string, bool);
template vector<Bibliotecario> System::VerContenido<Bibliotecario>(string, bool);
template vector<int> System::VerContenido<int>(string, bool);
template vector<Tags> System::VerContenido<Tags>(string, bool);
template vector<Persistencia> System::VerContenido<Persistencia>(string, bool);

// Instanciaci?n para LeerDelBin y EscribirDelBin
template vector<Alumno> System::LeerDelBin(vector<size_t> &IdARecuperar, string nombreArchivo);
template bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<Alumno>& elementos, string nombreArchivo);

template vector<Libro> System::LeerDelBin(vector<size_t> &IdARecuperar, string nombreArchivo);
template bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<Libro>&elementos, string nombreArchivo);

template vector<Tags> System::LeerDelBin(vector<size_t> &IdARecuperar, string nombreArchivo);
template bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<Tags>&elementos, string nombreArchivo);

template int System::Verificar_Existencia_Vector(int dni,vector<Bibliotecario>&v);
template int System::Verificar_Existencia_Vector(int dni,vector<Alumno>&v);


template int System::VerUltimo<Alumno>(string nombreArchivo);
template int System::VerUltimo<Libro>(string nombreArchivo);
template int System::VerUltimo<Bibliotecario>(string nombreArchivo);


template bool System:: Eliminar<Alumno>(size_t id, vector<Alumno>&v);
template bool System:: Eliminar<Bibliotecario>(size_t id, vector<Bibliotecario>&v);

// funcion para saltar al lugar que quieras, de libro, alumno o incluso bibl!
// vector<Registro> resultado = Saltar<Registro>(vector<int>IdARecuperar);

