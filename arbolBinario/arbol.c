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
    if(resIzq==-1&&resDer!=-1)
    {
      return resDer+1;
    }
    else if(resIzq!=-1&&resDer==-1)
    {
      return resIzq+1;
    }else if(resIzq==-1&&resDer==-1){
      return 0;
    }
    else
    {
      return resIzq+resDer;
    }
  }
  else
  {
    return -1;
  }
}

Arbol buscarMax(Arbol raiz)
{
  if(raiz!=NULL)
  {
    Arbol resIzq=buscarMax(raiz->izq);
    Arbol resDer=buscarMax(raiz->der);

    if(resIzq==NULL&&resDer==NULL)
    {
      return raiz;
    }else if(resIzq==NULL&&resDer!=NULL)
    {
      return resDer;
    }else if(resIzq!=NULL&&resDer==NULL)
    {
      return resIzq;
    }
    else
    {
      if(resIzq->info>resDer->info){
        return resIzq;
      }else if(resDer->info>resIzq->info)
      {
        return resDer;
      }else{
        return resDer;
        //PUEDE SER resIzq
      }
    }
  }
  else
  {
    return NULL;
  }
}

Arbol buscarMin(Arbol raiz) {

  if(raiz!=NULL)
  {
    Arbol resIzq = buscarMin(raiz->izq);
    Arbol resDer = buscarMin(raiz->der);

    Arbol menor = raiz; 

    if (resIzq != NULL && resIzq->info < menor->info) {
        menor = resIzq;
    }
    if (resDer != NULL && resDer->info < menor->info) {
        menor = resDer;
    }
    return menor;
  }
  else
  {
    return NULL;
  }
  
}

int similares(Arbol raiz1, Arbol raiz2)
{
  if(raiz1!=NULL&&raiz2!=NULL)
  {
    int numNodos1,numNodos2;
    int numHojas1,numHojas2;
    int numInternos1,numInternos2;
    int hijosunicos1,hijosunicos2;

    numNodos1=numNodos(raiz1);
    numNodos2=numNodos(raiz2);
    if(numNodos1!=numNodos2)
    {
      return 0;
    }

    numHojas1=numNodosHoja(raiz1);
    numHojas2=numNodosHoja(raiz2);

    if(numHojas1!=numHojas2)
    {
      return 0;
    }

    numInternos1=numNodosInternos(raiz1);
    numInternos2=numNodosInternos(raiz2);

    if(numInternos1!=numInternos2)
    {
      return 0;
    }

    hijosunicos1=numHijoUnico(raiz1);
    hijosunicos2=numHijoUnico(raiz2);

    if(hijosunicos1!=hijosunicos2)
    {
      return 0;
    }

    return 1;
  }
  else
  {
    return 0;
  }
}

int equivalentes(Arbol raiz1,Arbol raiz2)
{
  if(raiz1!=NULL&&raiz2!=NULL)
  {
    if(!similares(raiz1,raiz2))
    {
      return 0;
    }

    return amplitudEquivalente(raiz1,raiz2);
  }
  else
  {
    return 0;
  }
}

int amplitudEquivalente(Arbol raiz1, Arbol raiz2)
{ 
  Cola c;
  tipoNodo * actual;
  colaCreaVacia(&c);
  if(raiz1!=NULL){
    colaInserta(&c,raiz1);
  }

  Cola c2;
  tipoNodo *actual2;
  colaCreaVacia(&c2);
  if(raiz2!=NULL)
  {
    colaInserta(&c2,raiz2);
  }

  while(!colaVacia(&c)&&!colaVacia(&c2)){
    actual=colaSuprime(&c);
    actual2=colaSuprime(&c2);

    if(actual->info!=actual2->info)
    {
      return 0;
    }

    if(actual->izq!=NULL){
      colaInserta(&c,actual->izq);
    }
    if(actual->der!=NULL){
      colaInserta(&c,actual->der);
    }

    if(actual2->izq!=NULL){
      colaInserta(&c2,actual2->izq);
    }
    if(actual2->der!=NULL){
      colaInserta(&c2,actual2->der);
    }
  }

  if(!colaVacia(&c)||!colaVacia(&c2))
  {
    return 0;
  }

  return 1;
}

Arbol especular(Arbol raiz) {
  if (raiz == NULL) {
      return NULL;
  }

  // Intercambiar subárboles izquierdo y derecho
  Arbol temp = raiz->izq;
  raiz->izq = raiz->der;
  raiz->der = temp;

  // Llamada recursiva para los subárboles
  especular(raiz->izq);
  especular(raiz->der);

  return raiz; 
}
