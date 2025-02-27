#include "monticulo.h"

void iniciarMonticulo(Monticulo *m)
{
    m->tam=0;
}

void insertarMonticulo(Monticulo *m,tipoElemento x)
{
    int actual, padre;
    tipoElemento temp;
    int fin_filtrado;

    if(m->tam+1==TAM)
    {
        return;
    }else{
        m->tam+=1;
        m->elemento[m->tam]=x;

        actual=m->tam;
        fin_filtrado=0;
        while(!fin_filtrado)
        {
            padre=actual/2;
            if(padre==0||m->elemento[padre]<m->elemento[m->tam])
            {
                fin_filtrado=1;
            }else{
                temp=m->elemento[padre];
                m->elemento[padre]=m->elemento[actual];
                m->elemento[actual]=temp;
                actual=padre;
            }
        }
    }
}

tipoElemento eliminarMin(Monticulo *m)
{
    tipoElemento min;
    if(m->tam==0)
    {
        return -1;
    }
    
    min=m->elemento[1];
    m->elemento[1]=m->elemento[m->tam];
    m->tam-=1;
    //filtradoDescendente(m,1);
    return min;
}
