#ifndef BLOQUES_H
#define BLOQUES_H

#include <iostream>
#include <cstring>
#include <vector>
#include "../system/system.h"
#include "../login/login.h"

struct Bloque{
   
	uint32_t CantidadElementos=0;
	uint32_t SiguienteBloque=0;
	uint32_t Elementos[1022];
};

class Bloques{
    System* sistema;
public:
	size_t AgregarNuevoBloque();
	bool AgregarNuevoElemento(size_t IdTag, size_t idLibro);
    vector<size_t> LeerTodosLosElementos(size_t IdTag);
};

#endif
