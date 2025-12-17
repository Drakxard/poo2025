vector<Libro> genLibros(int Nlibros){
    vector<Libro> resultado;
    string nom;
	int id;
	for(size_t i = 0; i<Nlibros; ++i){
        nom= "test "+to_string(i+1);
		id= rand()%(Nlibros*2)+1;
		Libro aux(id,nom);
        resultado.push_back(aux);
    }
    return resultado;
}
