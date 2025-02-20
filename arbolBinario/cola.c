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
        return 0;
    }

    if(c->fondo==NULL&&c->frente==NULL){
        return 1;
    }else{
        return 0;
    }
}

int colaInserta(Cola *c, tipoNodo * elemento) {
    tipoCelda *nuevo = malloc(sizeof(tipoCelda));

    if(c==NULL){
        return 0;
    }

    if (nuevo == NULL) {
        return 0; 
    }

    if(elemento==NULL){
        free(nuevo);
        return 0;
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

    return 1;
}

tipoNodo * colaSuprime(Cola *c){
    if (c == NULL || c->frente == NULL||c->fondo==NULL) {
        printf("Error: Intento de suprimir en una cola vacía.\n");
        return NULL;
    }

    tipoCelda * aBorrar=c->frente;
    tipoNodo * elemento = aBorrar->elemento;
    c->frente = aBorrar->sig;

    if (c->frente == NULL) {  
        c->fondo = NULL;
    }

    // free(aBorrar); // Esta linea hace "double free or corruption (out)"
    return elemento;
}

