#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha Pilha;

struct pilha
{
    int capacidade;
    int tamanho;
    int *vetor;
};

Pilha criar_pilha(int capacidade)
{
    return (Pilha) {
        .capacidade = capacidade,
        .tamanho = 0,
        .vetor = (int *)malloc(sizeof(int) * capacidade)
    };
}

void liberar_pilha(Pilha *pilha)
{
    free(pilha->vetor);
}

bool pilha_vazia(Pilha *pilha)
{
    return pilha->tamanho == 0;
}

void empilhar(Pilha *pilha, int elemento)
{
    printf("PUSH(P, %d)\n", elemento);

    if (pilha->capacidade == pilha->tamanho)
    {
        printf("ERRO: pilha cheia\n");
        return;
    }

    pilha->vetor[pilha->tamanho++] = elemento;
}

bool desempilhar(Pilha *pilha)
{
    printf("POP(P)\n");

    if (pilha_vazia(pilha))
    {
        return false;
    }

    pilha->tamanho--;

    return true;
}

int tamanho_da_pilha(Pilha *pilha)
{
    return pilha->tamanho;
}

int topo_da_pilha(Pilha *pilha)
{
    if (pilha_vazia(pilha))
    {
        printf("ERRO: pilha vazia\n");
        return 0;
    }

    return pilha->vetor[pilha->tamanho - 1];
}

void esvaziar_pilha(Pilha *pilha)
{
    pilha->tamanho = 0;
}

void concatenar_pilhas(Pilha *pilha_a, Pilha *pilha_b)
{
    while (!pilha_vazia(pilha_b))
    {
        empilhar(pilha_a, topo_da_pilha(pilha_b));
        desempilhar(pilha_b);
    }
}

void imprimir_pilha(Pilha *pilha)
{
    for (int i = pilha->tamanho - 1; i >= 0; i--)
    {
        if (i == pilha->tamanho - 1)
        {
            printf("%d (topo)\n", pilha->vetor[i]);
        }
        else
        {
            printf("%d\n", pilha->vetor[i]);
        }
    }

    printf("\n");
}

bool verificar_palindromo(char *palavra)
{
    Pilha pilha = criar_pilha(strlen(palavra));

    for (int i = 0; i < strlen(palavra); i++)
    {
        empilhar(&pilha, palavra[i]);
    }

    for (int i = 0; i < strlen(palavra); i++)
    {
        if (topo_da_pilha(&pilha) != palavra[i])
        {
            liberar_pilha(&pilha);
            return false;
        }

        desempilhar(&pilha);
    }

    liberar_pilha(&pilha);

    return true;
}

int main()
{

    printf("2)\n");
    printf("a.\n");
    Pilha pilha2_a = criar_pilha(6);

    empilhar(&pilha2_a, 4);
    imprimir_pilha(&pilha2_a);

    empilhar(&pilha2_a, 3);
    imprimir_pilha(&pilha2_a);

    desempilhar(&pilha2_a);
    imprimir_pilha(&pilha2_a);

    empilhar(&pilha2_a, 8);
    imprimir_pilha(&pilha2_a);

    desempilhar(&pilha2_a);
    imprimir_pilha(&pilha2_a);

    Pilha pilha2_bi = criar_pilha(6);
    Pilha pilha2_bii = criar_pilha(6);

    printf("b.\n");

    printf("i.\n");
    empilhar(&pilha2_bi, 3);
    imprimir_pilha(&pilha2_bi);

    desempilhar(&pilha2_bi);
    imprimir_pilha(&pilha2_bi);

    desempilhar(&pilha2_bi);
    imprimir_pilha(&pilha2_bi);

    empilhar(&pilha2_bi, 4);
    imprimir_pilha(&pilha2_bi);

    printf("ii.\n");
    empilhar(&pilha2_bii, 1);
    imprimir_pilha(&pilha2_bii);

    desempilhar(&pilha2_bii);
    imprimir_pilha(&pilha2_bii);

    empilhar(&pilha2_bii, 2);
    imprimir_pilha(&pilha2_bii);

    empilhar(&pilha2_bii, 3);
    imprimir_pilha(&pilha2_bii);

    empilhar(&pilha2_bii, 4);
    imprimir_pilha(&pilha2_bii);

    empilhar(&pilha2_bii, 5);
    imprimir_pilha(&pilha2_bii);

    empilhar(&pilha2_bii, 6);
    imprimir_pilha(&pilha2_bii);

    empilhar(&pilha2_bii, 7);
    imprimir_pilha(&pilha2_bii);

    empilhar(&pilha2_bii, 8);
    imprimir_pilha(&pilha2_bii);

    printf("3)\n");

    Pilha pilha3 = criar_pilha(10);
    empilhar(&pilha3, 3);
    empilhar(&pilha3, 5);
    empilhar(&pilha3, 6);

    printf("a. tamanho: %d\n", tamanho_da_pilha(&pilha3));
    printf("b. topo: %d\n\n", topo_da_pilha(&pilha3));

    printf("4)\n");
    esvaziar_pilha(&pilha3);
    imprimir_pilha(&pilha3);

    printf("5)\n");
    printf("i. arara: %d\n", verificar_palindromo("arara"));
    printf("ii. jaime: %d\n\n", verificar_palindromo("jaime"));

    printf("6)\n");

    Pilha pilha6_a = criar_pilha(6);
    Pilha pilha6_b = criar_pilha(6);

    empilhar(&pilha6_a, 1);
    empilhar(&pilha6_a, 4);
    empilhar(&pilha6_a, 2);

    empilhar(&pilha6_b, 7);
    empilhar(&pilha6_b, 3);
    empilhar(&pilha6_b, 9);

    concatenar_pilhas(&pilha6_a, &pilha6_b);

    imprimir_pilha(&pilha6_a);
}