bool Sancionar(int IdAlumno)
{
	/// Alumno
	bool Respuesta = EstadoDisponibilidad();
	if (Respuesta)
	{
		actualizar_disponibilidad(string nombreArchivo, int id);
	}
	return true;
	// Saltar N-pos (id)
	// Cambiar Su estado a Estado Sancionado
	/// Return true -> sin problemas al sancionar
}