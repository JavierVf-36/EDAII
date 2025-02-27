#ifndef _MONTICULO_
#define _MONTICULO_
#define TAM 100
typedef int tipoElemento;
typedef struct Monticulo
{
    tipoElemento elemento[TAM];
    int tam;
}Monticulo;

void iniciarMonticulo(Monticulo *m);
void insertarMonticulo(Monticulo *m,tipoElemento x);
tipoElemento eliminarMin(Monticulo *m);
#endif