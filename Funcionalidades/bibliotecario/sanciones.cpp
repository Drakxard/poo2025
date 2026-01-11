#include "../libro/libro.h"
#include "../alumno/alumno.h"
#include "../system/system.h"
#include <cstring>
#include <iostream>

bool Sancionar(int IdAlumno){
	///Alumno
	bool Respuesta = Buscar(EstadoDisponibilidad()); 
	if(Respuesta){
		actualizar_disponibilidad(Respuesta);
	}
	return true;
	//Saltar N-pos (id)
	//Cambiar Su estado a Estado Sancionado
	///Return true -> sin problemas al sancionar
}
