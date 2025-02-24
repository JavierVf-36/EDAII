#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main(void)
{ Arbol varArbol;


/* Creación arbol ejemplo de las transparencias de recorridos */
  /*varArbol = creaNodo('A');
  varArbol->izq=creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq=creaNodo('D');
  varArbol->izq->der=creaNodo('E');
  varArbol->der->izq=creaNodo('F');
  varArbol->der->der=creaNodo('G');
  varArbol->izq->der->izq=creaNodo('H');
  varArbol->der->der->der=creaNodo('J');
  varArbol->izq->der->izq->der=creaNodo('P');
  varArbol->der->izq->izq=creaNodo('X');
  varArbol->der->der->der->izq=creaNodo('N');
  */
    varArbol = creaNodo('A');

    varArbol->izq = creaNodo('B');
    varArbol->der = creaNodo('C');

    varArbol->izq->izq = creaNodo('D');
    varArbol->izq->der = creaNodo('E');
    varArbol->der->izq = creaNodo('F');
    varArbol->der->der = creaNodo('G');

    varArbol->izq->izq->izq = creaNodo('H');
    varArbol->izq->izq->der = creaNodo('I');
    varArbol->izq->der->izq = creaNodo('Z');
    varArbol->izq->der->der = creaNodo('K');

    varArbol->der->izq->izq = creaNodo('L');
    varArbol->der->izq->der = creaNodo('M');
    varArbol->der->der->izq = creaNodo('N');
    varArbol->der->der->der = creaNodo('O');

    Arbol varArbol2;
    varArbol2 = creaNodo('G');
    varArbol2 = creaNodo('A');

    varArbol2->izq = creaNodo('B');
    varArbol2->der = creaNodo('C');

    varArbol2->izq->izq = creaNodo('D');
    varArbol2->izq->der = creaNodo('I');
    varArbol2->der->izq = creaNodo('F');
    varArbol2->der->der = creaNodo('G');

    varArbol2->izq->izq->izq = creaNodo('H');
    varArbol2->izq->izq->der = creaNodo('I');
    varArbol2->izq->der->izq = creaNodo('Z');
    varArbol2->izq->der->der = creaNodo('K');

    varArbol2->der->izq->izq = creaNodo('L');
    varArbol2->der->izq->der = creaNodo('M');
    varArbol2->der->der->izq = creaNodo('N');
    varArbol2->der->der->der = creaNodo('O');



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
  printf("Numero de nodos con hijo unico: %d\n", numHijoUnico(varArbol));

  Arbol nodomax=buscarMax(varArbol);
  printf("Valor maximo del arbol: %c\n",nodomax->info);
  nodomax=buscarMin(varArbol);
  printf("Valor minimo del arbol: %c\n", nodomax->info);
  if(similares(varArbol,varArbol2))
  {
    printf("Los dos arboles introducidos son similares.\n");
  }
  else
  {
    printf("Los dos arboles introducidos no son similares.\n");
  }

  if(equivalentes(varArbol,varArbol2))
  {
    printf("Los dos arboles introducidos son equivalentes.\n");
  }
  else
  {
    printf("Los dos arboles introducidos no son equivalentes.\n");
  }

  Arbol especulado=especular(varArbol);
  printf("AMPLITUD DEL ARBOL ESPECULADO: ");
  if(especulado!=NULL)
  {
    amplitud(especulado);
  }
  else
  {
    printf("No existe.\n");
  }
  
  printf("\n")

  if(anula(varArbol)==NULL){
    printf("Anulado con exito.\n"); 
  }else
  {
    printf("Error al anular arbol.\n");
  }
 

  return 1;
}

