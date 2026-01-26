import os
import requests
import time
from io import BytesIO  # Para manejar la descarga en memoria
from PIL import Image   # Para redimensionar

# --- CONFIGURACIÓN ---
DIRECTORIO_IMG = "./Recursos/img"
ARCHIVO_REGISTRO = "libros_index.txt"
ANCHO_OBJETIVO = 150
ALTO_OBJETIVO = 212

LIBROS_A_BUSCAR = [
    # --- 1. Programación en C++ y POO ---
    "C++ Como Programar Deitel",
    "El Lenguaje de Programacion C++ Stroustrup",
    "Programacion en C++ Joyanes Aguilar",
    "C++ Primer Lippman",
    "Thinking in C++ Bruce Eckel",
    "Effective C++ Scott Meyers",
    "Programacion orientada a objetos con C++ Francisco Javier Ceballos",
    "Accelerated C++ Andrew Koenig",
    "Clean Code Robert Martin",
    "Design Patterns Gamma",

    # --- 2. Cálculo 3 (Multivariable) ---
    "Calculo de varias variables James Stewart",
    "Calculo Vectorial Marsden",
    "Calculo Thomas Finney",
    "Calculo Leithold",
    "Calculo Larson Hostetler",
    "Calculo Trascendentes Tempranas Zill",
    "Calculo Avanzado Kaplan",
    "Calculo Tom Apostol",
    "Analisis Matematico Haaser",
    "Calculo diferencial e integral Purcell",

    # --- 3. Álgebra 2 (Lineal) ---
    "Algebra Lineal Stanley Grossman",
    "Algebra Lineal Bernard Kolman",
    "Algebra Lineal y sus aplicaciones David Lay",
    "Introduccion al Algebra Lineal Howard Anton",
    "Algebra Lineal Gilbert Strang",
    "Algebra Lineal Kenneth Hoffman",
    "Algebra Lineal Serge Lang",
    "Algebra Lineal Seymour Lipschutz",
    "Algebra Lineal David Poole",
    "Algebra Lineal George Nakos",

    # --- 4. Física 1 (Mecánica) ---
    "Fisica Universitaria Sears Zemansky",
    "Fisica para ciencias e ingenieria Serway",
    "Fisica Resnick Halliday",
    "Fisica para la ciencia y la tecnologia Tipler",
    "Fisica General Burbano",
    "Fisica Conceptual Paul Hewitt",
    "Fisica Alonso Finn",
    "Mecanica Vectorial para Ingenieros Beer Johnston",
    "Ingenieria Mecanica Dinamica Hibbeler",
    "Curso de Fisica de Berkeley Kittel",

    # --- 5. Lógica y Computabilidad ---
    "Matematicas Discretas Kenneth Rosen",
    "Matematicas Discretas Johnsonbaugh",
    "Matematicas Discretas y Combinatoria Grimaldi",
    "Introduccion a la teoria de la computacion Michael Sipser",
    "Teoria de Automatas y Lenguajes Formales Hopcroft",
    "Logica Matematica para Informaticos Ben-Ari",
    "Estructuras de Matematicas Discretas para la Computacion Kolman",
    "Introduccion a la Logica Copi",
    "Computability and Logic Boolos",
    "Godel Escher Bach Hofstadter",

    # --- 6. Estadística ---
    "Probabilidad y Estadistica para ingenieros Walpole",
    "Probabilidad y Estadistica para ingenieria y ciencias Devore",
    "Estadistica Matematica con Aplicaciones Wackerly",
    "Probabilidad y Estadistica aplicadas a la ingenieria Montgomery",
    "Introduccion a la Probabilidad y Estadistica Mendenhall",
    "Probabilidad y Estadistica Murray Spiegel",
    "Probabilidad y Aplicaciones Estadisticas Paul Meyer",
    "Estadistica elemental Mario Triola",
    "Estadistica para administracion y economia Levin",
    "A First Course in Probability Sheldon Ross",

    # --- 7. Ecuaciones Diferenciales Ordinarias ---
    "Ecuaciones Diferenciales con problemas de valores en la frontera Zill",
    "Ecuaciones Diferenciales elementales y problemas con valores en la frontera Boyce",
    "Ecuaciones Diferenciales Nagle",
    "Ecuaciones Diferenciales Elementales Rainville",
    "Ecuaciones Diferenciales con aplicaciones Simmons",
    "Ecuaciones Diferenciales Blanchard",
    "Ecuaciones Diferenciales y Algebra Lineal Edwards Penney",
    "Ecuaciones Diferenciales Isabel Carmona",
    "Matematicas Avanzadas para Ingenieria Kreyszig",
    "Transformadas de Laplace Spiegel",

    # --- 8. Laboratorio de Datos (Estructuras y Algoritmos) ---
    "Estructuras de Datos en C++ Joyanes Aguilar",
    "Introduction to Algorithms Cormen",
    "Estructuras de Datos y Algoritmos Aho",
    "Algorithms Robert Sedgewick",
    "The Art of Computer Programming Knuth",
    "Data Structures and Algorithm Analysis Mark Allen Weiss",
    "Estructuras de Datos Osvaldo Cairo",
    "Algoritmos y Estructuras de Datos Niklaus Wirth",
    "Cracking the Coding Interview McDowell",
    "Python Data Science Handbook VanderPlas"
]

