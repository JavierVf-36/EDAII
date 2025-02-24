#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{ tipoNodo * nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else
  { 	nuevo->info=info;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
   }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz)
{ 
  Cola c;
  tipoNodo * actual;
  colaCreaVacia(&c);
  if(raiz!=NULL){
    colaInserta(&c,raiz);
  }

  while(!colaVacia(&c)){
    actual=colaSuprime(&c);
    printf("%c ",actual->info);
    if(actual->izq!=NULL){
      colaInserta(&c,actual->izq);
    }
    if(actual->der!=NULL){
      colaInserta(&c,actual->der);
    }
  }
}

/*
***************************************
* RECORRIDOS EN PROFUNIDAD RECURSIVOS *
***************************************
*/

void preOrden(Arbol raiz)
{ if (raiz!=NULL)
  { printf("%c ",raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{ if (raiz!=NULL)
  { enOrden(raiz->izq);
    printf("%c ",raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{ if (raiz!=NULL)
  { postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ",raiz->info);
  }
}

/*
*************************
* FUNCIONES EJERCICIO 2 *
*************************
*/

int altura(Arbol raiz)
{
  if(raiz!=NULL){
    int resIzq=altura(raiz->izq);
    int resDer=altura(raiz->der);
    if(resIzq==resDer){
      return resIzq+1;
      //PODRIA VALER EL DE LA DERECHA
    }else if(resIzq>resDer){
      return resIzq+1;
    }else if(resDer>resIzq){
      return resDer+1;
    }
  }else{
    return 0;
  }
}

int numNodos(Arbol raiz)
{
  if(raiz!=NULL)
  {
    int resIzq=numNodos(raiz->izq);
    int resDer=numNodos(raiz->der);
    if(resIzq==0&&resDer==0)
    {
      return 1;
    }else
    {
      return resIzq+resDer+1;
    }
   
  }else
  {
    return 0;
  }
}

Arbol anula(Arbol raiz)
{
  if(raiz!=NULL)
  {
    Arbol hojaIzq=anula(raiz->izq);
    Arbol hojaDer=anula(raiz->der);
    if(hojaIzq==NULL&&hojaDer==NULL)
    {
      free(raiz);
      return NULL;
    }
  }
  else
  {
    return NULL;
  }
}

int sustituye(Arbol raiz, char valor, char cambio)
{
  if(raiz!=NULL)
  {
    int resIzq=sustituye(raiz->izq,valor,cambio);
    int resDer=sustituye(raiz->der,valor,cambio);
    int cambios;
    if(resIzq==-1&&resDer==-1)
    {
      cambios=0;
    }else if(resDer>resIzq)
    {
      cambios=resDer;
    }else if(resIzq>resDer)
    {
      cambios=resIzq;
    }else if(resDer==resIzq)
    {
      cambios=resIzq;
      //PODRIA SER resDer TAMBIEN
    }

    if(raiz->info==valor)
    {
      raiz->info=cambio;
      cambios+=1;
    }
    return cambios;
  }
  else
  {
    return -1;
  }
}

int numNodosHoja(Arbol raiz)
{
  if(raiz!=NULL)
  {
    int resIzq=numNodosHoja(raiz->izq);
    int resDer=numNodosHoja(raiz->der);
    int hojas=0;
    if(resIzq==-1&&resDer==-1)
    {
      return 1;
    } 
    
    if(resIzq!=-1)
    {
      hojas=hojas+resIzq;
    }

    if(resDer!=-1)
    {
      hojas=hojas+resDer;
    }
    return hojas;
  }
  else
  {
    return -1;
  }
}

int numNodosInternos(Arbol raiz)
{
  if(raiz!=NULL)
  {
    int resIzq=numNodosInternos(raiz->izq);
    int resDer=numNodosInternos(raiz->der);
    int numNodosInternos=0;
    if(resIzq==-1&&resDer==-1)
    {
      //NO SOY NODO INTERNO, NO VALGO
      return 0;
    }else if(resIzq!=-1||resDer!=-1)
    {
      if(resIzq!=-1){
        numNodosInternos=numNodosInternos+resIzq; 
      }

      if(resDer!=-1){
        numNodosInternos=numNodosInternos+resDer;
      }
      return numNodosInternos+1;
    }
  }
  else
  {
    return -1;
  }
}

int numHijoUnico(Arbol raiz)
{
  if(raiz!=NULL)
  {
    int resIzq=numHijoUnico(raiz->izq);
    int resDer=numHijoUnico(raiz->der);
    int numHijosUnicos=0;
    if(resIzq==-1&&resDer==0)
    {
      numHijosUnicos=numHijosUnicos+resDer;
      return numHijosUnicos+1;
    }
    else if(resIzq==0&&resDer==-1)
    {
      numHijosUnicos=numHijosUnicos+resIzq;
      return numHijosUnicos+1;
    }else if(resIzq==-1&&resDer==-1){
      return 0;
    }
    else
    {
      if(resIzq>resDer){
        return resIzq+1;
      }
      else if(resDer>resIzq)
      {
        return resDer+1;
      }
      else if(resDer==resIzq)
      {
        return resDer+1;
        //SE PUEDE DEVOLVER TAMBIEN EL DE LA IZQUIERDA
      }
    }
  }
  else
  {
    return -1;
  }
}