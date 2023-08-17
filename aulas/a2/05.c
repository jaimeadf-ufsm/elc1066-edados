float *alocar_vetor(int n)
{
    return (float *)malloc(n * sizeof(float));
}

void ler_vetor(int n, float *vet)
{
    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &vet[i]);
    }
}

float calcular_media(int n, float *vet)
{
    float soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += vet[i];
    }
    
    return soma / n;
}

float calcular_percentual_acima_da_media(int n, float *vet, float media)
{
    int acima = 0;

    for (int i = 0; i < n; i++)
    {
        if (vet[i] > media)
        {
            acima++;
        }
    }
    
    return (float)acima / n;
}

int main()
{
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    float *vet = alocar_vetor(n);
    
    ler_vetor(n, vet);

    float media = calcular_media(n, vet);
    float percentual = calcular_percentual_acima_da_media(n, vet, media);

    printf("A media dos elementos do vetor eh %.2f\n", media);
    printf("O percentual de elementos acima da media eh %.2f%%\n", percentual * 100);

    free(vet);

    return 0;
}