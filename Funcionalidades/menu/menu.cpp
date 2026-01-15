#include "menu.h"



///Clase encargada de los metodos de bajo nivel
System sistema;

string libros = "Recursos/Binarios/libros.bin";
string usuarios = "Recursos/Binarios/usuarios.bin";
string BibliotecarioPath = "Recursos/Binarios/Bibliotecario.bin";

///Clase encargada de las busquedas
Buscador navega;
string palabra="Casa";

vector<Libro> resultadoLibros;


vector<Libro> vectorLibros = sistema.VerContenido<Libro>(libros, 1);
int idLibro;
int Nlibros;	

///Iteradores para los metodos
vector<Libro>::const_iterator it;
vector<Libro>::const_iterator itBorrar;
int c;



void MenuBibliotecario(){
	int opcion=-1;
	while(opcion!=0){
	
	cout<<"Menu de gestion"<<endl;
	cout<<"1. Libros"<<endl
	<<"2. Usuarios"<<endl
	<<"3. Bibliotecarios"<<endl
	<<"0. Salir"
	<<endl
	<<"Selecciona: ";cin>>opcion;
	
//	cin.get();
	system("cls");	
	
	switch (opcion){
	case 1://Menu libro
		while(opcion!=6){
		cout<<"Menu Libros"<<endl;
		cout<<"1. Ver libros"<<endl
			<<"2. Buscar libros"<<endl
			<<"3. Eliminar libro"<<endl
			<<"4. Agregar Libro"<<endl
			<<"5. Etiquetas"<<endl
			<<"6. Volver"
			
			<<endl
			<<"Selecciona: ";cin>>opcion;
			
		system("cls");
		switch (opcion){
		case 1:
		cout<<"Libros Disponibles: "<<endl;	
		///Contenido Actual
		for(Libro &x: vectorLibros)
			cout
			<<"Nombre Libro: " 	<<x.VerNombre()
			<<"  Id: "	<<x.VerID()
			<<endl; 
		
		
		cout<<endl<<endl<<"Presiona para volver";
		cin.ignore();
		cin.get();
		system("cls");
		break;
	case 2:
		///Buscar libro
		///Terminal			| Entrada
		cout<<"Buscar libro, indica ID: ";cin>>idLibro;
		
		///Buscar Libro		| Proceso
		
		resultadoLibros = navega.Buscar(palabra,Etiquetas,50);
		
		
		cout<<endl<<endl<<"Presiona para volver";
		cin.ignore();
		cin.get();
		system("cls");
		
		break;
	case 3:
		cout<<"ID a eliminar: ";cin>>idLibro;
		
		
		///Buscar Libro		| Proceso
		resultadoLibros = navega.Buscar(palabra,Etiquetas,50);
		
		/*if(it!= vectorLibros.end() ){
		///Muestra 			| Salida
		cout<<"Libro: "<<endl
			<<"Nombre: "<<(*(it)).VerNombre()
			<<endl 
			<<"ID: "<<(*(it)).VerID()
			<<endl;
		
		char borrar;
		cout<<"Confirmas Eliminarlo? s/n: ";cin>>borrar;
		if(borrar=='s'){
		///Uso del metodo 	| Proceso
		itBorrar = navega.Buscar(idLibro,vectorLibros);
		admin.EliminarLibro(itBorrar,vectorLibros);
		sistema.Guardar<Libro>(libros,vectorLibros);
		}
		}else{ cout<<endl<<"Codigo No existente";}
		
		*/
		cout<<endl<<endl<<"Presiona para volver";
		cin.ignore();
		cin.get();
		system("cls");
		
		break;
	case 4:
		cout<<"Agregar Libro...";
		cout<<"LIbros a agregar: ";cin>>Nlibros;
		///Uso del metodo	| Proceso
		if(!Nlibros==0){
			vectorLibros = admin.AgregarLibros(Nlibros);	
			sistema.Guardar<Libro>(libros,vectorLibros);
			vectorLibros = sistema.VerContenido<Libro>(libros,true);
			cout<<"Agregados Corectamente!"<<endl;
		}	
		cout<<endl<<endl<<"Presiona para volver";
		cin.ignore();
		cin.get();
		system("cls");
		
		break;
	case 5:
		opcion=-1;
		while(opcion!=5){
		cout<<"Menu Etiquetas"<<endl;
		cout<<"1. Ver Etiquetas"<<endl
			<<"2. Buscar Etiquetas"<<endl
			<<"3. Eliminar Etiquetas"<<endl
			<<"4. Agregar Etiquetas"<<endl
			<<"5. Volver"
			
			<<endl
			<<"Selecciona: ";cin>>opcion;
			
			system("cls");
			switch (opcion){
			case 1:
		
				cout<<"Etiquetas Existentes: "<<endl;
				cout<<"De Libros: "<<endl;
				Etiquetas = sistema.etiquetas(etiquetasLibros);
				c=0;
				for(Tags& x : Etiquetas)
					cout<<++c<<" ) "<<x.nombre<<endl;
				cout<<"De Alumnos: "<<endl;
				Etiquetas = sistema.etiquetas(TagsAlmunos);
				c=0;
				for(Tags& x : Etiquetas)
					cout<<++c<<" ) "<<x.nombre<<endl;
				
				cout<<endl<<endl<<"Presiona para volver";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			case 2:
				cout<<"Buscar Etiquetas...";
				cout<<endl<<endl<<"Presiona para volver";
				cin.ignore();
				cin.get();
				system("cls");
				break;
				
			case 3:
				cout<<"Eliminar Etiquetas...";
				cout<<endl<<endl<<"Presiona para volver";
				cin.ignore();
				cin.get();
				system("cls");
				break;
				
			case 4:
				cout<<"Agregar Etiquetas...";
				///Carga en memoria N elementos
				//VectorTags= vacio
				//bibliotecario.Agregar<Tags>(VectorTags)
				//VectorTags=lleno
				///Va al bin a cargarlo
				//sistema.Guardar<Tags>(VectorTags)
				cout<<endl<<endl<<"Presiona para volver";
				cin.ignore();
				cin.get();
				system("cls");
				break;
				
			case 5:
				///volver
				break;
			
			default:
				break;
			}///Fin case, etiquetas
			}///Fin While etiquetas
	case 6:
		//Volviendo
		break;
		
			
	default:
	break;
		
		}///Case
	}
		default:
		break;
			  
		}//Case
}///While Principal


	}
	


