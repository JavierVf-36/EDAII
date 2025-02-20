#ifndef __COLA_H
#define __COLA_H
#include "arbol.h"

#ifndef __TIPO_CELDA
#define __TIPO_CELDA
typedef struct tipoCelda {
	Arbol elemento;
	struct tipoCelda * sig;
	} tipoCelda;
#endif

typedef struct {
    tipoCelda *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);
int colaVacia(Cola *c);
int colaInserta(Cola *c, tipoNodo * elemento);
tipoNodo * colaSuprime(Cola *c);
#endif
