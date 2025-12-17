#include "System.h"
int System::VerID()
{
	return id;
}
string System::VerNombre(){
	return nombre;
}


void System::GuardarLibros(string nombreArhivo, vector<Libro>&A_Guardar){
    ofstream archi(nombreArhivo, ios::binary);

    if(!archi)
        throw runtime_error("Error al guardar Libro en "+ nombreArhivo);
    
    Libro aux;
    for(size_t i=0; i < A_Guardar.size();++i){
        aux=A_Guardar[i];
        archi.write(reinterpret_cast<const char*>(&(aux)),sizeof(aux));
    }
    archi.close();
}

vector<Libro> System::VerLibros(string nombreArchivo){
    ifstream archi(nombreArchivo,ios::binary);
    if(!archi)
        throw runtime_error("Error al Recuperar Libro de " + nombreArchivo);
    vector<Libro>Resultado;
    Libro aux;
    while(archi.read(reinterpret_cast<char*>(&(aux)),sizeof(aux))){
        Resultado.push_back(aux);
    }
    archi.close();
    return Resultado;
}




