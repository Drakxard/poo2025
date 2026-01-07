#include "Bibliotecario.h";
using namespace std;

void Bibliotecario::GuardarLibros(string nombreArhivo, vector<Libro> &A_Guardar)
{
	ofstream archi(nombreArhivo, ios::binary);

	if (!archi)
		throw runtime_error("Error al guardar Libro en " + nombreArhivo);

	Libro aux;
	for (size_t i = 0; i < A_Guardar.size(); ++i)
	{
		aux = A_Guardar[i];
		archi.write(reinterpret_cast<const char *>(&(aux)), sizeof(aux));
	}
	archi.close();
}

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

vector<Libro>::const_iterator Bibliotecario::BuscarLibro(int idLibro, const vector<Libro> &v)
{
	vector<Libro>::const_iterator it = find_if(v.begin(), v.end(), [idLibro](const Libro a)
											   { return a.VerID() == idLibro; });
	if (it != v.end())
	{
		return it;
	}
	else
	{
		return v.end();
	}
}

// En bibliotecario.cpp

// Método corregido e implementado
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
			Setit->Disponible(false);  
			
            
            // Calcular días restantes hasta la fecha dada
            int diasCalculados = CalcularDiferenciaDias(dia, mes, anio);
            
            // Asignar los días al libro
            it->DiasRestantes(diasCalculados);
            
            cout << "Libro prestado exitosamente. Dias para devolucion: " << diasCalculados << endl;
            return true;
		}
		else
		{
			cout << "El libro ya se encuentra prestado." << endl;
		}
    return false;
}

bool EstaSancionado(Alumno &x){
	return x.sancion;
}

bool Seprestara(Libro l){
	l.id
}
vector<Alumno>Sancionados(int id);