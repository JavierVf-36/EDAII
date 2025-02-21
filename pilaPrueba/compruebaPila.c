#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(void){
    Pila c;

    int opc;
    do{
        printf("===========================\n");
        printf("    COMPRUEBA PILA\n");
        printf("===========================\n");
        printf("1.- Crear pila vacia.\n");
        printf("2.- Comprobar pila vacia.\n");
        printf("3.- Insertar elemento en pila.\n");
        printf("4.- Suprimir elemento de la pila.\n");
        printf("5.- Salir.\n");
        printf("Seleccion..: "); scanf("%d",&opc);

        switch(opc){
            case 1:
                int exito=pilaCreaVacia(&c);
                if(exito){
                    printf("Pila creada con exito.\n");
                }else{
                    printf("Error en la creacion de la pila.\n");
                    return 1;
                }       
            break;
            case 2:
                int vacia=pilaVacia(&c);
                if(vacia==1){
                    printf("La pila esta vacia ahora mismo.\n");
                }else if(vacia==0){
                    printf("La pila NO esta vacía.\n");
                }else if(vacia==2){
                    printf("La pila no se creo correctamente.\n");
                    return 1;
                }
            break;
            case 3:
            tipoElemento elemento;
            printf("Introduce el elemento a insertar en la pila:");
            scanf("%d",&elemento);
            int insertado=pilaInserta(&c,elemento);
            if(insertado==1){
                printf("Introducido en la pila con exito.\n");
            }else{
                printf("No se ha introducido el valor correctamente en la pila.\n");
            }
            break;
            case 4:
            tipoElemento contenido;

            if(pilaVacia(&c)){
                printf("La pila esta vacia ahora mismo.\n");
            }else{
               contenido=pilaSuprime(&c);
                printf("El elemento obtenido de la pila es %d\n",contenido); 
            }
            break;
            case 5:
            printf("Saliendo......\n");
            break;
            default:
            printf("Error. Opcion incorrecta.\n");
            break;
        }
    }while(opc!=5);
    return 0;
}