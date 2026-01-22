#include "Libro.h"
size_t Libro::VerID() const  
{
	return id;
}
const char* Libro::VerNombre() const{
	return this->nombre;
}

size_t Libro:: VerDisponible() const{
<<<<<<< Updated upstream
    return this->disponible;
}

// CorrecciÃ³n: Ahora retorna el atributo de la clase
=======
	return this->disponible;
}

// Corrección: Ahora retorna el atributo de la clase
>>>>>>> Stashed changes
bool Libro::EstadoDisponibilidad() const {
	return this->disponible;
}


void Libro::Agregar_Lectores(size_t idAlumno){
	Lectores.push_back(idAlumno);
}

const vector<int> Libro:: Ver_Lectores()const {
	return Lectores;
}

<<<<<<< Updated upstream
// Nuevo mÃ©todo para cambiar la disponibilidad desde Bibliotecario
=======
// Nuevo método para cambiar la disponibilidad desde Bibliotecario
>>>>>>> Stashed changes
void Libro::SetDisponible(bool d) {
	this->disponible = d;
}


void Libro::CambiarEstado(bool estado)
{
	if (estado)
		caduco = true;
	else
		caduco = false;
}

void Libro::RestarDia()
{
	//Llega hasta 0 dias, cuando se sobrepasa, caduca la devolucion
	//Ya no restar dias (antes de llamar)
	//sino antes preguntar si esta caducada la devolucion
	//Caducado -> Notificacion/Vector caducados
	//Luego al devolver primero buscar en ese vector diria, sino está
	//ahí, marcarlo como devuelto (reset estados)
	
	if(diasRestantes>=0)
		diasRestantes--;
	else
		CambiarEstado(1);
}

void Libro::DiasRestantes(int dias){
	diasRestantes = dias;
}

void Libro::CambiarNombre(const char *NuevoNombre){
	strncpy(this->nombre, NuevoNombre,49);
	this->nombre[49]='\0';
}


bool Libro::operator==(const Libro& otro) const {
	// Comparamos si los IDs son iguales.
	// Si tus variables se llaman diferente, c?mbialas aqu?.
	return this->id == otro.id; 
}
