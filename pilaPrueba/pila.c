#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int pilaCreaVacia(Pila *p){
    (*p)=NULL;
    return 1;
}

int pilaVacia(Pila *p){
    if(*p==NULL){
        return 1;
    }else{
        return 0;
    }
}

int pilaInserta(Pila *p, tipoElemento elemento){
    tipoCelda *nuevo;
    tipoCelda * temp;
    nuevo=malloc(sizeof(tipoCelda));
    if(nuevo==NULL){
        return 0;
    }
    temp=*p;
    *p=nuevo;
    nuevo->sig=temp;
    nuevo->elemento=elemento;
    return 1;
}

tipoElemento pilaSuprime(Pila *p){
    tipoElemento elemento;
    tipoCelda *aBorrar;
    aBorrar=*p;
    *p=aBorrar->sig;
    elemento=aBorrar->elemento;
    free(aBorrar);
    return elemento;
}