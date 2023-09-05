#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    int matricula;
    char nome[50];
    struct lista* prox;
};

typedef struct lista Lista;

Lista *lst_insere(Lista *lista, int matricula, char *nome)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    
    novo->matricula = matricula;
    novo->prox = lista;
    
    strcpy(novo->nome, nome);

    return novo;
}

void lst_imprime(Lista *lista)
{
    for (Lista *no = lista; no != NULL; no = no->prox)
    {
        printf("ALUNO %010d: %s\n", no->matricula, no->nome);
    }
}

int main()
{
    Lista *lista = NULL;
    lista = lst_insere(lista, 1, "Jaime");
    lista = lst_insere(lista, 2, "Maria");
    lista = lst_insere(lista, 3, "Joao");

    lst_imprime(lista);
}