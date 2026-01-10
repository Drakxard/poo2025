#include "Bibliotecario.h"
using namespace std;


void Bibliotecario::AgregarLibros(int LibrosAgregar, vector<Libro> &resultadoTest)
{

	string nombreLibro = "";
	int idLibro = 0;
	while (LibrosAgregar > 0)
	{

		cout << "Nombre del libro: ";
		cin >> nombreLibro;

		/// Generar ID
		int size = resultadoTest.size();
		if (size > 0)
			idLibro = (resultadoTest[size - 1].VerID()) + 1;

		Libro aux(idLibro, nombreLibro.c_str());
		resultadoTest.push_back(aux);
		--LibrosAgregar;
	}
}

void Bibliotecario::EliminarLibro(vector<Libro>::const_iterator Eliminar, vector<Libro> &v)
{
	v.erase(Eliminar);
}


// En bibliotecario.cpp


bool Bibliotecario::PrestarLibros(int idLibro, vector<Libro>& v, int dia, int mes, int anio) {
 // 1. Buscar el libro por ID si existe
 
	   if(idLibro>v.size()){
			cout<<"Código de libro inexistente, Libro no encontrado." << endl;
			return false; //no existe el libro o está prestado
	   }
	   
// 2. Verificar disponibilidad
		if (v[idLibro].EstadoDisponibilidad())
		{
			
			/// entonces lo prestare y no estara disponible
			//this->Disponible(false);  
			
            
            // Calcular días restantes hasta la fecha dada
            int diasCalculados = CalcularDiferenciaDias(dia, mes, anio);
            
            // Asignar los días al libro
           // this->DiasRestantes(diasCalculados);
            
            cout << "Libro prestado exitosamente. Dias para devolucion: " << diasCalculados << endl;
            return true;
		}
		else
		{
			cout << "El libro ya se encuentra prestado." << endl;
		}
    return false;
}

bool Bibliotecario:: Alumno_quiere_un_libro(Alumno &x){
	//averiguamos si está limpio y no está sancionado
	return true;//x.sancion;
}
/*vector<Alumno>Sancionados(int id){
	if(EstaSancionado){

	}
}
*/

int Bibliotecario::CalcularDiferenciaDias(int dia, int mes, int anio){
		// 1. Obtener fecha actual
		time_t t = time(0);
		struct tm * now = localtime(&t);
		
		// 2. Configurar fecha de devoluci�n (struct tm)
		struct tm fechaDevolucion = {0};
		fechaDevolucion.tm_year = anio - 1900; // Los a�os en tm cuentan desde 1900
		fechaDevolucion.tm_mon = mes - 1;      // Los meses van de 0 a 11
		fechaDevolucion.tm_mday = dia;
		
		// 3. Convertir ambas a tiempo en segundos
		time_t fechaActualSec = mktime(now);
		time_t fechaDevSec = mktime(&fechaDevolucion);
		
		// 4. Calcular diferencia en segundos y convertir a d�as
		double seconds = difftime(fechaDevSec, fechaActualSec);
		int dias = static_cast<int>(seconds / (60 * 60 * 24));
		
		return dias > 0 ? dias : 0; // Evitar d�as negativos si la fecha ya pas�
	}
