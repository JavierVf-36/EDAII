#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main(void)
{ Arbol varArbol;

/* Creación arbol ejemplo de las transparencias de recorridos */
  varArbol = creaNodo('A');
  varArbol->izq=creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq=creaNodo('D');
  varArbol->izq->der=creaNodo('E');
  varArbol->der->izq=creaNodo('F');
  varArbol->der->der=creaNodo('G');
  varArbol->izq->der->izq=creaNodo('H');
  varArbol->der->der->der=creaNodo('J');

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
  printf("--------------------------------\n");
  printf("Implementacion de las funciones\n");
  printf("--------------------------------\n");
  printf("Altura del arbol: %d\n",altura(varArbol)-1);
  printf("Numero de nodos: %d\n", numNodos(varArbol));
  printf("Valor de sustituir: 'J' por 'D' (letras cambiadas): %d\n", sustituye(varArbol,'J','D'));
  printf("Recorrido en amplitud de comprobacion: ");
  amplitud(varArbol);
  printf("\n");
  printf("Numero de hojas del arbol: %d\n", numNodosHoja(varArbol));
  printf("Numero de nodos internos: %d\n",numNodosInternos(varArbol));
  printf("Numero de hijos unicos: %d\n", numHijoUnico(varArbol)-1);
  /*
  if(anula(varArbol)==NULL){
    printf("Anulado con exito.\n"); 
  }else
  {
    printf("Error al anular arbol.\n");
  }
  */

  return 1;
}

