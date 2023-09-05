#include <stdlib.h>
#include <stdio.h>

typedef struct lista Lista;

struct lista
{
    int valor;
    Lista *proximo;
};


Lista *lst_cria(int valor)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->valor = valor;
    lista->proximo = NULL;

    return lista;
}

Lista *lst_insere(Lista *lista, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = lista;

    return novo;
}

void lst_imprime(Lista *lista)
{
    for (Lista *no = lista; no != NULL; no = no->proximo)
    {
        printf("%d\n", no->valor);
    }
}

Lista *lst_retira_n(Lista *lista, int valor)
{
    Lista *inicio = lista;

    Lista *anterior = NULL;
    Lista *atual = lista;

    while (atual != NULL)
    {
        Lista *proximo = atual->proximo;

        if (atual->valor == valor)
        {
            if (anterior == NULL)
            {
                inicio = proximo;
            }
            else
            {
                anterior->proximo = proximo;
            }

            free(atual);
            atual = NULL;
        }

        anterior = atual;
        atual = proximo;
    }

    return inicio;
}

Lista *lst_separa(Lista *lista, int n)
{
    Lista *particao = NULL;

    for (Lista *no = lista; no != NULL; no = no->proximo)
    {
        if (no->valor == n)
        {
            particao = no->proximo;
            no->proximo = NULL;

            break;
        }
    }

    return particao;
}

Lista *lst_merge(Lista *lista_a, Lista *lista_b)
{
    Lista *no_a = lista_a;
    Lista *no_b = lista_b;

    Lista *juncao_inicio = NULL;
    Lista **juncao_fim = &juncao_inicio;

    while (no_a != NULL || no_b != NULL)
    {
        if (no_a != NULL)
        {
            Lista *novo = lst_cria(no_a->valor);
            *juncao_fim = novo;
            juncao_fim = &novo->proximo;

            no_a = no_a->proximo;
        }

        if (no_b)
        {
            Lista *novo = lst_cria(no_b->valor);
            *juncao_fim = novo;
            juncao_fim = &novo->proximo;

            no_b = no_b->proximo;
        }
    }

    return juncao_inicio;
}

Lista *lst_inverte(Lista *lista)
{
    Lista *tras = NULL;
    Lista *atual = lista;

    while (atual != NULL)
    {
        Lista *frente = atual->proximo;

        atual->proximo = tras;

        tras = atual;
        atual = frente;
    }

    return tras;
}

Lista *lst_cria_circular(int valor)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->valor = valor;
    lista->proximo = lista;

    return lista;
}

Lista *lst_ultimo_circular(Lista *inicio)
{
    Lista *ultimo = inicio;

    while (ultimo->proximo != inicio)
    {
        ultimo = ultimo->proximo;
    }

    return ultimo;
}

void lst_insere_circular(Lista *inicio, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = inicio;

    Lista *ultimo = lst_ultimo_circular(inicio);
    ultimo->proximo = novo;
}

Lista *lst_retira_circular(Lista *inicio, int valor)
{
    Lista *no = inicio;

    do {
        if (no->proximo->valor == valor)
        {
            Lista *outro = no->proximo->proximo;

            if (no == no->proximo)
            {
                inicio = NULL;
            }
            else if (inicio == no->proximo)
            {
                inicio = no;
            }

            free(no->proximo);

            no->proximo = outro;

            break;
        }

        no = no->proximo;
    } while (no != inicio);

    return inicio;
}

void lst_imprime_circular(Lista *inicio)
{
    if (inicio == NULL)
    {
        return;
    }

    Lista *no = inicio;

    do {
        printf("%d\n", no->valor);
        no = no->proximo;
    } while (no != inicio);
}

int main()
{
    Lista *lista_a = lst_cria(5);
    lista_a = lst_insere(lista_a, 20);
    lista_a = lst_insere(lista_a, 3);
    lista_a = lst_insere(lista_a, 5);
    lista_a = lst_insere(lista_a, 12);
    lista_a = lst_insere(lista_a, 34);
    lista_a = lst_insere(lista_a, 31);

    Lista *lista_b = lst_cria(1);
    lista_b = lst_insere(lista_b, 12);
    lista_b = lst_insere(lista_b, 5);
    lista_b = lst_insere(lista_b, 17);
    lista_b = lst_insere(lista_b, 3);

    Lista *lista_c = lst_cria(1);
    lista_c = lst_insere(lista_c, 4);
    lista_c = lst_insere(lista_c, 2);

    Lista *lista_d = lst_cria(9);
    lista_d = lst_insere(lista_d, 3);
    lista_d = lst_insere(lista_d, 7);

    Lista *lista_e = lst_cria(9);
    lista_e = lst_insere(lista_e, 7);
    lista_e = lst_insere(lista_e, 1);
    lista_e = lst_insere(lista_e, 4);
    lista_e = lst_insere(lista_e, 2);

    Lista *lista_circular = lst_cria_circular(30);
    lst_insere_circular(lista_circular, 1);
    lst_insere_circular(lista_circular, 4);
    lst_insere_circular(lista_circular, 9);
    lst_insere_circular(lista_circular, 3);

    printf("Lista A:\n");
    lst_imprime(lista_a);

    printf("\nLista B:\n");
    lst_imprime(lista_b);

    printf("\nLista C:\n");
    lst_imprime(lista_c);

    printf("\nLista D:\n");
    lst_imprime(lista_d);

    printf("\nLista E:\n");
    lst_imprime(lista_e);

    Lista *lista_sem_n = lst_retira_n(lista_a, 5);
    
    printf("\nLista A retirado 5:\n");
    lst_imprime(lista_sem_n);

    Lista *lista_parte_2 = lst_separa(lista_b, 5);

    printf("\nLista B parte 1:\n");
    lst_imprime(lista_b);

    printf("\nLista B parte 2:\n");
    lst_imprime(lista_parte_2);

    Lista *lista_intercalada = lst_merge(lista_c, lista_d);

    printf("\nLista C e D intercalada:\n");
    lst_imprime(lista_intercalada);

    Lista *lista_invertida = lst_inverte(lista_e);

    printf("\nLista E invertida:\n");
    lst_imprime(lista_invertida);

    printf("\nLista circular:\n");
    lst_imprime_circular(lista_circular);

    printf("\nLista circular:\n");
    lst_imprime_circular(lista_circular);

    lista_circular = lst_retira_circular(lista_circular, 30);

    printf("\nLista circular sem 30:\n");
    lst_imprime_circular(lista_circular);

    lista_circular = lst_retira_circular(lista_circular, 3);

    printf("\nLista circular sem 3:\n");
    lst_imprime_circular(lista_circular);

    lista_circular = lst_retira_circular(lista_circular, 1);

    printf("\nLista circular sem 1:\n");
    lst_imprime_circular(lista_circular);

}

