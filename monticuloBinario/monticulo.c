#include "monticulo.h"

void iniciaMonticulo(Monticulo *m)
{
    m->tamanno=0;
}

int vacioMonticulo(Monticulo m)
{
    if(m->tamanno==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int insertar(tipoElemento x, Monticulo *m)
{
    int hueco;
    if(m->tamanno>=MAXIMO)
    {
        return -1;
    }else
    {
        m->tamaño+=1;
        hueco=m->tamanno;

        while(hueco/2>1)
        {
            filtradoAscendente(&m, hueco);
            hueco=hueco-=1;
        }
        
    }
}

void filtradoAscendente(Monticulo *m, int i)
{
    tipoElemento temp;
    if(m->elemento[i]<m->elemento[i/2])
    {
        temp.clave=m->elemento[i];
        m->elemento[i]=m->elemento[i/2];
        m->elemento[i/2]=temp;
    }
}

void filtradoDescendente(Monticulo *m, int i)
{
    tipoElemento hijo1,hijo2;
    hijo1.clave=m->elemento[i*2];
    if(m->tamanno>=i*2+1)
    {
        hijo2=m->elemento[i*2+1];
    }

    if(hijo1.clave<hijo2.clave)
    {
        m->elemento[i]=hijo1.clave;
    }
    else
    {
        m->elemento[i]=hijo2.clave;
    }
}