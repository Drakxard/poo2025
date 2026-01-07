#include "Bibliotecario.h"
#include <ctime>
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


// En bibliotecario.cpp

// Asegúrate de que libro.h tenga acceso a sus atributos o métodos setter adecuados
bool Bibliotecario::PrestarLibros(int idLibro, vector<Libro>& v, int cantDiasPrestar) {
	// Buscar el libro
	auto it = find_if(v.begin(), v.end(), [idLibro](const Libro& a) {
		return a.VerID() == idLibro;
	});
	
	// 1. Verificar si existe
	if (it != v.end()) {
		// NOTA: EstadoDisponibilidad() devuelve un bool, úsalo en el if.
		// Además, verifica que la lógica en libro.cpp esté correcta (actualmente no retorna valor en tu archivo).
		
		/* Corrección: Asumiendo que EstadoDisponibilidad verifica si está libre */
		// Necesitas un método público para ver si es true, ya que 'disponible' es privado en tu Libro.h
		
		// Asumimos lógica: Si el libro NO tiene diasRestantes o una flag de disponible
		bool estaDisponible = true; // Aquí deberías llamar a it->EsDisponible() o similar
		
		if (estaDisponible) { 
			// ERROR ORIGINAL: it->disponible = false; (Esto es privado en Libro.h, usa un setter)
			// ERROR ORIGINAL: it->CambiarEstado(bool estado); (Sintaxis incorrecta)
			
			it->CambiarEstado(false); // Marcar como no disponible / prestado
			
			// AQUÍ ESTÁ LO QUE PEDISTE: Cargar los días
			// Si 'cantDiasPrestar' ya es el número de días, solo asígnalo:
			it->DiasRestantes(cantDiasPrestar);
			
			// SI quisieras calcularlo basado en una fecha objetivo (ej. 20/12/2025):
			// int diasCalculados = CalcularDiferenciaDias(20, 12, 2025);
			// it->DiasRestantes(diasCalculados);
			
			return true; // Éxito
		} else {
			return false; // Ya fue prestado
		}
	}
	return false; // No se encontró el libro
}
	







