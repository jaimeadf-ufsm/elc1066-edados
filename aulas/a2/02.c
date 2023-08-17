#include <stdio.h>

int negativos (int n, float *vet)
{
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            neg++;
        }
    }
        
    return neg;
}

int main()
{
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    float *vet = malloc(n * sizeof(float));
    
    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &vet[i]);
    }
    
    printf("O vetor tem %d numeros negativos\n", negativos(n, vet));
    free(vet);

    return 0;
}