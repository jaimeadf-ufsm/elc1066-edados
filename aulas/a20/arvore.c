#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arvore Arvore;

struct arvore
{
    int valor;
    Arvore *esquerda;
    Arvore *direita;
};

Arvore *arvore_criar(int valor, Arvore *esquerda, Arvore *direita)
{
    Arvore *arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->valor = valor;
    arvore->esquerda = esquerda;
    arvore->direita = direita;

    return arvore;
}

bool arvore_vazia(Arvore *arvore)
{
    return arvore == NULL;
}

void arvore_liberar(Arvore *arvore)
{
    if (arvore_vazia(arvore))
    {
        return;
    }

    arvore_liberar(arvore->esquerda);
    arvore_liberar(arvore->direita);

    free(arvore);
}

Arvore *arvore_inverter(Arvore *arvore)
{
    if (arvore_vazia(arvore))
    {
        return NULL;
    }

    Arvore *temp = arvore->esquerda;

    arvore->esquerda = arvore_inverter(arvore->direita);
    arvore->direita = arvore_inverter(temp);

    return arvore;
}

void arvore_simetrica(Arvore *arvore)
{
    if (!arvore_vazia(arvore))
    {
        arvore_simetrica(arvore->esquerda);
        printf(" %d ", arvore->valor);
        arvore_simetrica(arvore->direita);
    }
}

void arvore_antisimetrica(Arvore *arvore)
{
    if (!arvore_vazia(arvore))
    {
        arvore_antisimetrica(arvore->direita);
        printf(" %d ", arvore->valor);
        arvore_antisimetrica(arvore->esquerda);
    }
}

bool abb_verificar(Arvore *arvore)
{
    return (arvore_vazia(arvore->esquerda) || (arvore->esquerda->valor < arvore->valor && abb_verificar(arvore->esquerda))) &&
        (arvore_vazia(arvore->direita) || (arvore->direita->valor >= arvore->valor && abb_verificar(arvore->direita)));
}

Arvore *abb_inserir(Arvore *arvore, int valor)
{
    if (arvore_vazia(arvore))
    {
        return arvore_criar(valor, NULL, NULL);
    }

    if (valor < arvore->valor)
    {
        arvore->esquerda = abb_inserir(arvore->esquerda, valor);
    }
    else
    {
        arvore->direita = abb_inserir(arvore->direita, valor);
    }

    return arvore;
}

int main()
{
    Arvore *arvore = NULL;
    arvore = abb_inserir(arvore, 5);
    arvore = abb_inserir(arvore, 1);
    arvore = abb_inserir(arvore, 3);
    arvore = abb_inserir(arvore, 7);
    arvore = abb_inserir(arvore, 2);
    arvore = abb_inserir(arvore, 8);
    arvore = abb_inserir(arvore, 8);
    arvore = abb_inserir(arvore, 1);
    arvore = abb_inserir(arvore, 5);
    arvore = abb_inserir(arvore, 4);

    printf("Crescente (ABB: %d):\n", abb_verificar(arvore));
    arvore_simetrica(arvore);

    printf("\nDescrescente (ABB: %d):\n", abb_verificar(arvore));
    arvore_antisimetrica(arvore);

    arvore = arvore_inverter(arvore);

    printf("\nInvertida: (ABB: %d)\n", abb_verificar(arvore));
    arvore_simetrica(arvore);
    printf("\n");
}