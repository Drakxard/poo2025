#ifndef TAGS_H
#define TAGS_H
#include <iostream>
#include <cstring>
using namespace std;
class Tags {
	size_t id;
	char nombre[49]; 
	
public:
	Tags(){};
	Tags(size_t id, const char *nombre);
	int VerID() const;
	const char *VerNombre() const;
	void CambiarNombre(const char *NuevoNombre);
	void Cambiar_Id( int nuevo_id);
};

#endif

