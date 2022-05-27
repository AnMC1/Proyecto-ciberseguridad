#include<stdio.h>
#include<stdlib.h>


/* Funciones para registrar ciberataque   PROTOTIPOS */
typedef struct Lista Lista;
typedef struct Nodo Nodo;
typedef struct Ciberataque Ciberataque; 

void insertar_Ciberataque(Ciberataque ciberataque);
void eliminar_Ciberataque( int *codigo);
void modificar_Ciberataque(Ciberataque ciberataque, int *codigo);
void consultar_Lista_Ciberataque();
void mostrar_ciberataque_por_codigo(int * codigo);

Lista* L;

/////////////////////////////Funciones registro de tipo ciberataque//////////////////////////////
struct Ciberataque{
	int codigo;
	char nombre[50];
	char descripcion[100];
	char canal[50];
	
};

struct Nodo{
    Ciberataque ciberataque;
    Nodo *siguiente;
};

struct Lista
{
    Nodo *inicio;
};

Lista *listaNueva1(void)
{
    Lista *L;
    L = (Lista *) malloc(sizeof(Lista));
    L->inicio = NULL;
    return L;
};

//---------------------------REGISTRAR-----------------------------
void insertar_Ciberataque(Ciberataque ciberataque){					/* Insertar los datos del ciberataque en una lista simple */
    Nodo  *n, *aux, *nuevo;

    nuevo=(Nodo *) malloc(sizeof(Nodo));

	
    if(L->inicio==NULL){
        /* Inserta al inicio si esta vacia */
        L->inicio=(Nodo*)malloc(sizeof(Nodo));
        L->inicio->ciberataque= ciberataque;
        L->inicio->siguiente=NULL;
        return;
    }

    n = L->inicio;
    while(n!= NULL)
    {
        aux = n;
        n = n->siguiente;
    }

    //nuevo=(Nodo *) malloc(sizeof(Nodo));
    aux->siguiente = nuevo;
    nuevo->siguiente = NULL;
    nuevo->ciberataque = ciberataque;
}

//---------------------------ELIMINAR-----------------------------
void eliminar_Ciberataque( int *codigo)
{
    Nodo *eliminado = L->inicio, *anterior = NULL;
    //Valida si la lista esta vacia
    if(L->inicio == NULL)
    {
        printf("La lista esta vacia...\n");
    }
    else
    {
        //Si el nodo a eliminar esta al inicio de la lista

        if( L->inicio->ciberataque.codigo==codigo)
        {
            eliminado = L->inicio;
            L->inicio = L->inicio->siguiente;
            /*if(L->inicio->siguiente==NULL)			//Preguntar por esta validacion
            	anterior=L->inicio;
				L->inicio=NULL;   */
			
        }
        else
        {
            while(eliminado!= NULL)
            {
                if( eliminado->ciberataque.codigo==codigo)		//Nodo a eliminar cuando la cedula coincida
                {
                    anterior->siguiente = eliminado->siguiente;
                    break;
                }
                else
                {
                    anterior = eliminado;
                    eliminado = eliminado->siguiente;
                }
            }
        }
        if(eliminado != NULL)
        {
            printf("El ciberataque eliminado es %s \n", eliminado->ciberataque.codigo);
            free(eliminado);
        }
    }
}

//---------------------------MODIFICAR-----------------------------
void modificar_Ciberataque(Ciberataque ciberataque, int *codigo){
    Nodo *aux=L->inicio;

    while (aux!=NULL){
        if (aux->ciberataque.codigo==codigo){
            aux->ciberataque=ciberataque;
        }
        aux=aux->siguiente;
    }

}

//---------------------------CONSULTAR-----------------------------
void consultar_Lista_Ciberataque() {
    Nodo *i;
    printf("\n**La lista de CIBERATAQUES** \n");
    printf("\n");
    printf("%-15s%-8s\n", "Nombre", "Codigo");
    for (i = L->inicio; i != NULL; i = i->siguiente) {
        printf("%-15s%-8d\n", i->ciberataque.nombre, i->ciberataque.codigo);
    }
    printf("\n");
}

//---------------------------MOSTRAR POR CODIGO -------------------
void mostrar_ciberataque_por_codigo(int * codigo){
    Nodo *nAux = L->inicio;
    while(nAux != NULL)
    {
        if( nAux->ciberataque.codigo==codigo){

            printf("Nombre: %s\nCodigo: %d\nDescripcion: %s\nCanal: %s\n",nAux->ciberataque.nombre, nAux->ciberataque.codigo,nAux->ciberataque.descripcion,nAux->ciberataque.canal);
		}
        nAux = nAux->siguiente;
    }
}

//--------------------------BUSCAR CIBERATAQUE---------------------
Ciberataque buscar_Ciberataque(int *codigo){
    Ciberataque ciberataque_Encontrado;
    Nodo *nodo = L->inicio;

    while(nodo != NULL){

        if (nodo->ciberataque.codigo==codigo){
            return ciberataque_Encontrado=nodo->ciberataque;
        }
        nodo = nodo->siguiente;
    }
    return ciberataque_Encontrado;

}
