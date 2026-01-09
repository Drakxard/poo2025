
template<typename K>
class System{
public:
    System(){};
    void Guardar(string nombreArhivo, vector<K> &A_Guardar);
    vector<K> VerContenido(string nombreArchivo,bool crear);
    bool actualizar_disponibilidad( string nombreArchivo, int id);

};