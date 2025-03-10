#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

void crea(particion P)
{
  tipoElemento i;
  for(i=0;i<MAXIMO;i++)
  {
    tipoCelda *nuevo;
    nuevo=malloc(sizeof(tipoCelda));
    if(nuevo==NULL)
    {
      return ;
    }

    nuevo->elemento=i;
    nuevo->sig=NULL;
    P[i].primero=nuevo;
    P[i].ultimo=nuevo;
  }
}

tipoConjunto buscar(tipoElemento x, particion P)
{

}

int unir(tipoConjunto x, tipoConjunto y, particion P)
{

}


void verParticion(particion P)
{ int i;
   tipoCelda *aux;
    for (i =0;i<MAXIMO;i++) {
         aux = P[i].primero;
         if (aux!=NULL)  printf("\n\nClase equivalencia representante %d: ",i);
        while (aux!=NULL)
        { printf("%d ",aux->elemento);
         aux=aux->sig;
        }
    }
}

void verClaseEquivalencia(tipoElemento x,particion P)
{ int representante;
  tipoCelda *aux;
  
    representante = buscar(x,P);
    printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x,representante);
    aux = P[representante].primero;
    while (aux)
        { printf(" %d ",aux->elemento);
          aux=aux->sig;
        }
    printf("\n\n");
}
