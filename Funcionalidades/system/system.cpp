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
template<typename D> ///cambia la disponibilidad del libro o la sancion del alumno
bool System::actualizar_disponibilidad( string nombreArchivo, int id){
    fstream archi(nombreArchivo, ios::binary);
    if(!archi){
        //nada
    }else{
        throw runtime_error("abriste cualquier cosa man deaa");
    }
  
    D  aux;
	
	archi.seekg((id-1)*sizeof(D))//vamos a la posicion 

    archi.read(reinterpret_cast<char*>(&aux),sizeof(D));
    //aux.disponible(false);
    //cursor al final del libro o alumno
    //Debe volver asi escribir libro actualizado 
    
	archi.seekg((id-1)*sizeof(D))
    archi.write(reinterpret_cast<const char*>(&aux),sizeof(D));
		//aux.SetDisponible(false); para actualizar (no) disponibilidad del libro
		//aux.CambiarEstado(true); para actualizar (si) sancion del alumno
    archi.close();
	
	return true; //se realizo el cambio
}


vector<Tags> System::etiquetas(const string& path){
	///Segun el tipo un path?
	string AllTags= path;
	
	vector<Tags> resultado;
	resultado = VerContenido<Tags>(AllTags,1);
	return resultado;

}



	
	// Instanciación para Guardar
template void System::Guardar<Alumno>(string, vector<Alumno>&);
template void System::Guardar<Libro>(string, vector<Libro>&);

// Instanciación para VerContenido
template vector<Alumno> System::VerContenido<Alumno>(string, bool);
template vector<Libro> System::VerContenido<Libro>(string, bool);




