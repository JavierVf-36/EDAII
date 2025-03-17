#include "conjuntos.h"
#include <stdio.h>

/*
* CUANDO LO REPASES: DA VIOLACION DE SEGMENTO (genial)
*
*
*/


void crea(particion P)
{
    for(int i=0;i<MAXIMO;i++)
    {
        P[i]=i;
    }
}

tipoConjunto buscar(tipoElemento x, particion P)
{
    if(P[x]==x)
    {
        return x;
    }
    return buscar(P[x],P);
}


//Dentro de los arboles no se guarda el representante, sino el padre, (sino, no seria un arbol)
//Al llamar a buscar, al ser recursiva se obtiene bien el representante de cada nodo del arbol
int unir(tipoConjunto x, tipoConjunto y, particion P)
{   
    P[y]=x;
    return 1;
}

/**********************
*   UNION POR TAMAÑO  *
***********************
* Los representantes almacenan con valor negativo el numero de elementos de su arbol
* A la hora de hacer una operacion de union, se pone el representante, con menos elementos
* debajo del representante de mas elementos (como hijo suyo). En caso de empate, puede ser
* cualquiera, normalmente el de la izquierda.
*/

void creaTamanoOAltura(particion P)
{
    for(int i=0;i<MAXIMO;i++)
    {
        P[i]=-1;
    }
}

int buscarPorTamanoOAltura(tipoElemento x, particion P)
{
    if(P[x]<=-1)
    {
        return x;
    }
    return buscar(P[x],P);
}

int unionPorTamano(tipoElemento x, tipoElemento y, particion P)
{
    if(P[x]<P[y])
    {
        P[x]=P[x]+P[y];
        P[y]=x;
    }
    else
    {
        P[y]=P[y]+P[x];
        P[x]=y;
    }
}


/**********************
*   UNION POR ALTURA  *
***********************
* Similar a la union por tamaño. Los representantes almacenan con valor negativo la altura
* del arbol. Se considera que la primera altura de un elemento es -1. (altura de unico elemento)
* Cuando hagamos la union, el arbol de menor altura siempre se pondra como hijo del arbol de mayor altura
* [¡] La funcion de union NO CAMBIA respecto a la anterior [!]
*/

int unionPorAltura(tipoElemento x, tipoElemento y, particion P)
{
    if(P[x]<P[y])
    {
        P[y]=x;
    }
    else if(P[y]<P[x])
    {
        P[x]=y;
    }
    else
    {   
        P[x]-=1;
        P[y]=x;
    }
    printf("unido\n");
}

//
// Función auxiliar para ver contenido de Partición 
//
void verParticion(particion P)
{ 
    int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",P[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}
