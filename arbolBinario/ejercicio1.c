#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main(void)
{ Arbol varArbol;

/* Creación arbol ejemplo de las transparencias de recorridos */
  varArbol = creaNodo('G');
  varArbol->izq=creaNodo('A');
  varArbol->der = creaNodo('Y');
  varArbol->izq->izq=creaNodo('A');
  varArbol->izq->der=creaNodo('D');
  varArbol->der->izq=creaNodo('R');
  varArbol->der->der=creaNodo('I');

/* Aplicación de recorridos al arbol ejemplo */

  printf("Recorrido en PRE_ORDEN: ");
  preOrden(varArbol);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(varArbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(varArbol);
  printf("\n");
  printf("Recorrido en AMPLITUD: ");
  amplitud(varArbol);
  printf("\n");

/* Comenzar a implementar y probar las funciones del ejercicio 2 ... y segunda parte del ejercicio 3 */




  return 1;
}

