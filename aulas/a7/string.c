#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct lista Lista;

struct lista
{
    char *texto;
    Lista *proximo;
};

Lista *lst_cria(const char *texto)
{
    Lista *no = (Lista *)malloc(sizeof(Lista));
    no->texto = (char *)malloc(strlen(texto) + 1);
    no->proximo = NULL;

    strcpy(no->texto, texto);

    return no;
}


bool lst_igual(Lista *lista_a, Lista *lista_b)
{
    Lista *no_a = lista_a;
    Lista *no_b = lista_b;

    while (no_a != NULL && no_b != NULL)
    {
        if (strcmp(no_a->texto, no_b->texto) != 0)
        {
            return false;
        }

        no_a = no_a->proximo;
        no_b = no_b->proximo;
    }

    return no_a == NULL && no_b == NULL;
}

Lista *lst_copia(Lista *lista)
{
    Lista *copia_lista = NULL;
    Lista *copia_no = NULL;

    for (Lista *no = lista; no != NULL; no = no->proximo)
    {
        if (copia_no == NULL)
        {
            copia_lista = lst_cria(no->texto);
            copia_no = copia_lista;
        }
        else
        {
            copia_no->proximo = lst_cria(no->texto);
            copia_no = copia_no->proximo;
        }
    }

    return copia_lista;
}

