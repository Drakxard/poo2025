#include "bibliotecario.h"
#include "../buscador/buscador.h"



using namespace std;

// --- FUNCI�N CROSS-PLATFORM ---
void Bibliotecario::LimpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
// ------------------------------



vector<Libro> Bibliotecario::AgregarElementos(int Agregar, string nombreArchivo, System& sys){
	vector<Libro> resultado;
	Buscador x;
	string nombre = "", autor = "";
	int idElemento = sys.VerUltimo<Libro>(nombreArchivo);
	while (Agregar > 0)
	{
		cout << "Nombre: "; cin >> nombre;     
		cout << "Autor: "; cin >> autor; 
		//validacion que no ingresen dos veces lo mismo
		if(x.Busqueda_Autor(autor,resultado).size()==0){
			++idElemento;
			Libro aux(idElemento, nombre.c_str(),autor.c_str());
			resultado.push_back(aux);
			--Agregar;
			cout << endl << "Libro agregado: " << aux.VerNombre() <<" / Autor: "<<aux.VerAutor()<<"/ ID:"<<idElemento<<endl;
		}else{
			cout<<"No se puede ingresar un libro y un autor dos veces"<<endl;
		}
	}
	return resultado;
}

void Bibliotecario::EliminarLibro(vector<Libro>::const_iterator Eliminar, vector<Libro> &Libros){
	Libros.erase(Eliminar);
}

bool Bibliotecario::PrestarLibros(size_t idLibro, size_t idAlumno, vector<Libro> &Libros, vector<Alumno> &Alumnos, vector<Libros_en_Prestamo>& Prestamos, int dia, int mes, int anio){
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
//			Agregar_Leidos(idLibro);
//			Libros[idLibro].Agregar_Lectores(idAlumno);
			
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
	aux.anio_Devolucion = anio;

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

bool Bibliotecario::Devolucion_libro(size_t idLibro, size_t /*idAlumno*/, vector<Libro> &Libros, vector<Alumno> &/*Alumnos*/, vector<Libros_en_Prestamo>& Prestamos, int /*dia_Devolucion*/, int /*mes_Devolucion*/, int /*anio_Devolucion*/){
	//queda marcado alumnos, dia, mes, año para implementar en la funcion historial
	// Buscar el préstamo correspondiente al libro y eliminarlo del vector Prestamos
	auto itPrestamo = find_if(Prestamos.begin(), Prestamos.end(), [idLibro](const Libros_en_Prestamo &p){
		return p.id_Libro == idLibro;
	});

	if (itPrestamo == Prestamos.end()) {
		cout << "Prestamo para ese libro no encontrado." << endl;
		return false;
	}

	Prestamos.erase(itPrestamo);

	// Marcar el libro correspondiente como disponible si existe en el vector Libros
	auto itLibro = find_if(Libros.begin(), Libros.end(), [idLibro](const Libro &l){
		return l.VerID() == idLibro;
	});

	if (itLibro != Libros.end()) {
		itLibro->SetDisponible(true);
		itLibro->DiasRestantes(0);
	}

	cout << "Devolucion realizada y prestamo eliminado." << endl;
	return true;
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

bool Bibliotecario::Sancion(int IdAlumno, string nombreArchivo, bool decision, System& sys){
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


