#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila Fila;
typedef struct lista Lista;

struct lista
{
    int elemento;
    Lista *proximo;
};

struct fila
{
    Lista *inicio;
    Lista *fim;
};

Fila fila_criar()
{
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;

    return fila;
}

bool fila_vazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void fila_inserir(Fila *fila, int valor)
{
    Lista *no = (Lista *)malloc(sizeof(Lista));
    no->elemento = valor;
    no->proximo = NULL;

    if (fila_vazia(fila))
    {
        fila->inicio = no;
    }
    else
    {
        fila->fim->proximo = no;
    }

    fila->fim = no;
}

int fila_retirar(Fila *fila)
{
    if (fila_vazia(fila))
    {
        printf("ERRO: fila vazia\n");
        return 0;
    }

    Lista *no = fila->inicio;
    int valor = fila->inicio->elemento;

    fila->inicio = no->proximo;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(no);

    return valor;
}

int fila_frente(Fila *fila)
{
    if (fila_vazia(fila))
    {
        printf("ERRO: fila vazia\n");
        return 0;
    }


    return fila->inicio->elemento;
}

void fila_imprime(Fila *fila, char *etiqueta)
{
    printf("%s:\n", etiqueta);

    for (Lista *no = fila->inicio; no != NULL; no = no->proximo)
    {
        printf("- %d\n", no->elemento);
    }

    printf("\n");
}

Fila fila_combinar(Fila *fila1, Fila *fila2)
{
    Fila resultado = fila_criar();

    while (!fila_vazia(fila1) || !fila_vazia(fila2))
    {
        if (!fila_vazia(fila1))
        {
            fila_inserir(&resultado, fila_retirar(fila1));
        }

        if (!fila_vazia(fila2))
        {
            fila_inserir(&resultado, fila_retirar(fila2));
        }
    }

    return resultado;
}

Fila fila_ordernar(Fila *fila1, Fila *fila2)
{
    Fila resultado = fila_criar();

    while (!fila_vazia(fila1) || !fila_vazia(fila2))
    {
        if (fila_vazia(fila2))
        {
            fila_inserir(&resultado, fila_retirar(fila1));
            continue;
        }

        if (fila_vazia(fila1))
        {
            fila_inserir(&resultado, fila_retirar(fila2));
            continue;
        }

        if (fila_frente(fila1) <= fila_frente(fila2))
        {
            fila_inserir(&resultado, fila_retirar(fila1));
        }
        else
        {
            fila_inserir(&resultado, fila_retirar(fila2));
        }
    }

    return resultado;
}

int main()
{
    printf("Questao 1:\n");

    Fila f1_2 = fila_criar();
    Fila f2_2 = fila_criar();

    fila_inserir(&f1_2, 2);
    fila_inserir(&f1_2, 4);
    fila_inserir(&f1_2, 1);

    fila_inserir(&f2_2, 7);
    fila_inserir(&f2_2, 3);
    fila_inserir(&f2_2, 9);

    fila_imprime(&f1_2, "f1");
    fila_imprime(&f2_2, "f2");

    Fila fres_2 = fila_combinar(&f1_2, &f2_2);

    fila_imprime(&fres_2, "fres");

    printf("\nQuestao 2:\n");

    Fila f1_3 = fila_criar();
    Fila f2_3 = fila_criar();

    fila_inserir(&f1_3, 2);
    fila_inserir(&f1_3, 4);
    fila_inserir(&f1_3, 6);
    fila_inserir(&f1_3, 8);
    fila_inserir(&f1_3, 10);

    fila_inserir(&f2_3, 1);
    fila_inserir(&f2_3, 3);
    fila_inserir(&f2_3, 5);
    fila_inserir(&f2_3, 7);
    fila_inserir(&f2_3, 9);
    fila_inserir(&f2_3, 11);
    fila_inserir(&f2_3, 12);
    fila_inserir(&f2_3, 14);
    fila_inserir(&f2_3, 18);
    fila_inserir(&f2_3, 20);

    fila_imprime(&f1_3, "f1");
    fila_imprime(&f2_3, "f2");

    Fila fres_3 = fila_ordernar(&f1_3, &f2_3);

    fila_imprime(&fres_3, "fres");
}