#include <stdio.h>
#include <stdlib.h>
#define N 10
#define INFINITO 99999

//Ejemplo de grafos
typedef struct arco
{
    int idV;
    int coste;
    struct arco *sig;
}arco;

typedef struct vertice
{
    int alcanzado;
    int distancia;
    int ordentop;
    int gradoEntrada;
    int anterior;
    arco *lista;
}vertice;

typedef struct 
{
    vertice directorio[N];
    int orden;
}grafo;


//DEFINICION DE COLAS
typedef int tipoElemento;

typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
} tipoCelda;

typedef struct {
    tipoCelda *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c){
    c->fondo=NULL;
    c->frente=NULL;
    return 0;
}

int colaVacia(Cola *c){

    if(c==NULL){
        return -2;
    }

    if(c->fondo==NULL||c->frente==NULL){
        return 1;
    }else{
        return 0;
    }
}

int colaInserta(Cola *c, tipoElemento elemento) {
    tipoCelda *nuevo = malloc(sizeof(tipoCelda));

    if (nuevo == NULL) {
        return 1; 
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

    return 0;
}

tipoElemento colaSuprime(Cola *c){
    tipoElemento elemento;
    tipoCelda *aBorrar;
    elemento=c->frente->elemento;
    aBorrar=c->frente;
    c->frente=c->frente->sig;
    free(aBorrar);
    if(c->frente==NULL){
        c->fondo=NULL;
    }
    return elemento;
}




void agregarArco(grafo *g, int origen, int destino, int coste) {
    arco *nuevo = (arco *)malloc(sizeof(arco));
    nuevo->idV = destino;
    nuevo->coste = coste;
    nuevo->sig = g->directorio[origen].lista;
    g->directorio[origen].lista = nuevo;
}

void crearGrafo(grafo *g) {
    g->orden = 5;

    for (int i = 0; i < g->orden; i++) {
        g->directorio[i].lista = NULL;
        g->directorio[i].alcanzado = 0;
        g->directorio[i].distancia = INFINITO;
        g->directorio[i].anterior = -1;
    }

    // Aristas sin ciclos (ejemplo de DAG: 0 → 1 → 2, 0 → 3, 3 → 4, 4-> 2)
    agregarArco(g, 0, 1, 2);
    agregarArco(g, 1, 2, 4);
    agregarArco(g, 0, 3, 1);
    agregarArco(g, 3, 4, 3);
    agregarArco(g, 4, 2, 1);
    //agregarArco(g,1,0,2); Linea de prueba para comprobar ciclo
}

void mostrarGrafo(grafo *g) {
    for (int i = 0; i < g->orden; i++) {
        printf("Vertice %d -> ", i);
        arco *a = g->directorio[i].lista;
        while (a != NULL) {
            printf("%d(coste %d) ", a->idV, a->coste);
            a = a->sig;
        }
        printf("\n");
    }
}


int obtenerVSinOrdenGradoEntradaCero(grafo *g)
{
    int i;
    for(i=0;i<g->orden;i++)
    {
        if(g->directorio[i].ordentop==-1&&g->directorio[i].gradoEntrada==0)
        {
            return i;
        }
    }
    //Error. Hay ciclo en el grafo
    return -1;
}


void iniciarGrafo(grafo *g) {
    //Necesitamos poner valores por defecto del orden Topologico y del grado de entrada
    int i;
    arco *aux;

    for(i=0;i<g->orden;i++)
    {
        g->directorio[i].ordentop=-1;
        g->directorio[i].gradoEntrada=0;
        g->directorio[i].alcanzado=0;
        g->directorio[i].distancia=INFINITO;
        g->directorio[i].anterior=0;
    }

    //Recorremos la lista de nuevo, para setear los valores del grado de entrada de cada uno de los vertices
    for(i=0;i<g->orden;i++)
    {
        aux=g->directorio[i].lista;
        while(aux!=NULL)
        {
            g->directorio[aux->idV].gradoEntrada+=1;
            aux=aux->sig;
        }
    }
    
}



void ordenTop1(grafo *g)
{
    int vActual;
    arco *aux;
    int ordenTop; // 'i'
    iniciarGrafo(g);

    for(ordenTop=1;ordenTop<=g->orden;ordenTop++)
    {
        vActual=obtenerVSinOrdenGradoEntradaCero(g);
        if(vActual==-1)
        {
            printf("Error. El grafo tiene un ciclo.\n");
            return ;
        }
        g->directorio[vActual].ordentop=ordenTop;
        aux=g->directorio[vActual].lista;
        while(aux!=NULL)
        {
            g->directorio[aux->idV].gradoEntrada-=1;
            aux=aux->sig;
        }
    }
}

void ordenTop2(grafo *g)
{
    int vActual;
    Cola c;
    int i;
    arco *aux;
    iniciarGrafo(g);
    colaCreaVacia(&c);
    for(i=0;i<g->orden;i++)
    {
        if(g->directorio[i].gradoEntrada==0)
        {
            colaInserta(&c,i);
        }
    }

    i=1;

    while(!colaVacia(&c))
    {
        vActual=colaSuprime(&c);
        g->directorio[vActual].ordentop=i;
        i++;
        aux=g->directorio[vActual].lista;
        while(aux!=NULL)
        {
            g->directorio[aux->idV].gradoEntrada-=1;
            if(g->directorio[aux->idV].gradoEntrada==0)
            {
                colaInserta(&c,aux->idV);
            }
           
            aux=aux->sig;
        }
    } 
}


void mostrarOrdenTop(grafo *g)
{
    int i;
    for(i=0;i<g->orden;i++)
    {
        printf("V%d:[%d]",i,g->directorio[i].ordentop);
        printf("\n");
    }
}

void mostrarCamino(grafo *g)
{
    for (int i = 0; i < g->orden; i++)
    {
        printf("Camino hasta el vértice %d: ", i);

        if (g->directorio[i].distancia == INFINITO)
        {
            printf("No alcanzable\n");
            continue;
        }

        // Reconstruir el camino al revés
        int camino[100];  // Tamaño suficiente para tu caso
        int len = 0;
        int actual = i;
        while (actual != -1)
        {
            camino[len++] = actual;
            actual = g->directorio[actual].anterior;
        }

        // Imprimir el camino en orden
        for (int j = len - 1; j >= 0; j--)
        {
            printf("%d", camino[j]);
            if (j > 0)
                printf(" -> ");
        }

        printf(" (distancia: %d)\n", g->directorio[i].distancia);
    }
}



void caminoMinimo(grafo *g, int vInicial)
{
    int distanciaActual;
    int i;
    arco *aux;
    
    iniciarGrafo(g);
    g->directorio[vInicial].distancia=0;
    g->directorio[vInicial].anterior=-1;

    for(distanciaActual=0;distanciaActual<g->orden;distanciaActual++)
    {
        for(i=0;i<g->orden;i++)
        {
            if(g->directorio[i].distancia==distanciaActual)
            {
                g->directorio[i].alcanzado=1;
                aux=g->directorio[i].lista;
                while(aux!=NULL)
                {
                    if(g->directorio[aux->idV].distancia==INFINITO)
                    {
                        g->directorio[aux->idV].distancia=distanciaActual+1;
                        g->directorio[aux->idV].anterior=i;
                    }
                    aux=aux->sig;
                }
            }
        }
    }
}

void caminoMinimo2(grafo *g, int vInicial)
{
    Cola c;
    arco *aux;
    int vActual;

    iniciarGrafo(g);
    g->directorio[vInicial].anterior=-1;
    g->directorio[vInicial].distancia=0;
    colaCreaVacia(&c);
    colaInserta(&c,vInicial);

    while(!colaVacia(&c))
    {
        vActual=colaSuprime(&c);
        aux=g->directorio[vActual].lista;
        while(aux!=NULL){
            if(g->directorio[aux->idV].distancia==INFINITO)
            {
                g->directorio[aux->idV].distancia=g->directorio[vActual].distancia+1;
                g->directorio[aux->idV].anterior=vActual;
                colaInserta(&c, aux->idV);
            }
            aux=aux->sig;
        }
    }

}

int main(void)
{
    grafo g;
    g.orden=0;
    crearGrafo(&g);
    printf("Contenido del grafo:\n");
    mostrarGrafo(&g);
    printf("\n");
    printf("Resultado del orden topologico con tiempo de ejecucion n²:\n");
    ordenTop1(&g);
    mostrarOrdenTop(&g);
    printf("\n");
    printf("Esto es un tiempo no deseado. Vamos a hacer la version mejorada usando colas:\n");
    ordenTop2(&g);
    mostrarOrdenTop(&g);
    printf("\n");
    printf("Vamos a mostrar el camino minimo a partir de un vertice inicial.\n");
    caminoMinimo(&g,0);
    mostrarCamino(&g);
    printf("\n");
    printf("Mostramos el camino minimo usando la version mejorada usando colas:\n");
    caminoMinimo2(&g,0);
    mostrarCamino(&g);
    return 0;
}

