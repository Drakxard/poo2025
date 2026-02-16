#ifndef SYSTEM_H  // 1. Si no est? definido PERSONA_H
#define SYSTEM_H
#include "../preConfiguracion/preConfiguracion.h"

#include <fstream>
#include <cstring>
class Libro;
class Alumno;
class Bibliotecario;
class Bloque;

using namespace std;
//template<typename K>

struct Cabecera{
	char nombre[50], path[50];
};
struct Libros_en_Prestamo
{
	size_t id_Libro,id_Prestamo,id_Alumno,dia_Devolucion,mes_Devolucion,anio_Devolucion;
};

struct Tags;
struct Bloque;
class System{
	string pathalumnos ="Recursos/Binarios/alumnos.bin";
	string pathprestamos ="Recursos/Binarios/LibrosPrestamosActivos.bin";
	string pathlibros = "Recursos/Binarios/libros.bin";
	string pathbibliotecarios = "Recursos/Binarios/bibliotecarios.bin";
	
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
	string libros(){return pathlibros;}
	string bibliotecarios(){return pathbibliotecarios;}
	
	template<typename S>
		int Verificar_Existencia_Vector(int dni, vector<S>&v);
	template<typename S>
	bool Verificar_Existencia_Binario(int Id,string nombreArchivo);
	
	///Cabeceras para libros
	vector<Cabecera> CargarDesdeTxt(string nombreArchivo);
	
};

#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../bibliotecario/bibliotecario.h"
#include "../Bloques/Bloques.h"





template <typename T>  ///Cambiar a Guardar al final
bool System::Guardar(string nombreArhivo, vector<T> &A_Guardar, bool sobreEscribir){
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






template <typename T>
vector<T> System::LeerDelBin(vector<size_t> &IdARecuperar, string nombreArchivo){  
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
bool System::EscribirEnBin(vector<int> &IdARecuperar, vector<T>&elementos, string nombreArchivo){ 
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



#endif // 3. Fin de la condici?n
