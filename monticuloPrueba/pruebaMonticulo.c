#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"

int main(void)
{
    Monticulo m;
    int opc;
    printf("Vamos a crear un monticulo..:");
    iniciarMonticulo(&m);
    printf("Iniciado correctamente.\n");

    do{
        printf("====================================\n");
        printf("1.- Insertar elemento al monticulo\n");
        printf("2.- Eliminar mínimo del montículo\n");
        printf("3.- Salir del programa.\n");
        printf("====================================\n");
        printf("Seleciona una opcion...: ");
        scanf("%d",&opc);
        switch(opc)
        {
            case 1:
            tipoElemento elemento;
            printf("Introduce el elemento que quieres insertar al monticulo...:");
            scanf("%d",&elemento);
            insertarMonticulo(&m,elemento);
            printf("Insertado correctamente.\n");
            break;
            case 2:
            printf("No disponible aun.\n");
            break;
            case 3:
            printf("Saliendo........\n");
            break;
            default:
            printf("Error. Opcion introducida incorrecta.\n");
            break;
        }
    }while(opc!=3);
    return 0;
}