#include "bibliotecario.h"
#include "../system/system.h"
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

// --- FUNCI�N CROSS-PLATFORM ---
void LimpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
// ------------------------------

template<typename T>
	vector<T> Bibliotecario::AgregarElementos(int Agregar, string nombreArchivo, System& sys)
{
	vector<T> resultado;
	string nombre = "";
	size_t dni;
	
	int idElemento = sys.VerUltimo<T>(nombreArchivo);
	
	while (Agregar > 0)
	{
		cout << "Nombre: "; cin >> nombre;     
		cout << "Dni: "; cin >> dni;
		
		++idElemento;
		T aux(idElemento, nombre.c_str(), dni);
		resultado.push_back(aux);
		--Agregar;
		cout << "Nombre del nuevo: " << aux.VerNombre() << endl;
	}
	return resultado;
}

vector<Libro> Bibliotecario::AgregarElementos(int Agregar, string nombreArchivo, System& sys)
{
	vector<Libro> resultado;
	string nombre = "";
	int idElemento = sys.VerUltimo<Libro>(nombreArchivo);
	while (Agregar > 0)
	{
		cout << "Nombre: "; cin >> nombre;     
		++idElemento;
		Libro aux(idElemento, nombre.c_str());
		resultado.push_back(aux);
		--Agregar;
		cout << endl << "Libro agregado: " << aux.VerNombre() << endl;
	}
	return resultado;
}

void Bibliotecario::EliminarLibro(vector<Libro>::const_iterator Eliminar, vector<Libro> &Libros)
{
	Libros.erase(Eliminar);
}

bool Bibliotecario::PrestarLibros(size_t idLibro, size_t idAlumno, vector<Libro> &Libros, vector<Alumno> &Alumnos, vector<Libros_en_Prestamo>& Prestamos, int dia, int mes, int anio)
{
	if(idLibro > Libros.size()){
		cout << "Codigo de libro inexistente." << endl;
		return false;
	}
	

	auto itlibro = find_if(Libros.begin(), Libros.end(), [idLibro](const Libro& a) {
		return a.VerID() == idLibro;
	});
	
	auto itAlumno = find_if(Alumnos.begin(), Alumnos.end(), [idAlumno](const Alumno& b) {
		return b.VerID() == idAlumno;
	});

	if (itAlumno != Alumnos.end() && Alumno_quiere_un_libro(*itAlumno)) {
		return false;
	}

	if (itlibro != Libros.end()) {
		if (itlibro->EstadoDisponibilidad()) {
			itlibro->SetDisponible(false); 
			int diasCalculados = CalcularDiferenciaDias(dia, mes, anio);
			itlibro->DiasRestantes(diasCalculados);
			
			cout << "Libro prestado exitosamente. Dias: " << diasCalculados << endl;
			AgregarLibroPrestado(idLibro, idAlumno, dia, mes, anio, Prestamos);
			return true;
		} else {
			cout << "El libro ya se encuentra prestado." << endl;
			return false; 
		}
	}
	cout << "Libro no encontrado." << endl;
	return false;
}

void Bibliotecario::AgregarLibroPrestado(size_t id_LibroPrestado,size_t id_AlumnoPrestado, int dia, int mes, int anio, vector<Libros_en_Prestamo>& Prestamos){
	Libros_en_Prestamo aux;
	aux.id_Libro = id_LibroPrestado;
	aux.id_Alumno = id_AlumnoPrestado;
	aux.dia_Devolucion = dia;
	aux.mes_Devolucion = mes;
	aux.año_Devolucion = anio;

	// Calcular el último id_Prestamo en el vector (0 si está vacío)
	size_t ultimoId = 0;
	if (!Prestamos.empty()) {
		auto it = std::max_element(Prestamos.begin(), Prestamos.end(), [](const Libros_en_Prestamo &a, const Libros_en_Prestamo &b){
			return a.id_Prestamo < b.id_Prestamo;
		});
		ultimoId = it->id_Prestamo;
	}
	aux.id_Prestamo = ultimoId + 1;

	Prestamos.push_back(aux);
}

