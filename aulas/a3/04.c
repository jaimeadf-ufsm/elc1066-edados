#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **aloca_matriz(int m, int n)
{
    int **mat = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    return mat;
}

void desaloca_matriz(int m, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        free(mat[i]);
    }

    free(mat);
}

void preenche_matriz(int m, int n, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = rand() % 10;
        }
    }
}

void mostra_matriz(int m, int n, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }

        printf("\n");
    }
}

int **soma_matriz(int m, int n, int **mat1, int **mat2)
{
    int **res = aloca_matriz(m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return res;
}

int main()
{
    srand(time(NULL));

    int m, n;

    printf("Digite as dimensoes mxn da matriz: ");
    scanf(" %d %d", &m, &n);

    int **mat1 = aloca_matriz(m, n);
    int **mat2 = aloca_matriz(m, n);

    preenche_matriz(m, n, mat1);
    preenche_matriz(m, n, mat2);

    int **res = soma_matriz(m, n, mat1, mat2);

    printf("Matriz 1:\n");
    mostra_matriz(m, n, mat1);

    printf("\nMatriz 2:\n");
    mostra_matriz(m, n, mat2);

    printf("\nSoma:\n");
    mostra_matriz(m, n, res);

    desaloca_matriz(m, mat1);
    desaloca_matriz(m, mat2);
    desaloca_matriz(m, res);
}