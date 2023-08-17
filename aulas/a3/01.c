#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime_matriz(int m, int n, int *mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i * n + j]);
        }
        
        printf("\n");
    }
}

void preenche_matriz(int m, int n, int *mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i * n + j] = rand() % 10;
        }
    }
}

int main()
{
    srand(time(NULL));

    int m, n;

    printf("Digite as dimensoes mxn da matriz: ");
    scanf(" %d %d", &m, &n);

    int *mat = (int *)malloc(m * n * sizeof(int));

    preenche_matriz(m, n, mat);
    imprime_matriz(m, n, mat);
    free(mat);
}

