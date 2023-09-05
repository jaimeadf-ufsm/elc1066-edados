#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista
{
    int info;
    Lista *prox;
};

Lista *lst_cria(int info)
{
    Lista *l = (Lista*)malloc(sizeof(Lista)); 
    l->info = info;
    l->prox = NULL;

    return l;
}

Lista *lst_fim(Lista *lista)
{
    if (lista == NULL)
    {
        return NULL;
    }

    Lista *no = lista;

    while (no->prox)
    {
        no = no->prox;
    }

    return no;
}

Lista *lst_insere(Lista *lista, int i)
{
    Lista *novo = lst_cria(i);
    Lista *fim = lst_fim(lista);

    if (fim == NULL)
    {
        return novo;
    }

    fim->prox = novo;
    
    return lista;
}

void lst_imprime(Lista *lista)
{
    printf("\nLista:\n");

    for (Lista *no = lista; no != NULL; no = no->prox)
    {
        printf("%d\n", no->info);
    }
}

float lst_calculaMedia(Lista *lista)
{
    float total = 0;
    int count = 0;

    for (Lista *no = lista; no != NULL; no = no->prox)
    {
        total += no->info;
        count++;
    }

    return total / count;
}

Lista *lst_retira_ant(Lista *lista, int valor)
{
    if (lista == NULL)
    {
        return NULL;
    }

    Lista *anterior = lista;

    for (Lista *atual = lista->prox; atual->prox != NULL; atual = atual->prox)
    {
        if (atual->prox->info == valor)
        {
            anterior->prox = atual->prox;
            free(atual);

            break;
        }

        anterior = atual;
    }

    return lista;
}

int main()
{
    Lista *lista = lst_cria(3);
    lista = lst_insere(lista, 5);
    lista = lst_insere(lista, 2);
    lista = lst_insere(lista, 9);
    lista = lst_insere(lista, 20);
    lista = lst_insere(lista, 15);

    lst_imprime(lista);
    printf("Media: %f\n", lst_calculaMedia(lista));

    lst_retira_ant(lista, 2);
    lst_imprime(lista);

    lst_retira_ant(lista, 3);
    lst_imprime(lista);
}
