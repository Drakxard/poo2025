#include "Persistencia.h"
#include <fstream>
using namespace std;


Persistencia::Persistencia() {
	string path = "./Recursos/Binarios/persistencia.bin";
	ifstream archi(path,ios::binary);
	
	if(!archi){
		throw runtime_error("Error al leer la persistencia "+path);
	}
	Persistencia aux;
	archi.read(reinterpret_cast<char*>(&aux),sizeof(aux));
	*this=aux;
	archi.close();
	
}

Persistencia::~Persistencia(){
	string path = "./Recursos/Binarios/Cargapersistencia.bin";
	ofstream archi(path,ios::binary);
	if(!archi){
		throw runtime_error("Error al escribir la persistencia "+path);
	}
	archi.write(reinterpret_cast<const char*>(this),sizeof(Persistencia));
	archi.close();	
}
