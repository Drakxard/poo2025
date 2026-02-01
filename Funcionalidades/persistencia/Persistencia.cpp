#include "Persistencia.h"
#include <fstream>
#include <iostream> // Para cerr
#include "../system/system.h"

using namespace std;

Persistencia::Persistencia() {
	this->UltimaDireccion = 0;
	this->CantidadTags = 0;
}

void Persistencia::CargarDatos(){
	System sistema;
	string path = "./Recursos/Binarios/persistencia.bin";
	vector<Persistencia> resultado = sistema.VerContenido<Persistencia>(path,true);
	cout<<endl<<"Tam de datos Persistencia, Creando con "<<resultado.size()<<endl;
	if(resultado.size()==0){
		this->UltimaDireccion = 0;
		this->CantidadTags = 0;
	}
	else {
		this->UltimaDireccion = resultado[0].VerUltimaDireccion();
		this->CantidadTags = resultado[0].VerCantidadTags();
	}
}

void Persistencia::GuardarCambios(){
	System sistema;
	string path = "./Recursos/Binarios/persistencia.bin";
	vector<Persistencia> resultado;
	Persistencia aux= *this;
	resultado.push_back(aux);
	sistema.Guardar<Persistencia>(path,resultado,true);
}

Persistencia::~Persistencia(){
	

}
