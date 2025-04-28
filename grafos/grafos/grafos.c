#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "grafos.h"
/**********************************************
/ Inicia correctamente directorio de vertices  /
/**********************************************/
void iniciar(tipoGrafo *g)
{
  int gEntrada[g->orden];
  
}

void profundidadMejorado(int v_inicio,tipoGrafo *g)
{

}

void amplitudMejorado(int v_inicio,tipoGrafo *g)
{

}

/* Ejercicio 2*/
int ordenTop1(tipoGrafo *grafo)
{
  int orden;
  pArco p;
  vertices v,w;
  iniciar(grafo);
  for(orden=1;orden<grafo->orden;orden++)
  {
    v=buscarVerticeGradoCeroNoOrdenTop(grafo);
    if(v==-1)
    {
      printf("Error grafo ciclo\n");
      fflush(stdout);
      return v;
    }
    else
    {
      grafo->directorio[v].ordenTop1=orden;
      p=grafo->directorio[w].lista;
      while(p!=NULL)
      {
        w=p->v;
        grafo->directorio[w].gradoEntrada=grafo->directorio[w].gradoEntrada-1;
        p=p->sig;
      }
    }
  }
}


int ordenTop2(tipoGrafo *grafo)
{
  vertices v,w;
  Cola c;
  iniciar(grafo);
  colaCreaVacia(&c);
  for(v=1;v<grafo->orden;v++)
  {
    if(grafo->directorio[v].gradoEntrada==0)
    {
      colaInserta(&c,w);
    }
  }

  orden=1;
  while(!colaVacia(&c))
  {
    v=colaSuprime(&c);
    grafo->directorio[v].ordenTop2=orden;
    orden++;
    pArco p=grafo->directorio[v].lista;
    while(p!=NULL)
    {
      w=p->vertice;
      grafo->directorio[w].gradoEntrada=grafo->directorio[w].gradoEntrada-1;
      if(grafo->directorio[w].gradoEntrada==0)
      {
        colaInserta(&c,w);
      }
      p=p->sig;
    }
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
