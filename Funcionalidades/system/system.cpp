#include "system.h"
#include <vector>
using namespace std;
template <typename T>
void System::Guardar(string nombreArhivo, vector<T> &A_Guardar)
{
	ofstream archi(nombreArhivo, ios::binary);

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

template <typename T>
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

bool System::actualizar_disponibilidad( string nombreArchivo, int id){
    fstream archi(nombreArchivo, ios::binary);
    if(!archi){
        //nada
    }else{
        throw runtime_error("abriste cualquier cosa man deaa");
    }
  
    
   
    //cambiar el bool de Disponibilidad
    //Cambiar estado del libro en el binario 
   // archi.seekg((id-1)*sizeof(libro))//vamos a la posicion del libro
    Libro  aux;

    archi.read(reinterpret_cast<char*>(&aux),sizeof(aux));
    //aux.disponible(false);
    
    //cursor al final del libro
    //Debe volver asi escribir libro actualizado 
    //archi.seekg((id-1)*sizeof(libro))
    archi.write(reinterpret_cast<const char*>(&aux),sizeof(aux));
   // aux.Disponible(false);
    archi.close();
	return true;
}


template <typename T>
vector<T> System::etiquetas(const string& path){
	///Segun el tipo un path?
	string AllTags= path;
	
	vector<T> resultado;
	resultado = VerContenido<T>(AllTags,1);
	return resultado;

}



	
	// Instanciación para Guardar
template void System::Guardar<Alumno>(string, vector<Alumno>&);
template void System::Guardar<Libro>(string, vector<Libro>&);

// Instanciación para VerContenido
template vector<Alumno> System::VerContenido<Alumno>(string, bool);
template vector<Libro> System::VerContenido<Libro>(string, bool);


// Instanciación para Etiquetas
template vector<Alumno> System::etiquetas<Alumno>(const string& path);
template vector<Libro> System::etiquetas<Libro>(const string& path);


