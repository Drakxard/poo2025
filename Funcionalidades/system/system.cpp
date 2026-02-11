#include "system.h"
using namespace std;
Bloque System::VerContenido(string nombreArchivo,size_t NroBloque){
	ifstream archi(nombreArchivo,ios::binary);
	if(!archi)
		throw runtime_error("Error al Recuperar de " + nombreArchivo);
	
	Bloque aux;
	archi.seekg(sizeof(Bloque)*NroBloque);
	archi.read(reinterpret_cast<char*>(&(aux)),sizeof(aux));
	archi.close();
	return aux;
}
bool System::Guardar(string nombreArhivo, Bloque &A_Guardar, size_t Pos)
{
	fstream archi(nombreArhivo, ios::binary | ios::in | ios::out);
	
	if (!archi) {
		ofstream crear(nombreArhivo, ios::binary);
		crear.close();
		archi.open(nombreArhivo, ios::binary | ios::in | ios::out);
		
	}
	
	if (!archi){
		cerr<<"Error al guardar en " + nombreArhivo;
		return false;
	}
	archi.seekp(sizeof(Bloque) * Pos);
	archi.write(reinterpret_cast<const char *>(&(A_Guardar)), sizeof(Bloque));
	archi.close();
	return true;
}


vector<Cabecera> System::CargarDesdeTxt(string nombreArchivo){
	ifstream archi(nombreArchivo);
	if(!archi)
		throw runtime_error("Error al leer "+nombreArchivo);
	
	vector<Cabecera>resultado;
	string nombre,path;
	Cabecera aux;
	while((getline(archi,nombre)) and (getline(archi,path))){
		strncpy(aux.nombre,nombre.c_str(),49);
		aux.nombre[49] = '\0';
		
		strncpy(aux.path,path.c_str(),49);
		aux.path[49] = '\0';
		resultado.push_back(aux);
	}
	archi.close();
	return resultado;
}
