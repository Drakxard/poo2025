#include "Historial.h"

//template <typename S>
//void Historial::Ver_Historial(int actual, vector<S>& v){	
//	auto encontrado = find_if(v.begin(), v.end(), [actual](const S& p){
//		return p.VerID() == actual;
//	});
//	
//	if(encontrado != v.end()){
//		int pos = encontrado - v.begin();
//		
//		const vector<int>& leidos = v[pos].Ver_Leidos();
//		
//		if(leidos.size() > 0){
//			for(int i = 0; i < leidos.size(); ++i){
//				cout << "' " << leidos[i] << " '" << endl;
//			}
//		}else{
//			cout << "No ha leído libros aún" << endl;
//		}
//	}else{
//		cout << "Persona no encontrada." << endl;
//	}
//}

//void Historial::Ver_Historial_libros(int actual, vector<Libro>& v){	
//	
//	auto encontrado = find_if(v.begin(), v.end(), [actual](const Libro& l){
//		return l.VerID() == actual;
//	});
//	
//	if(encontrado != v.end()){
//		int pos = encontrado - v.begin();
//		
//		const vector<int>& lectores = v[pos].Ver_Lectores();
//		
//		if(lectores.size() > 0){
//			for(int i = 0; i < lectores.size(); ++i){
//				cout << "' " << lectores[i] << " '" << endl;
//			}
//		}else{
//			cout << "No ha tenido lectores aún" << endl;
//		}
//	}else{
//		cout << "Libro no encontrado." << endl;
//	}
//}
	   
