#include "conjuntos.h"
#include <stdio.h>

void crea(particion P)
{
    for(int i=0;i<MAXIMO;i++)
    {
        P[i]=i;
    }
}

tipoConjunto buscar(tipoElemento x, particion P)
{
    return P[x];
}


int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    tipoElemento i;

    if(P[x]!=x)
    {
        return 0;
    }


    for(i=0;i<MAXIMO;i++)
    {
        if(P[i]==y)
        {
            P[i]=x;
        }
    }  
    return 1;
}

void verParticion(particion P)
{ int i;
    for (i =0;i<MAXIMO;i++) printf("|%2d",P[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n");
}
