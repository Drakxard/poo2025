#include "Persistencia.h"
#include <fstream>
#include <iostream> // Para cerr

using namespace std;

Persistencia::Persistencia() {
	
	string path = "./Recursos/Binarios/persistencia.bin";
	ifstream archi(path, ios::binary);
	
	if(!archi){
		this->UltimaDireccion = 0;
		this->CantidadTags = 0;
	}
	else {
		Persistencia aux;
		archi.read(reinterpret_cast<char*>(&aux), sizeof(aux));
		
		
		
		this->UltimaDireccion = aux.VerUltimaDireccion();
		this->CantidadTags = aux.VerCantidadTags();
		
		archi.close();
	}
}

Persistencia::~Persistencia(){

	string path = "./Recursos/Binarios/persistencia.bin";
	
	ofstream archi(path, ios::binary);
	if(!archi){
		cerr << "Error al escribir la persistencia en " << path << endl;
	} else {
		archi.write(reinterpret_cast<const char*>(this), sizeof(Persistencia));
		archi.close();  
	}
}
