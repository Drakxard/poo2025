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

vector<Libro> System::VerLibros(string nombreArchivo,bool crear){
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

void System::AgregarLibros(int LibrosAgregar,vector<Libro>&resultadoTest){
	
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
	void System:: EliminarLibro(Libro Eliminar,vector<Libro>&resultadoTest){
	vector<Libro>::iterator it = remove(resultadoTest.begin(),
										resultadoTest.end(),Eliminar);
	resultadoTest.erase(it);
	
	}


vector<Libro>::const_iterator System::BuscarLibro(int idLibro,const vector<Libro> &v){
	vector<Libro>::const_iterator it = find_if(v.begin(),v.end(),[idLibro](const Libro a){
		return a.VerID() == idLibro;});
	if (it != v.end()) {
		return it; 
	} else {
		return v.end(); 
	}
	
}



