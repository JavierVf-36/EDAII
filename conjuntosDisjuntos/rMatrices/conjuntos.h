#ifndef __CONJUNTOS_H
#define __CONJUNTOS_H

#define MAXIMO 16
typedef int particion[MAXIMO];
typedef int tipoConjunto;
typedef int tipoElemento;

void crea(particion P);
tipoConjunto buscar(tipoElemento x, particion P);
int unir(tipoConjunto x, tipoConjunto y, particion P);
void verParticion(particion P);
#endif
