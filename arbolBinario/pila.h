#ifndef __PILA_H
#define __PILA_H
#include "arbol.h"

#ifndef __TIPO_CELDA
#define __TIPO_CELDA
typedef struct tipoCelda {
	Arbol elemento;
	struct tipoCelda * sig;
	} tipoCelda;
#endif

typedef tipoCelda* Pila;

int pilaCreaVacia(Pila *p);
int pilaVacia(Pila *p);
int pilaInserta(Pila *p, Arbol elemento);
Arbol pilaSuprime(Pila *p);

#endif