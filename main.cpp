#include <iostream>
#include "Funcionalidades/preConfiguracion/preConfiguracion.h" // Solo una vez

// Importar Clases
#include "Funcionalidades/system/system.h"
#include "Funcionalidades/buscador/buscador.h"
#include "Funcionalidades/libro/libro.h"
#include "Funcionalidades/bibliotecario/bibliotecario.h"
#include "Funcionalidades/alumno/alumno.h"
#include "Funcionalidades/login/login.h" // Si vas a usar login
#include "Funcionalidades/Bloques/Bloques.h"

using namespace std; // Importante si usas string sin std::
// VARIABLE GLOBAL (Funciona en ambos sistemas)


string NombreUsuario= "Invitado";
int codigo = 1;
/// Variables
const char *nom = NombreUsuario.c_str();
///Crear entedidad del sistema de gestion
int DNI=12345;
Bibliotecario admin(codigo,nom,DNI); 
///Clase encargada de los metodos de bajo nivel
// VARIABLE GLOBAL (Funciona en ambos sistemas)
System sistema;


// Nombre del Binario de test o Rutas con barras normales funcionan en ambos como mas le pinte
string libros = "Recursos/Binarios/libros.bin";
string alumnos = "Recursos/Binarios/alumnos.bin";
string bibliotecarios = "Recursos/Binarios/bibliotecarios.bin";

///Clase encargada de las busquedas
Buscador navega;
string palabra;
//Precarga de los dos menus
void menuBibliotecario();
void menuAlumno();

// Funci�n auxiliar para crear carpetas en ambos OS
void CrearCarpetasNecesarias() {
#ifdef _WIN32
	system("if not exist Recursos\\Binarios\\Tags mkdir Recursos\\Binarios\\Tags");
#else
	system("mkdir -p Recursos/Binarios/Tags");
#endif
}

vector<Libro> resultadoLibros;
vector<Alumno> resultadoAlumnos;
vector<Bibliotecario> resultadoBibliotecarios;
vector<Libros_en_Prestamo>Prestamos;
///Estados Especiales
///De alumno
string sancionados = "Recursos/binarios/sancionados.bin";
///De libro
string prestados = "Recursos/binarios/prestados.bin";
string matematica = "Recursos/binarios/matematica.bin";
string poo = "Recursos/binarios/poo.bin";
string fisica = "Recursos/binarios/fisica.bin";
///N-tags


vector<Libro> vectorLibros = sistema.VerContenido<Libro>(libros, 1);
vector<Alumno> vectorAlumnos = sistema.VerContenido<Alumno>(alumnos, 1);
vector<Bibliotecario> vectorBibliotecario = sistema.VerContenido<Bibliotecario>(bibliotecarios, 1);
size_t idLibro, idAlumno, idBibliotecario;
int cant;	

///Iteradores para los metodos
vector<Libro>::const_iterator it;
vector<Libro>::const_iterator itBorrar;
int c; //ya apareci

vector<Tags> Etiquetas;
Tags auxTags;
vector<Tags> tagsActuales;


