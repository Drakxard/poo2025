
struct Tags{
	string nombre;
	vector<int>registrados;
};
template<typename T>
class Buscador{
	vector<Tags> Etiquetas;
public:
	Buscador(vector<Tags>Etiquetas){
		this->Etiquetas = Etiquetas;
	}
	vector<T>::const_iterator Buscar(string nombreBuscado, int Cantidad);

};