bool Bibliotecario::Devolucion_libro(size_t idlibro){
	for(int i = 0; i < CantidadPrestamos; ++i){
		if((size_t)Id_Prestamos[i] == idlibro){
			Id_Prestamos[i] = -1; 
			return true;
		}
	}
	return false;
}

bool Bibliotecario::Alumno_quiere_un_libro(Alumno &x){
	return x.VerEstadoDeSancion();
}

int Bibliotecario::CalcularDiferenciaDias(int dia, int mes, int anio){
	time_t t = time(0);
	struct tm * now = localtime(&t);
	
	struct tm fechaDevolucion = {0};
	fechaDevolucion.tm_year = anio - 1900; 
	fechaDevolucion.tm_mon = mes - 1;      
	fechaDevolucion.tm_mday = dia;
	
	time_t fechaActualSec = mktime(now);
	time_t fechaDevSec = mktime(&fechaDevolucion);
	
	double seconds = difftime(fechaDevSec, fechaActualSec);
	int dias = static_cast<int>(seconds / (60 * 60 * 24));
	
	return dias > 0 ? dias : 0; 
}

bool Bibliotecario::Sancionar(int IdAlumno, string nombreArchivo, bool decision, System& sys)
{
	fstream archi(nombreArchivo, ios::binary|ios::out|ios::in);
	if (!archi) return false;
	
	Alumno t;
	archi.seekg((IdAlumno - 1) * (sizeof(Alumno))); 
	archi.read(reinterpret_cast<char *>(&t), sizeof(Alumno));
	
	t.Sancionar(decision);
	
	archi.seekp((IdAlumno - 1) * sizeof(Alumno));
	archi.write(reinterpret_cast<const char*>(&t), sizeof(Alumno));
	return true; 
}

bool Bibliotecario::Actualizar_Disponibilidad(int idLibro, string nombreArchivo, bool decision, System& sys){
	fstream archi(nombreArchivo, ios::binary|ios::out|ios::in);
	if (!archi) return false;
	
	Libro t;
	archi.seekg((idLibro - 1) * (sizeof(Libro))); 
	archi.read(reinterpret_cast<char *>(&t), sizeof(Libro));
	
	t.SetDisponible(decision); 
	if(decision) t.CambiarEstado(false); 
	
	archi.seekp((idLibro - 1) * sizeof(Libro));
	archi.write(reinterpret_cast<const char*>(&t), sizeof(Libro));
	return true; 
}

template<typename T>
	void Bibliotecario::CargarNuevos(int cant, string nombreArchivo, System& sys){
	vector<T> Agregados = AgregarElementos<T>(cant, nombreArchivo, sys);
	for(T&x : Agregados)
		cout << x.VerNombre() << "    " << x.VerDNI() << endl;
	
	char confirmar;
	cout << "Confirmar? (s/n): "; cin >> confirmar;
	LimpiarPantalla(); // Usa la funci�n compatible
	
	if(confirmar == 's'){
		sys.Guardar<T>(nombreArchivo, Agregados, false);
	}
}

void Bibliotecario::CargarNuevosLibros(int cant, string nombreArchivo, System& sys){
	vector<Libro> Agregados = AgregarElementos(cant, nombreArchivo, sys);
	for(Libro&x : Agregados)
		cout << x.VerNombre() << "    " << x.VerID() << endl;
	
	char confirmar;
	cout << "Confirmar? (s/n): "; cin >> confirmar;
	LimpiarPantalla(); // Usa la funci�n compatible
	
	if(confirmar == 's'){
		sys.Guardar<Libro>(nombreArchivo, Agregados, false);
	}
}

// Instanciaciones
template void Bibliotecario::CargarNuevos<Bibliotecario>(int, string, System&);
template void Bibliotecario::CargarNuevos<Alumno>(int, string, System&);
template vector<Alumno> Bibliotecario::AgregarElementos(int, string, System&);
template vector<Bibliotecario> Bibliotecario::AgregarElementos(int, string, System&);
