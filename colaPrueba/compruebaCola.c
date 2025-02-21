#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main(void){
    Cola c;

    int opc;
    do{
        printf("===========================\n");
        printf("    COMPRUEBA COLA\n");
        printf("===========================\n");
        printf("1.- Crear cola vacia.\n");
        printf("2.- Comprobar cola vacia.\n");
        printf("3.- Insertar elemento en cola.\n");
        printf("4.- Suprimir elemento de la cola.\n");
        printf("5.- Salir.\n");
        printf("Seleccion..: "); scanf("%d",&opc);

        switch(opc){
            case 1:
                int exito=colaCreaVacia(&c);
                if(exito==0){
                    printf("Cola creada con exito.\n");
                }else{
                    printf("Error en la creacion de la cola.\n");
                    return 1;
                }       
            break;
            case 2:
                int vacia=colaVacia(&c);
                if(vacia==0){
                    printf("La cola esta vacia ahora mismo.\n");
                }else if(vacia==1){
                    printf("La cola NO esta vacía.\n");
                }else if(vacia==2){
                    printf("La cola no se creo correctamente.\n");
                    return 1;
                }
            break;
            case 3:
            tipoElemento elemento;
            printf("Introduce el elemento a insertar en la cola:");
            scanf("%d",&elemento);
            int insertado=colaInserta(&c,elemento);
            if(insertado==0){
                printf("Introducido en la cola con exito.\n");
            }else{
                printf("No se ha introducido el valor correctamente en la cola.\n");
            }
            break;
            case 4:
            tipoElemento contenido;

            if(!colaVacia(&c)){
                printf("La cola esta vacia ahora mismo.\n");
            }else{
               contenido=colaSuprime(&c);
            printf("El elemento obtenido de la cola es %d\n",contenido); 
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