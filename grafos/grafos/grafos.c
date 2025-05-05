#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "grafos.h"
/**********************************************
/ Inicia correctamente directorio de vertices  /
/**********************************************/
void iniciar(tipoGrafo *g)
{
  int i;
  arco *aux;

  for(i=0;i<g->orden;g++)
  {
    g->directorio[i].ordenTop=-1;
    g->directorio[i].gradoEntrada=0;
  }

  //Volvemos a recorrer la lista entera
  for(i=0;i<g->orden;i++)
  {
    aux=g->directorio[i].lista;
    while(aux!=NULL)
    {
      g->directorio[aux->v].gradoEntrada;
      aux=aux->sig;
    }
  }
  
}

void profundidadMejorado(int v_inicio,tipoGrafo *g)
{

}

void amplitudMejorado(int v_inicio,tipoGrafo *g)
{

}

/* Ejercicio 2*/
int ordenTop1(tipoGrafo *g)
{
  int vActual;
  pArco aux;
  int ordenTop;

  iniciar(g);
  for(ordenTop=1;ordenTop<g->orden;ordenTop++)
  {
    vActual=buscarVerticeGradoCeroNoOrdenTop(g);
    if(vActual==-1)
    {
      return -1;
    }

    g->directorio[vActual].ordenTop=ordenTop;
    aux=g->directorio[vActual].lista;
    while(aux!=NULL)
    {
      g->directorio[aux->v].gradoEntrada--;
      aux=aux->sig;
    }
  }
  return 0;
}

int buscarVerticeGradoCeroNoOrdenTop(tipoGrafo *g)
{ 
  int i;
  for(i=0;i<g->orden;i++)
  {
    if((g->directorio[i].ordenTop==-1)&&(g->directorio[i].gradoEntrada==0))
    {
      return i;
    }
  }
  return -1;
}


int ordenTop2(tipoGrafo *g)
{
  int vActual;
  pArco aux;
  int i;
  Cola c;
  iniciar(g);
  colaCreaVacia(&c);

  for(i=0;i<g->orden;i++)
  {
    if(g->directorio[i].gradoEntrada==0)
    {
      colaInserta(&c,i);
    }
    i=1;
    while(!colaVacia(&c))
    {
      vActual=colaSuprime(&c);
      g->directorio[i].ordenTop=i;
      i++;
      aux=g->directorio[vActual].lista;
      while(aux!=NULL)
      {
        g->directorio[aux->v].gradoEntrada--;
        if(g->directorio[aux->v].gradoEntrada==0)
        {
          colaInserta(&c,aux->v);
        }
        aux=aux->sig;
      }
    }
    if(i<=g->orden)
    {
      return -1;
    }
    return 0;
  }
  
}
/******************************************************************************/
/* Recorrido en PROFUNDIDAD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/*********************************************************************************/
void profundidad(int v_inicio,tipoGrafo * grafo)
{ int w;
  pArco  p;
  printf("%d ",v_inicio);
  grafo->directorio[v_inicio].alcanzado=1;
  p = grafo->directorio[v_inicio].lista;
  while (p!=NULL)
  { w=p->v;
    if (!grafo->directorio[w].alcanzado)
        profundidad(w,grafo);
    p = p->sig;
  }
}
/************************************************************************************************/
/* Recorrido en AMPLITUD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/************************************************************************************************/
void amplitud(int v_inicio,tipoGrafo *grafo)
{ int w;
  pArco  p;
  Cola c;

  colaCreaVacia(&c);
  colaInserta(&c,v_inicio);
  while (!colaVacia(&c))  {
	  w =colaSuprime(&c);
    if (!grafo->directorio[w].alcanzado) {
		  printf("%d ",w);
	    grafo->directorio[w].alcanzado=1;
      p =grafo->directorio[w].lista;
 		  while (p!=NULL){
			  w = p->v;
			  colaInserta(&c,w);
			  p = p->sig;
		  }
	  }
  }
	  
}
/**********************************************************************************************/
/* Función auxiliar para ver el contenido de la estructura que representa un grafo en memoria */
/**********************************************************************************************/
void verGrafo(tipoGrafo *g)
{  int i;
   pArco p;

   printf("\nGrafo  (Orden %d)\n\n",g->orden);
   printf("       alc gEnt oTop dist peso ant \n");
   printf("     +----+----+----+----+----+----+\n");

   for(i=1;i<=g->orden;i++)
   {  
    printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado,
    g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);
    if (g->directorio[i].distancia == INF) printf("  * |");
    else   printf(" %2d |", g->directorio[i].distancia);
    if (g->directorio[i].peso == INF) printf("  * |");
    else   printf(" %2d |", g->directorio[i].peso);
    printf(" %2d |",g->directorio[i].anterior);
    p = g->directorio[i].lista;
    while (p != NULL)
    {
      printf(" ->%2d", p->v);	// Grafos no ponderados
      //printf(" ->%2d, %2d", p->v, p->peso); // Grafos ponderados
      p = p->sig;
    }
    printf("\n");
   }
   printf("     +----+----+----+----+----+----+\n\n");
}

/****************************************
**              EJERCICIO 4             *
*****************************************
*/

//Con solo pasarlo a pseudocodigo es suficiente.
void aceptarArista()
{
  //Es un grafo dirigido. Tiene que aparecer en dos listas de adyacencia

}

tipoGrafo * prim1(tipoGrafo *grafo)
{


}

tipoGrafo * prim2(tipoGrafo *grafo)
{


}


tipoGrafo * kruskal(tipoGrafo *grafo)
{


}

//A veces preguntan solo aceptar arista, otras el arbol de expansion,
//otras preguntan como tiene que ser el tipo de dato monticulo
//
