#include <stdio.h>
#include <stdlib.h>

typedef struct lista2 Lista2;

struct lista2
{
    int info;
    Lista2 *ant;
    Lista2 *prox;
};

Lista2 *lst_cria(int i)
{
    Lista2 *lista = (Lista2 *)malloc(sizeof(Lista2));
    lista->info = i;
    lista->ant = NULL;
    lista->prox = NULL;

    return lista;
}

Lista2 *lst_fim(Lista2 *lista)
{
    if (lista == NULL)
    {
        return NULL;
    }

    Lista2 *fim = lista;

    while (fim->prox)
    {
        fim = fim->prox;
    }

    return fim;
}

Lista2 *lst_insere(Lista2 *lista, int i)
{
    Lista2 *fim = lst_fim(lista);

    Lista2 *novo = (Lista2 *)malloc(sizeof(Lista2));
    novo->ant = fim;
    novo->prox = NULL;

    fim->prox = novo;

    return lista;
}

Lista2 *lst_retira_ant(Lista2 *lista, int i)
{
    for (Lista2 *no = lista; no != NULL; no = no->prox)
    {
        if (no->info == i)
        {
            if (no->ant == NULL)
            {
                lista = no->prox;
            }
            else
            {
                no->ant->prox = no->prox;
            }

            if (no->prox)
            {
                no->prox->ant = no->ant;
            }

            free(no);

            break;
        }
    }

    return lista;
}

void lst_imprime(Lista2 *lista)
{
    for (Lista2 *no = lista; no != NULL; no = no->prox)
    {
        printf("%d\n", no->info);
    }
}

int main()
{
    Lista2 *lista = lst_cria(30);
    lista = lst_insere(lista, 3);
    lista = lst_insere(lista, 9);
    lista = lst_insere(lista, 15);
    lista = lst_insere(lista, 11);

    printf("\nLista:\n");
    lst_imprime(lista);

    lista = lst_retira_ant(lista, 9);

    printf("\nLista:\n");
    lst_imprime(lista);
}
