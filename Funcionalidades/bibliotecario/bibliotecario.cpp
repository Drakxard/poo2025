#include "Bibliotecario.h"
#include "../system/system.h"

using namespace std;




vector<Libro> Bibliotecario::AgregarLibros(int LibrosAgregar)
{
	vector<Libro> resultado;
	string nombreLibro = "";
	int idLibro = 0;
	string a="ab";
	int id = sistema->VerUltimo<Bibliotecario>(a);
	
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
	// 1. Buscar si el alumno por ID si existe
	auto itAlumno = find_if(Alumnos.begin(), Alumnos.end(), [idAlumno](const Alumno& a) {
			return a.VerID() == idAlumno;
		});
	
	if(idLibro>Alumnos.size()){
			cout<<"C�digo de libro inexistente, Libro no encontrado." << endl;
			return false; //no existe el libro o est� prestado
		}
	//verificar si el alumno no esta sancionado
		
	
		// 1. Buscar el libro por ID si existe
		auto itlibro = find_if(Libros.begin(), Libros.end(), [idLibro](const Libro& a) {
			return a.VerID() == idLibro;
		});
		
		if(idLibro>Libros.size()){
			cout<<"C�digo de libro inexistente, Libro no encontrado." << endl;
			return false; //no existe el libro o est� prestado
		}
		
		// 2. Verificar si existe
		if (itlibro != Libros.end()) {
			// 3. Verificar disponibilidad
			if (itlibro->EstadoDisponibilidad()) {
				
				// Marcar como NO disponible
				itlibro->SetDisponible(false); 
				
				// Calcular días restantes hasta la fecha dada
				int diasCalculados = CalcularDiferenciaDias(dia, mes, anio);

				// Asignar los días al libro
				itlibro->DiasRestantes(diasCalculados);
				
				cout << "Libro prestado exitosamente. Dias para devolucion: " << diasCalculados << endl;
				return true; 
			} else {
				cout << "El libro ya se encuentra prestado." << endl;
				return false; 
			}
		}
    
    cout << "Libro no encontrado." << endl;
    return false;
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
	string a= "ab";
	int ultimoID = sistema->template VerUltimo<Alumno>(a);
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
	string a = "ab";
	//int ultimoID = sistema.VerUltimo<Bibliotecario>(a);
	int ultimoID =0;
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