int main(){
	//para la compatibilidad en ambos sistemas operativos (linux y Windows)
	CrearCarpetasNecesarias();
	cout <<endl<< "Sistema iniciado correctamente." << endl;

	
	//Bloques allTags;
	/*-----------------Login------------------------
	//Saber los alumnos y bibliotecarios
	vectorAlumnos = sistema.VerContenido<Alumno>(alumnos,true);
	vectorBibliotecario= sistema.VerContenido<Bibliotecario>(bibliotecarios,true);
	
	cout<<"Sistema de gestion Bibliotecario!!!"<<endl<<endl;
	
	int dni;
	cout<<"Ingrese su Documento de Identidad, por favor: ";
	cin>>dni;
	
	
	int PosBibliotecario = BuscarDniEnBibliotecarios(dni, vectorBibliotecario);
	cout<<"PosBibliotecario: "<<PosBibliotecario<<endl;
	//Declarar Variables para ser usadas en la ejecucion
	Alumno alumn;
	Bibliotecario biblio;
	
	
	
	if(PosBibliotecario != -1){
	biblio = ObjetoCorrespondienteBibliotecario(PosBibliotecario, vectorBibliotecario);
	cout<<"?Que Quieres Hacer "<<biblio.VerNombre()<<" ?"<<endl;
	menuBibliotecario();
}
	else{
	int PosAlumno = BuscarDniEnAlumnos(dni,vectorAlumnos);
	if(PosAlumno!= -1){
	alumn = ObjetoCorrespondienteAlumno(PosAlumno, vectorAlumnos); 
	cout<<"PosAlumno: "<<PosAlumno<<endl;
	
	cout<<"?Que Quieres Hacer "<<alumn.VerNombre()<<" ?"<<endl;
	cout<<"Menu alumno..";
}else{
	cout<<"No est?s en el sistema... Registrandote"<<endl;
	cant=1;
	admin.CargarNuevos<Alumno>(cant,alumnos);
}
}
	
	//Fin login, tenemos o un Bibliotecario o un Alumno
	*/
	/* ----------------------- Intefaz --------------------
	///Para mostrar los libros antes mostramos sus Cabeceras
	
	string indexCabeceras="./Recursos/libros_index.txt";
	
	vector<Cabecera> resultado = sistema.CargarDesdeTxt(indexCabeceras);
	
	for(Cabecera& x: resultado)
	cout<<
	"Nombre libro: "<<x.nombre<<
	"      "<<
	"path: "<<x.path<<
	endl;
	
	*/
	
	
	// ----------- Metodos relacionados a Libros --------------
	
	
	
	//VerLibrosExistentes
	/*cout<<"Libros Disponibles: "<<endl;
	vectorLibros = sistema.VerContenido<Libro>(libros,true);
	resultadoLibros = navega.Relacionados(palabra,vectorLibros);
	
	for(Libro& x: vectorLibros){
	cout
	<<"Nombre Libro: " 	<<x.VerNombre()
	<<"/ Id: "	<<x.VerID();
	if(x.EstadoDisponibilidad()==1){
	cout<<"/ Disponible"<<endl;
}else{
	cout<<"/ No Disponible"
	<<endl;
}
}
	cout<<endl<<endl<<"------------------------------"<<endl;
	*/
	
	/* -------------------- Buscar libro palabra -----------------------
	cin.ignore();
	cout<<"Buscar libro, ingrese palabra: ";
	getline(cin,palabra);
	cin.ignore();
	resultadoLibros = navega.Relacionados(palabra,vectorLibros);
	for(Libro &x: vectorLibros){
	cout
	<<"Nombre Libro: " 	<<x.VerNombre()
	<<"/ Id: "	<<x.VerID();
	if(x.EstadoDisponibilidad()==1){
	cout<<"/ Disponible"<<endl;
}else{
	cout<<"/ No Disponible"
	<<endl;
}
} 
	*/
	
	
	
	
	/*----------------------- Eliminar Libros ---------------------								vectorLibros = sistema.VerContenido<Libro>(libros,true);
	cout<<"ID a eliminar: ";cin>>idLibro;
	
	char borrar;
	cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
	if(borrar=='s'){
	///Uso del metodo 	| Proceso
	sistema.Eliminar(idLibro, vectorLibros);
	sistema.Guardar<Libro>(libros,vectorLibros);
	
}else{
	cout<<endl<<"Codigo No existente";
}
	*/
	
	//------------Agregar Libros----------------
	/*cout<<"Libros a agregar: ";cin>>cant;
	admin.CargarNuevosLibros(cant,libros,sistema );
	
	*/
	// -----------^ Metodos relacionados a Libros ^ --------------
	
	
	
	/* --------------- Flujo de bloques ------------
	//Trabajar con bloques
	
	//Las etiquetas reservan bloques, al ser creados
	Tags auxTags;
	vector<Tags> tagsActuales;
	auxTags = allTags.AgregarNuevoTag();
	tagsActuales.push_back(auxTags);
	
	///Guardar tags
	sistema.Guardar<Tags>(allTags.VerPathEtiquetas(),tagsActuales);
	
	tagsActuales = sistema.VerContenido<Tags>(allTags.VerPathEtiquetas(),true);
	cout<<endl<<endl;
	for(Tags& x:tagsActuales)
	cout<<"Nombre Tag: "<<x.NombreTag<<" Inicia en: "<<x.InicioBloque<<
	"   < ------ >  "<<x.IdTag<<  endl;
	
	
	
	size_t IDtag, IDNuevo;
	cout<<"Ingresado IdTag: ";cin>>IDtag;
	cout<<"Id a agregar: ";cin>>IDNuevo;
	
	
	
	
	allTags.AgregarNuevoElemento(IDtag,IDNuevo);
	
	cout<<endl<<"Todos los id de ese bloque son: "<<endl;
	vector<size_t>resultado = allTags.LeerTodosLosElementos(IDtag);
	
	
	*/
	
	
	/* ----------- Metodos relacionados a Alumnos --------------
	
	//--------------Ver Alumnos------------
	vectorAlumnos = sistema.VerContenido<Alumno>(alumnos,true);
	
	cout<<"Alumnos: "<<endl;
	for(Alumno& x: vectorAlumnos)
	cout<<x.VerNombre()  <<"/   "<<x.VerDNI()  <<"/   "<<x.VerID()<<endl;
	
	cout<<endl<<endl<<"------------------------------"<<endl;
	
	//--------------Agregar Alumnos -----------  
	cout<<"Alumnos a agregar: ";cin>>cant;
	admin.CargarNuevos<Alumno>(cant,alumnos);
	
	//---------------Eliminar Alumno--------------
	cout<<"ID a eliminar: ";cin>>idAlumno;
	char borrar;
	cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
	if(borrar=='s'){
	///Uso del metodo 	| Proceso
	sistema.Eliminar<Alumno>(idAlumno, vectorAlumnos);
	sistema.Guardar<Alumno>(alumnos,vectorAlumnos);
	
}else{
	cout<<endl<<"Codigo de identificaci�n inexistente";
}
	
	//---------------Buscar Alummno--------------
	cin.ignore();
	cout<<"Buscar Alumno, ingrese el nombre: ";
	getline(cin,palabra);
	cin.ignore();
	
	resultadoAlumnos = navega.Relacionados(palabra,vectorAlumnos);
	if(resultadoAlumnos.size()==0){
	cout<<"no se encontro a nadie con ese nombre"<<endl;
}else{
	for(Alumno &x: resultadoAlumnos){
	cout<<"Nombre Alumno: " <<x.VerNombre()
	<<" / Id: "	<<x.VerID()
	<<" / DNI: "<<x.VerDNI();
	if(x.VerEstadoDeSancion()==1){
	cout<<"/ Sancionado"<<endl;
}else{
	cout<<"/ No Sancionado"
	<<endl;
}
} 
} 
	*/
	
	
	/* -----------^ Metodos relacionados a Alumnos ^ --------------
	
	
	
	/* ----------- Metodos relacionados a Bibliotecarios  --------------
	
	//---------------Ver Bibliotecarios--------------
	
	vectorBibliotecario= sistema.VerContenido<Bibliotecario>(bibliotecarios,true);
	cout<<"Bibliotecario: "<<endl;
	for(Bibliotecario& x: vectorBibliotecario)
	cout<<x.VerNombre()<<" / "<<x.VerDNI()<<" / "<<x.VerID()<<endl;
	cout<<endl<<endl<<"------------------------------"<<endl;
	
	//---------------Buscar Bibliotecarios"--------------
	cin.ignore();
	cout<<"Buscar Bibliotecario, ingrese el nombre: ";
	getline(cin,palabra);
	cin.ignore();
	resultadoBibliotecarios = navega.Relacionados<Bibliotecario>(palabra,vectorBibliotecario);
	
	
	if(resultadoBibliotecarios.size()==0){
		cout<<"no se encontro a nadie con ese nombre"<<endl;
	}else{
			for(Bibliotecario &x: resultadoBibliotecarios){
				cout<<"Nombre Bibliotecario: " <<x.VerNombre()
					<<" / Id: "	<<x.VerID()
					<<" / DNI: "<<x.VerDNI();
			}
	}
} 
	
	//--------------Agregar Bibliotecarios -----------
	cout<<"Bibliotecarios a agregar: ";cin>>cant;
	admin.CargarNuevos<Bibliotecario>(cant,bibliotecarios);
	
	
	//---------------Eliminar Bibliotecarios"--------------
	cout<<"ID a eliminar: ";cin>>idBibliotecario;
	char borrar;
	cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
	if(borrar=='s'){
	cout<<endl<<"Id ingresado a borrar: "<<idBibliotecario<<endl;
	///Uso del metodo 	| Proceso
	vectorBibliotecario= sistema.VerContenido<Bibliotecario>(bibliotecarios,true);
	sistema.Eliminar<Bibliotecario>(idBibliotecario, vectorBibliotecario);
	sistema.Guardar<Bibliotecario>(bibliotecarios,vectorBibliotecario,true);
	}
	*///---------------Prestar libro Bibliotecarios--------------
//	cout << "ID Libro: "; 
//	size_t idL; 
//	cin >> idL;
//	cout << "ID Alumno: "; 
//	size_t idA; 
//	cin >> idA;
//	cout << "Fecha devolucion (dia mes anio): "; 
//	int d,m,y; 
//	cin >> d >> m >> y;
//	vectorLibros = sistema.VerContenido<Libro>(libros, true);
//	vectorAlumnos = sistema.VerContenido<Alumno>(alumnos, true);
//	bool ok = admin.PrestarLibros(idL, idA, vectorLibros, vectorAlumnos, Prestamos, d, m, y);
//	if (ok) {
//		sistema.Guardar<Libro>(libros, vectorLibros, true);
//		cout << "Prestamo registrado. ID prestamo: " << Prestamos.back().id_Prestamo << "\n";
//	}else{ cout << "No se pudo prestar el libro.\n";
//	}
// actualizar persistencia del libro
	/*

	
	//---------------Sancionar Bibliotecarios--------------


	//---------------Devolucion libro Bibliotecarios--------------
	cout<<"ingrese Id del libro a devolver";
	cin>>idLibro;
	if(admin.Devolucion_libro(idLibro)==true){
		cout<<"Libro devuelto"<<endl;
	}else{
		cout<<"Cï¿½digo de libro inexistente, Libro no encontrado." << endl;
	}
	-----------^ Metodos relacionados a Bibliotecarios ^ --------------
	*/

	/**/
	
	
	///------------------ Buscador ------------------
	
	/*///Extraer palabra de frase
	string frase= "Luna llena de Azul marino";
	vector<string> resultado = navega.ExtraerPalabras(frase);
	c=0;
	for(string& x: resultado)
	cout<<++c<<")"<<x<<endl;
	*/
		
/*	///Busqueda ampliada
	string fraseBusqueda;
	cout<<"Nombre de la frase de busqueda: ";cin>>fraseBusqueda;
	vector<size_t> resultadoBusqueda = navega.BusquedaAmpliada(fraseBusqueda);
	cout<<endl;
	for(size_t& x: resultadoBusqueda)
		cout<< x <<endl;
	*/
	
	/* Coincidencias
	vector<size_t> coincidencias = {1,2,3,3,4,5,6,6,7,7,7,7,8,9,10};
	vector<size_t> resultadoDeBusqueda = navega.ResultadoBusqueda(coincidencias);
	cout<<"Ranking de frecuencia: "<<endl;
	c=0;
	for(size_t& x: resultadoDeBusqueda)
	cout<<++c<<") "<<x<<endl;
	*/
	/*/// LeerEnBin para Tags luego paginador
	
	///VerLibros
	
	//VerLibrosExistentes
	cout<<"Libros Disponibles: "<<endl;
	vectorLibros = sistema.VerContenido<Libro>(libros,true);
	resultadoLibros = navega.Relacionados<Libro>(palabra,vectorLibros);
	
	for(Libro& x: vectorLibros){
		cout
			<<"Nombre Libro: " 	<<x.VerNombre()
			<<"/ Id: "	<<x.VerID();
		if(x.EstadoDisponibilidad()==1){
			cout<<"/ Disponible"<<endl;
		}else{
			cout<<"/ No Disponible"
				<<endl;
		}
	}
	cout<<endl<<endl<<"------------------------------"<<endl;
	/*
	
	cout<<"Libros a agregar: ";cin>>cant;
	admin.CargarNuevosLibros(cant,libros);
	
	Tags auxTags;
	vector<Tags> tagsActuales;
	auxTags = allTags.AgregarNuevoTag();
	tagsActuales.push_back(auxTags);
	
	///Guardar tags
	sistema.Guardar<Tags>(allTags.VerPathEtiquetas(),tagsActuales);

	/// Libros del tags	
	tagsActuales = sistema.VerContenido<Tags>(allTags.VerPathEtiquetas(),true);
	cout<<endl<<endl;
	vector<size_t> idTags;
	vector<Libro> librosGuardados;
	cant=0;
	for(Tags& x:tagsActuales){
		
		cout<<endl<<"Nombre Tag: "<<x.NombreTag<<" Inicia en: "<<x.InicioBloque<<
		"   < ------ >  "<<x.IdTag<<  endl;
		cout<<endl<<"Sus libros son: ";
		idTags = allTags.LeerTodosLosElementos(cant);
		librosGuardados = sistema.LeerDelBin<Libro>(idTags,libros);
		cout<<endl<<"Libros encontrados: "<<librosGuardados.size()<<endl;
		for(Libro& x : librosGuardados){
			cout<<endl;
			cout<<"Nombre: "<<x.VerNombre()<<endl
				<<"Id: "<<x.VerID()<<endl;
			cout<<endl;
		}
		++cant;
	}
	
	///asignar libro a tag
	size_t IDtag, IDNuevo;
	cout<<"Ingresado IdTag: ";cin>>IDtag;
	cout<<"Id a agregar: ";cin>>IDNuevo;
	allTags.AgregarNuevoElemento(IDtag,IDNuevo);
	
	*/
	
	
	
	
	
	
	
	
	
	return 0;
}
	
	
	
