#include "system.h"
#include <vector>
using namespace std;

void System::Guardar(string nombreArhivo, vector<Libro> &A_Guardar)
{
	ofstream archi(nombreArhivo, ios::binary);

	if (!archi)
		throw runtime_error("Error al guardar en " + nombreArhivo);

	Libro aux;
	for (size_t i = 0; i < A_Guardar.size(); ++i)
	{
		aux = A_Guardar[i];
		archi.write(reinterpret_cast<const char *>(&(aux)), sizeof(aux));
	}
	archi.close();
}


vector<Libro> System::VerContenido(string nombreArchivo,bool crear){
    ifstream archi(nombreArchivo,ios::binary);
    if(crear){
		//nada
	}
	else{
		if(!archi)
			throw runtime_error("Error al Recuperar Libro de " + nombreArchivo);
    }
	vector<Libro>Resultado;
    Libro aux;
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
}



vector<Tags> System::etiquetas(){

	vector<Tags> resultado;
	//resultado = VerContenido(AllTags,1);
	return resultado;

}
