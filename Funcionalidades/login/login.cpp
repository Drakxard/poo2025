
#include "login.h"

int BuscarDniEnBibliotecarios(int dni, vector<Bibliotecario>& v){
    system sistema;
    int Esta = sistema.Verificar_Existencia_Vector<Bibliotecario>(dni, v);
    if(Esta != -1){
        return Esta;
    }
    return -1;
}
int BuscarDniEnAlumnos(int dni, vector<Alumno>& v){
    system sistema;
    int Esta = sistema.Verificar_Existencia_Vector<Alumno>(dni, v);
    if(Esta != -1){
        return Esta;
    }
    return -1;
}





Bibliotecario ObjetoCorrespondienteBibliotecario(int posBibliotecario, vector<Bibliotecario>&v ){
    // encontrado
    Bibliotecario resultado = v[posBibliotecario];
    string nombre= resultado.VerNombre();
    int codigo = resultado.VerId(); 
	const char *nom = nombre.c_str();
	Bibliotecario admin(codigo,nom); 
    return admin;
}


Alumno ObjetoCorrespondienteAlumno(int posAlumno, vector<Alumno>&v ){
    // encontrado
    Alumno resultado = v[posAlumno];
    string nombre= resultado.VerNombre();
    int codigo = resultado.VerId(); 
	const char *nom = nombre.c_str();
	Alumno usuario(codigo,nom); 
    return usuario;
}

