import struct
	import os
	
# Configuración de directorios
	OUT_DIR = "Recursos/Binarios"
	
	def ensure_out_dir():
	if not os.path.exists(OUT_DIR):
		os.makedirs(OUT_DIR)
		
		def write_libros(path, count=10):
		print(f"Generando {path}...")
# Estructura Libro (Estimada para MinGW 32-bit / ZinjaI):
# int id (4)
# char nombre[50] (50)
# padding (2) -> para alinear el siguiente int a 4 bytes
# int diasRestantes (4)
# bool disponible (1)
# bool caduco (1)
# padding (2) -> para alinear el struct total a 4 bytes
# Total: 64 bytes
		
		fmt = '<i50s2xiBB2x' 
		
		with open(path, 'wb') as f:
		for i in range(1, count + 1):
			id_ = i
# Nombre rellenado a 50 bytes
			nombre_str = f"Libro de Prueba {i}"
			nombre = nombre_str.encode('utf-8')[:49].ljust(50, b'\0')
									   
									   dias = 0
									   disponible = 1 # True
									   caduco = 0     # False
									   
# Pack escribe los datos binarios
									   data = struct.pack(fmt, id_, nombre, dias, disponible, caduco)
									   f.write(data)
									   
									   def write_alumnos(path, count=5):
									   print(f"Generando {path}...")
# Estructura Alumno (Hereda de Persona):
# --- BASE Persona ---
# int id (4)
# int DNI (4)
# char nombre[49] (49)
# padding (3) -> Alineación a 60 bytes
# --- DERIVADA Alumno ---
# char nombre[49] (49) (Variable oculta/shadowing)
# padding (3)
# int id (4) (Variable oculta/shadowing)
# bool sancion (1)
# padding (3)
# Total estimado: 120 bytes
									   
									   fmt = '<ii49s3x49s3xiB3x'
									   
									   with open(path, 'wb') as f:
									   for i in range(1, count + 1):
										   id_ = i
										   dni = 40000000 + i
										   nombre_str = f"Alumno {i}"
										   nombre = nombre_str.encode('utf-8')[:48].ljust(49, b'\0')
																	  sancion = 0
																	  
# Escribimos los datos duplicados en la base y la derivada
# para que funcione sin importar cual lea tu programa.
																	  data = struct.pack(fmt, id_, dni, nombre, nombre, id_, sancion)
																	  f.write(data)
																	  
																	  def write_bibliotecarios(path):
																	  print(f"Generando {path}...")
# Estructura Bibliotecario:
# --- BASE Persona ---
# int id (4), int DNI (4), char nombre[49], pad(3) -> 60 bytes
# --- DERIVADA Bibliotecario ---
# char nombre[49], pad(3) -> 52 bytes
# int id (4)
# System sistema (Objeto complejo con std::string) -> ~24 bytes en 32-bit (aprox)
# Total estimado: ~140 bytes.
# ADVERTENCIA: System contiene punteros. Escribir ceros es lo unico "seguro" 
# pero el programa podria fallar al cerrarse.
																	  
# Asumimos 24 bytes de ceros para el objeto System
																	  fmt = '<ii49s3x49s3xi24x'
																	  
																	  with open(path, 'wb') as f:
# Bibliotecario 1
																	  id_ = 1
																	  dni = 30000000
																	  nombre = b"Admin Bibliotecario".ljust(49, b'\0')
																	  
																	  data = struct.pack(fmt, id_, dni, nombre, nombre, id_)
																	  f.write(data)
																	  
																	  def main():
																	  ensure_out_dir()
																	  
# Generar archivos
																	  write_libros(os.path.join(OUT_DIR, 'libros.bin'))
																	  write_alumnos(os.path.join(OUT_DIR, 'alumnos.bin'))
																	  write_bibliotecarios(os.path.join(OUT_DIR, 'bibliotecarios.bin'))
																	  
# Tu main.cpp usa 'usuarios.bin' a veces, hacemos una copia de alumnos
																	  write_alumnos(os.path.join(OUT_DIR, 'usuarios.bin'))
																	  
																	  print("¡Archivos generados exitosamente en Recursos/Binarios!")
																	  
																	  if __name__ == '__main__':
																		  main()
