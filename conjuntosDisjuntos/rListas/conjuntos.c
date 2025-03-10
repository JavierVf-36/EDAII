#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

void crea(particion P)
{
  tipoElemento i;
  tipoCelda *nuevo;
  for(i=0;i<MAXIMO;i++)
  {
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
  tipoConjunto i;
  tipoCelda * aux;
  for(i=0;i<MAXIMO;i++)
  {
    aux=P[i].primero;
    while(aux!=NULL)
    {
      if(aux->elemento==x)
      {
        return i;
      }
        aux=aux->sig;
    } 
  }
} 

int unir(tipoConjunto x, tipoConjunto y, particion P)
{
  if(P[x].primero!=NULL)
  {
    P[x].ultimo->sig=P[y].primero;
    P[x].ultimo=P[y].ultimo;
    P[y].primero=NULL;
    P[y].ultimo=NULL;
    return 1;
  }
  else
  {
    return 0;
  }
}


void verParticion(particion P)
{ int i;
   tipoCelda *aux;
    for (i =0;i<MAXIMO;i++) {
         aux = P[i].primero;
         if (aux!=NULL)  printf("\nClase equivalencia representante %d: ",i);
        while (aux!=NULL)
        { printf("%d ",aux->elemento);
         aux=aux->sig;
        }
    }
}


//Se mete en el representante del que has puesto, y muestra todos los nodos que haya
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
    printf("\n");
}
