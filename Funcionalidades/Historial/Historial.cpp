#include "../bibliotecario/bibliotecario.h"
#include "../alumno/alumno.h"
#include "../libro/libro.h"
#include "Historial.h"






bool Historial::AgregarNuevoRegistro(int IdBibliotecario){return true;}//se debe agregar automaticamente                                                          //una vez prestado el libro
bool Historial::EliminarRegistro(int IdRegistro){return true;};//Si quiere eliminar un libro o
<<<<<<< Updated upstream
                                                    //un alumno
=======
//un alumno
>>>>>>> Stashed changes

template <typename S>
void Historial::Ver_Historial(int actual, vector<S>& v){	
	auto encontrado = find_if(v.begin(), v.end(), [actual](const S& p){
		return p.VerID() == actual;
	});
	if(encontrado != v.end()){
		int pos= encontrado-v.begin();
		if(v[pos].Ver_Leidos.size() > 0){
			//		Mostramos los libros si es que ha leído
			for(int i=0;i<v[actual].Leidos.size();++i){
				cout<<"' "<<v[actual].Leidos[i]<<" '"<<endl;
			}
		}else{
			cout<<"No ha leído libros aún"<<endl;
		}
	}
<<<<<<< Updated upstream
}
	
void Historial::Ver_Historial_libros(int actual, vector<Libro>& v){	
	
	auto encontrado = find_if(v.begin(), v.end(), [actual](const Libro& l){
		return l.VerID() == actual;
	});
	
	if(encontrado != v.end()){
		int pos= encontrado-v.begin();
		if(v[pos].Ver_Lectores().size() > 0){
			//Mostramos los libros si es que ha leído
			for(int i = 0; i < v[pos].Ver_Lectores().size(); ++i){
				cout << "' " << v[pos].Ver_Lectores()[i] << " '" << endl;
			}
		}else{
			cout<<"No ha tenido lectores aún"<<endl;
		}
	}
=======
>>>>>>> Stashed changes
}

//void Historial::Ver_Historial_libros(int actual, vector<Libro>& v){	
//	
//	auto encontrado = find_if(v.begin(), v.end(), [actual](const Libro& l){
//		return l.VerID() == actual;
//	});
//	
//	if(encontrado != v.end()){
//		int pos= encontrado-v.begin();
//		if(v[pos].Ver_Leidos().size() > 0){
//			//Mostramos los libros si es que ha leído
//			for(int i = 0; i < v[pos].Ver_Leidos().size(); ++i){
//				cout << "' " << v[pos].Ver_Leidos()[i] << " '" << endl;
//			}
//		}else{
//			cout<<"No ha tenido lectores aún"<<endl;
//		}
//	}
//}
