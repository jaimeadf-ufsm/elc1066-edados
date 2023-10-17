#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct arvore Arvore;


struct arvore
{
    char valor;
    Arvore *esq, *dir;
};

Arvore *arv_cria(char valor, Arvore *esq, Arvore *dir)
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));   
    arvore->valor = valor;
    arvore->esq = esq;
    arvore->dir = dir;

    return arvore;
}

bool arv_vazia(Arvore *arvore)
{
    return arvore == NULL;
}

void arv_pre_ordem(Arvore *arvore)
{
    if (!arv_vazia(arvore))
    {
        printf("%c", arvore->valor);
        arv_pre_ordem(arvore->esq);
        arv_pre_ordem(arvore->dir);
    }
}

void arv_simetrica(Arvore *arvore)
{
    if (!arv_vazia(arvore))
    {
        arv_simetrica(arvore->esq);
        printf("%c ()", arvore->valor);
        arv_simetrica(arvore->dir);
    }
}

void arv_pos_ordem(Arvore *arvore)
{
    if (!arv_vazia(arvore))
    {
        arv_pos_ordem(arvore->esq);
        arv_pos_ordem(arvore->dir);
        printf("%c", arvore->valor);
    }
}

int arv_pares(Arvore *arvore)
{
    if (arv_vazia(arvore))
    {
        return 0;
    }

    return !(arvore->valor & 1) + arv_pares(arvore->esq) + arv_pares(arvore->dir);
}

Arvore *arv_copia(Arvore *arvore)
{
    if (arv_vazia(arvore))
    {
        return NULL;
    }

    return arv_cria(arvore->valor, arv_copia(arvore->esq), arv_copia(arvore->dir));
}

int arv_folhas(Arvore *arvore)
{
    if (arv_vazia(arvore))
    {
        return 0;
    }

    return 1 + arv_folhas(arvore->esq) + arv_folhas(arvore->dir);
}

int arv_um_filho(Arvore *arvore)
{
    if (arv_vazia(arvore))
    {
        return 0;
    }
    else if (arv_vazia(arvore->esq))
    {
        return 1 + arv_um_filho(arvore->dir);
    }
    else if (arv_vazia(arvore->dir))
    {
        return 1 + arv_um_filho(arvore->esq);
    }
    else
    {
        return arv_um_filho(arvore->esq) + arv_um_filho(arvore->dir);
    }
}

bool arv_igual(Arvore *a, Arvore *b)
{
    if (arv_vazia(a))
    {
        return arv_vazia(b);
    }

    if (arv_vazia(b))
    {
        return arv_vazia(a);
    }

    return a->valor == b->valor && arv_igual(a->esq, b->esq) && arv_igual(a->dir, b->dir);
}

int main()
{
    Arvore *a = arv_cria(
        'a',
        NULL,
        arv_cria(
            'b',
            NULL,
            arv_cria(
                'c',
                arv_cria(
                    'd',
                    arv_cria(
                        'e',
                        arv_cria(
                            'g',
                            arv_cria(
                                'i',
                                NULL,
                                NULL
                            ),
                            NULL
                        ),
                        NULL
                    ),
                    arv_cria(
                        'f',
                        NULL,
                        arv_cria(
                            'h',
                            arv_cria(
                                'j',
                                NULL,
                                NULL
                            ),
                            NULL
                        )
                    )
                ),
                NULL
            )
        )
    );

    printf("Pre-ordem: \n");
    arv_pre_ordem(a);

    printf("\n\nPos-ordem: \n");
    arv_pos_ordem(a);

    printf("\n\nSimetrica: \n");
    arv_simetrica(a);


    printf("\n\nFolhas: %d\n", arv_folhas(a));
    printf("Um Filho: %d\n", arv_um_filho(a));
    printf("Pares: %d\n", arv_pares(a));

    Arvore *b = arv_copia(a);
    Arvore *c = arv_cria('a', arv_copia(a), NULL);

    printf("Igual: %d\n", arv_igual(a, b));
    printf("Nao Igual: %d\n", arv_igual(a, c));
}