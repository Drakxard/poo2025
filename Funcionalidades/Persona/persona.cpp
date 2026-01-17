#include "persona.h"

using namespace std;

int Persona::VerID() const
{
	return id;
}
int Persona::VerDNI() const
{
	return DNI;
}
const char *Persona::VerNombre() const
{
	return this->nombre;
}
void Persona::CambiarNombre(const char *NuevoNombre)
{
	strncpy(this->nombre, NuevoNombre, 49);
	this->nombre[49] = '\0';
}
void Persona::Cambiar_Id(int nuevo_id){
	cin>>nuevo_id;
	this->id= nuevo_id;
}

vector<Libro> Persona::VerLibros(string nombreArchivo,bool crear){
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
