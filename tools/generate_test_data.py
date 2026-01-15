#!/usr/bin/env python3
import os
import struct

OUT_DIR = "Recursos/Binarios"

def ensure_out_dir():
    os.makedirs(OUT_DIR, exist_ok=True)

def write_libros(path, count=20):
    # Libro: id (int32), nombre (50 bytes), diasRestantes (int32), disponible (uint8), caduco (uint8)
    fmt = '<i50siBB'
    with open(path, 'wb') as f:
        for i in range(1, count+1):
            id_ = i
            nombre = f"Libro {i} - Titulo de prueba".encode('utf-8')[:49]
            nombre = nombre.ljust(50, b'\0')
            diasRestantes = 14 + (i % 10)
            disponible = 1 if (i % 3) != 0 else 0
            caduco = 0
            f.write(struct.pack(fmt, id_, nombre, diasRestantes, disponible, caduco))

def write_bibliotecarios(path):
    # Persona-like: id (int32), DNI (int32), nombre (49 bytes)
    fmt = '<ii49s'
    biblios = [
        (1, 20123456, "Ana Gomez"),
        (2, 30111222, "Luis Perez"),
        (3, 40199887, "María Torres"),
    ]
    with open(path, 'wb') as f:
        for id_, dni, nombre in biblios:
            nombre_b = nombre.encode('utf-8')[:48].ljust(49, b'\0')
            f.write(struct.pack(fmt, id_, dni, nombre_b))

def write_alumnos(path, count=10):
    # Alumno: id (int32), DNI (int32), nombre (49 bytes), sancion (uint8)
    fmt = '<ii49sB'
    with open(path, 'wb') as f:
        for i in range(1, count+1):
            id_ = i
            dni = 50000000 + i
            nombre = f"Alumno_{i}".encode('utf-8')[:48].ljust(49, b'\0')
            sancion = 1 if (i % 7) == 0 else 0
            f.write(struct.pack(fmt, id_, dni, nombre, sancion))

def write_historial(path, alumnos_count=10):
    # Historial record: idAlumno (int32), idLibro (int32), dia (int32), mes (int32), anio (int32), devuelto (uint8)
    fmt = '<iiiiiB'
    with open(path, 'wb') as f:
        rec_id = 0
        for alumno in range(1, alumnos_count+1):
            # give each alumno 2 records
            for j in range(2):
                rec_id += 1
                idAlumno = alumno
                idLibro = ((alumno - 1) * 2 + j) % 20 + 1
                dia = 1 + (rec_id % 27)
                mes = 1 + (rec_id % 12)
                anio = 2023 + (rec_id % 3)
                devuelto = 1 if (rec_id % 4) != 0 else 0
                f.write(struct.pack(fmt, idAlumno, idLibro, dia, mes, anio, devuelto))

def main():
    ensure_out_dir()
    write_libros(os.path.join(OUT_DIR, 'libros.bin'), 20)
    write_bibliotecarios(os.path.join(OUT_DIR, 'bibliotecarios.bin'))
    write_alumnos(os.path.join(OUT_DIR, 'usuarios.bin'), 10)
    # also write alumnos.bin for compatibility
    write_alumnos(os.path.join(OUT_DIR, 'alumnos.bin'), 10)
    write_historial(os.path.join(OUT_DIR, 'historial.bin'), 10)
    print('Archivos generados en', OUT_DIR)

if __name__ == '__main__':
    main()
