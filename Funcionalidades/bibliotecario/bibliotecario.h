#include <string>
#include <vector>
#include "../libro/libro.h"
#include "../../librerias/persona.h"

using namespace std;
class Bibliotecario: public Persona{
 char nombre[49];
 int id;
public:
	Bibliotecario(int id, const char *nombre):Persona(id,nombre){};
	// Función auxiliar para calcular diferencia de días desde "hoy" hasta una fecha meta
	int CalcularDiferenciaDias(int dia, int mes, int anio) {
		// 1. Obtener fecha actual
		time_t t = time(0);
		struct tm * now = localtime(&t);
		
		// 2. Configurar fecha de devolución (struct tm)
		struct tm fechaDevolucion = {0};
		fechaDevolucion.tm_year = anio - 1900; // Los años en tm cuentan desde 1900
		fechaDevolucion.tm_mon = mes - 1;      // Los meses van de 0 a 11
		fechaDevolucion.tm_mday = dia;
		
		// 3. Convertir ambas a tiempo en segundos
		time_t fechaActualSec = mktime(now);
		time_t fechaDevSec = mktime(&fechaDevolucion);
		
		// 4. Calcular diferencia en segundos y convertir a días
		double seconds = difftime(fechaDevSec, fechaActualSec);
		int dias = static_cast<int>(seconds / (60 * 60 * 24));
		
		return dias > 0 ? dias : 0; // Evitar días negativos si la fecha ya pasó
	}
	void GuardarLibros(string nombreArhivo, vector<Libro> &A_Guardar);
    vector<Libro> VerLibros(string nombreArchivo,bool crear=false);
	void AgregarLibros(int LibrosAgregar,vector<Libro>&resultadoTest);
	void EliminarLibro(vector<Libro>::const_iterator Eliminar,vector<Libro>&v);
	vector<Libro>::const_iterator BuscarLibro(int idLibro,const vector<Libro>&v);
	bool PrestarLibros(int idLibro,vector<Libro>&v,int cantDiasPrestar);
	

};
