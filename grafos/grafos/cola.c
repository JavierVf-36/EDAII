#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int colaCreaVacia(Cola *c){
    c=malloc(sizeof(Cola));
    if(c==NULL){
        return 1;
    }

    c->fondo=NULL;
    c->frente=NULL;
    return 0;
}

int colaVacia(Cola *c){

    if(c==NULL){
        return -2;
    }

    if(c->fondo==NULL||c->frente==NULL){
        return 0;
    }else{
        return 1;
    }
}

int colaInserta(Cola *c, tipoElemento elemento) {
    tipoCelda *nuevo = malloc(sizeof(tipoCelda));

    if (nuevo == NULL) {
        return 1; 
    }

    nuevo->elemento = elemento;
    nuevo->sig = NULL;

    if (c->fondo == NULL) {
        c->frente = nuevo;
        c->fondo = nuevo;
    } else {
        c->fondo->sig = nuevo;  
        c->fondo = nuevo;  
    }

    return 0;
}

tipoElemento colaSuprime(Cola *c){
    tipoElemento elemento;
    tipoCelda *aBorrar;
    elemento=c->frente->elemento;
    aBorrar=c->frente;
    c->frente=c->frente->sig;
    free(aBorrar);
    if(c->frente==NULL){
        c->fondo=NULL;
    }
    return elemento;
}