if not os.path.exists(DIRECTORIO_IMG):
    os.makedirs(DIRECTORIO_IMG)

def obtener_datos():
    registros = []
    headers = {'User-Agent': 'PythonBookFetcher/1.0 (Educational Project)'}

    print(f"--- Procesando {len(LIBROS_A_BUSCAR)} libros ---")
    print(f"--- Resolución Forzada: {ANCHO_OBJETIVO}x{ALTO_OBJETIVO} ---")

    for i, termino_busqueda in enumerate(LIBROS_A_BUSCAR):
        print(f"[{i}] Buscando: {termino_busqueda[:30]}...", end=" ")
        
        try:
            params = {'q': termino_busqueda}
            url_busqueda = "https://openlibrary.org/search.json"
            
            respuesta = requests.get(url_busqueda, params=params, headers=headers)
            datos = respuesta.json()

            encontrado = False
            path_relativo = ""

            if 'docs' in datos and len(datos['docs']) > 0:
                # Buscamos en los primeros 10 resultados alguno con portada
                for doc in datos['docs'][:10]:
                    if 'cover_i' in doc:
                        cover_id = doc['cover_i']
                        
                        # Usamos el ID del libro en la lista como nombre para evitar duplicados o nombres raros
                        nombre_archivo = f"{i}.jpg"
                        path_relativo = f"{DIRECTORIO_IMG}/{nombre_archivo}"
                        
                        # URL de la imagen original (Tamaño Grande -L)
                        url_imagen = f"https://covers.openlibrary.org/b/id/{cover_id}-L.jpg"

                        # 1. Descargar bytes de la imagen
                        response_img = requests.get(url_imagen, headers=headers)
                        img_bytes = BytesIO(response_img.content)
                        
                        # 2. Abrir con Pillow y Redimensionar
                        with Image.open(img_bytes) as img:
                            # Forzamos 150x212 (ignorando aspecto original)
                            img_resized = img.resize((ANCHO_OBJETIVO, ALTO_OBJETIVO), Image.Resampling.LANCZOS)
                            
                            # Si la imagen no es RGB (ej. es CMYK o P), la convertimos a RGB para guardarla como JPG
                            if img_resized.mode != 'RGB':
                                img_resized = img_resized.convert('RGB')
                            
                            # 3. Guardar en disco
                            img_resized.save(path_relativo)
                        
                        print(f"✅ OK (Resized)")
                        encontrado = True
                        break # Salimos del bucle interno
                
                if not encontrado:
                    print("⚠️ Sin portada en los primeros resultados.")
            else:
                print("❌ No encontrado.")

            if encontrado:
                # Formato: Nombre del Libro : Ruta
                registros.append(f"{termino_busqueda}:{path_relativo}")
            else:
                registros.append(f"{termino_busqueda}:NO_ENCONTRADO")

            # Pausa pequeña
            time.sleep(0.2)

        except Exception as e:
            print(f"Error: {e}")

    # Guardar índice final
    with open(ARCHIVO_REGISTRO, "w", encoding="utf-8") as f:
        for linea in registros:
            f.write(linea + "\n")

    print("\n--- Terminado ---")
    print(f"Revisa {ARCHIVO_REGISTRO} y la carpeta {DIRECTORIO_IMG}")

if __name__ == "__main__":
    obtener_datos()