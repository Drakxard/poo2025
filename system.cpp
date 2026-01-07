#include "Bibliotecario.h"
using namespace std;
int Bibliotecario::VerID()
{
	return id;
}
string Bibliotecario::VerNombre(){
	return nombre;
}


void Bibliotecario::GuardarLibros(string nombreArhivo, vector<Libro>&A_Guardar){
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

vector<Libro> Bibliotecario::VerLibros(string nombreArchivo,bool crear){
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

void Bibliotecario::AgregarLibros(int LibrosAgregar,vector<Libro>&resultadoTest){
	
	string nombreLibro="";
	int idLibro=0;
	while(LibrosAgregar>0){
		
		cout<<"Nombre del libro: ";cin>>nombreLibro;
		
		///Generar ID
		int size= resultadoTest.size(); 
		if(size>0)
			idLibro = (resultadoTest[size-1].VerID()) + 1;
		
		Libro aux(idLibro,nombreLibro.c_str());
		resultadoTest.push_back(aux);
		--LibrosAgregar;
	}
}

void Bibliotecario::EliminarLibro(vector<Libro>::const_iterator Eliminar,vector<Libro>&v){
	v.erase(Eliminar);
}


vector<Libro>::const_iterator Bibliotecario::BuscarLibro(int idLibro,const vector<Libro> &v){
	vector<Libro>::const_iterator it = find_if(v.begin(),v.end(),[idLibro](const Libro a){
		return a.VerID() == idLibro;});
	if (it != v.end()) {
		return it; 
	} else {
		return v.end(); 
	}
	
}


	bool Bibliotecario::PrestarLibros(int idLibro, vector<libro>& v,int cantDiasPrestar) {
		auto it = find(v.begin(), v.end(), idLibro);
		
		// 1. Verificar si existe
		if (it != v.end()) {
			if(EstadoDisponibilidad()){
				it->disponible = false; //fue prestado
				bool estado=false;
				it->CambiarEstado(bool estado);
				int dias= 
				return true; // �xito
			}else{
				return false; // ya fue prestado
			}
		}
		return false; // No se encontr� el libro
	}
	







