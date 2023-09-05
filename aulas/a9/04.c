#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PROFESSOR 0
#define ALUNO 1

struct professor
{
    int codigo;
    char nome[50];
    float salario;
};

typedef struct professor Professor;

struct aluno
{
    int matricula;
    char nome[50];
};

typedef struct aluno Aluno;

struct listaHet
{
    int tipo;
    void *info;
    struct listaHet *prox;
};

typedef struct listaHet ListaHet;

ListaHet *lst_insere_professor(ListaHet *lista, int codigo, char *nome)
{
    Professor *professor = (Professor *)malloc(sizeof(Professor));
    professor->codigo = codigo;
    strcpy(professor->nome, nome);

    ListaHet *novo = (ListaHet *)malloc(sizeof(ListaHet));
    novo->tipo = PROFESSOR;
    novo->info = professor;
    novo->prox = lista;

    return novo;
}

ListaHet *lst_insere_aluno(ListaHet *lista, int matricula, char *nome)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    aluno->matricula = matricula;
    strcpy(aluno->nome, nome);

    ListaHet *novo = (ListaHet *)malloc(sizeof(ListaHet));
    novo->tipo = ALUNO;
    novo->info = aluno;
    novo->prox = lista;

    return novo;
}

void *lst_imprime(ListaHet *lista)
{
    for (ListaHet *no = lista; no != NULL; no = no->prox)
    {
        switch (no->tipo)
        {
        case PROFESSOR:
            Professor *professor = (Professor *)no->info;

            printf("PROFESSOR %010d: %s\n", professor->codigo, professor->nome);
            break;
        
        case ALUNO:
            Aluno *aluno = (Aluno *)no->info;

            printf("ALUNO %010d: %s\n", aluno->matricula, aluno->nome);
            break;
        }
    }
}

int main()
{
    ListaHet *lista = NULL;
    lista = lst_insere_aluno(lista, 1, "Jaime");
    lista = lst_insere_professor(lista, 5, "Caio");
    lista = lst_insere_aluno(lista, 2, "Maria");
    lista = lst_insere_professor(lista, 8, "Carlos");
    lista = lst_insere_aluno(lista, 3, "Joao");

    lst_imprime(lista);
}