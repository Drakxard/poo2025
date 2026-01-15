#include "Bibliotecario.h"
#include <algorithm>
using namespace std;





vector<Libro> Bibliotecario::AgregarLibros(int LibrosAgregar, string nombreArchivo)
{
	vector<Libro> resultado;
	string nombreLibro = "";
	int idLibro = 0;
	
	int id = sistema.VerUltimo<Libro>(nombreArchivo);
	while (LibrosAgregar > 0)
	{
		
		cout << "Nombre del libro: ";
		cin >> nombreLibro;
		
		/// Generar ID
			idLibro = ++id;
		
		Libro aux(idLibro, nombreLibro.c_str());
		resultado.push_back(aux);
		--LibrosAgregar;
	}
	return resultado;
}

void Bibliotecario::EliminarLibro(vector<Libro>::const_iterator Eliminar, vector<Libro> &Libros)
{
	Libros.erase(Eliminar);
}


// En bibliotecario.cpp

bool Bibliotecario::PrestarLibros(size_t idLibro, size_t idAlumno, vector<Libro> &Libros, vector<Alumno> &Alumnos, int dia, int mes, int anio)
{
	// 1. Buscar al alumno por ID usando find_if
	auto itAlumno = find_if(Alumnos.begin(), Alumnos.end(), [idAlumno](const Alumno& a) {
		return a.VerID() == idAlumno;
	});
	
	// Validar si el iterador lleg� al final (no encontr� al alumno)
	if (itAlumno == Alumnos.end()) {
		cout << "Error: Alumno con ID " << idAlumno << " no encontrado." << endl;
		return false;
	}
	
	// 2. Verificar si el alumno est� sancionado
	// Nota: Asumimos que VerEstadoDeSancion devuelve 'true' si est� sancionado.
	// Puedes usar la funci�n auxiliar que ya ten�as: Alumno_quiere_un_libro(*itAlumno)
	// O llamar directamente al m�todo del alumno. Usaremos el m�todo directo por claridad:
	if (itAlumno->VerEstadoDeSancion()) { 
		cout << "Prestamo denegado: El alumno " << itAlumno->VerNombre() << " tiene una sancion activa." << endl;
		return false;
	}
	
	// 3. Buscar el libro por ID
	auto itLibro = find_if(Libros.begin(), Libros.end(), [idLibro](const Libro& l) {
		return l.VerID() == idLibro;
	});
	
	// Validar si el iterador lleg� al final (no encontr� el libro)
	if (itLibro == Libros.end()) {
		cout << "Error: Libro con ID " << idLibro << " no encontrado." << endl;
		return false;
	}
	
	// 4. Verificar disponibilidad y procesar el pr�stamo
	if (itLibro->EstadoDisponibilidad()) {
		
		// Marcar el libro como NO disponible
		itLibro->SetDisponible(false); 
		
		// Calcular la diferencia de d�as para la devoluci�n
		int diasCalculados = CalcularDiferenciaDias(dia, mes, anio);
		
		// Asignar los d�as restantes al libro
		itLibro->DiasRestantes(diasCalculados);
		
		cout << "------------------------------------------------" << endl;
		cout << "Libro prestado exitosamente a: " << itAlumno->VerNombre() << endl;
		cout << "Libro: " << itLibro->VerNombre() << endl;
		cout << "Dias para devolucion: " << diasCalculados << endl;
		cout << "------------------------------------------------" << endl;
		
		return true; 
	} else {
		cout << "El libro '" << itLibro->VerNombre() << "' ya se encuentra prestado." << endl;
		return false; 
	}
}

bool Bibliotecario:: Alumno_quiere_un_libro(Alumno &x){
	//averiguamos si esta limpio y no esta sancionado
	return x.VerEstadoDeSancion();
}


int Bibliotecario::CalcularDiferenciaDias(int dia, int mes, int anio){
	// 1. Obtener fecha actual
	time_t t = time(0);
	struct tm * now = localtime(&t);
	
	// 2. Configurar fecha de devoluci?n (struct tm)
	struct tm fechaDevolucion = {0};
	fechaDevolucion.tm_year = anio - 1900; // Los a?os en tm cuentan desde 1900
	fechaDevolucion.tm_mon = mes - 1;      // Los meses van de 0 a 11
	fechaDevolucion.tm_mday = dia;
	
	// 3. Convertir ambas a tiempo en segundos
	time_t fechaActualSec = mktime(now);
	time_t fechaDevSec = mktime(&fechaDevolucion);
	
	// 4. Calcular diferencia en segundos y convertir a d?as
	double seconds = difftime(fechaDevSec, fechaActualSec);
	int dias = static_cast<int>(seconds / (60 * 60 * 24));
	
	return dias > 0 ? dias : 0; // Evitar d?as negativos si la fecha ya pas?
}

bool Bibliotecario::Sancionar(int IdAlumno, string nombreArchivo, bool decision)
{
	int ultimoID = sistema.VerUltimo<Alumno>(nombreArchivo);
	if (IdAlumno > ultimoID){
		cout << "DNI inexistente, Alumno no encontrado." << endl;
		return false;
	}
	else{
		fstream archi(nombreArchivo, ios::binary|ios::out|ios::in);
		if (!archi)
			throw runtime_error("Error al Recuperar de " + nombreArchivo);
		Alumno t;
		archi.seekg((IdAlumno) * (sizeof(Alumno))); // vamos a la posicion
		archi.read(reinterpret_cast<char *>(&t), sizeof(Alumno));
		// cursor al final del alumno
		// Debe volver asi escribir libro actualizado 
		t.Sancionar(decision);//se cambia; bool  sancion = true, se sancionó
		
		archi.seekg((-1)*sizeof(Alumno));
        archi.write(reinterpret_cast<const char*>(&t),sizeof(Alumno));
     	return true; //alumno sancionado
	}
}
bool Bibliotecario::Actualizar_Disponibilidad( int idLibro, string nombreArchivo, bool decision){
	int ultimoID = sistema.VerUltimo<Libro>(nombreArchivo);
	if (idLibro > ultimoID){
		cout << "Id inexistente, Libro no encontrado." << endl;
		return false;
	}
	else{
		fstream archi(nombreArchivo, ios::binary|ios::out|ios::in);
		if (!archi)
			throw runtime_error("Error al Recuperar de " + nombreArchivo);
		
		Libro t;
		archi.seekg((idLibro) * (sizeof(Libro))); // vamos a la posicion
		archi.read(reinterpret_cast<char *>(&t), sizeof(Libro));
		// Debe volver al principio del libro para actualizarlo  
		t.CambiarEstado(decision);//se cambia la disponibilidad del libro;
		
		archi.seekg((-1)*sizeof(Libro));
        archi.write(reinterpret_cast<const char*>(&t),sizeof(Libro));
     	return true; //Libro Disponible
	}
}
