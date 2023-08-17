int main()
{
    int n;
    
    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    int *vet = malloc(n * sizeof(int));

    printf("Digite %d numeros: ", n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    printf("Os numeros na ordem inversa sao: ");

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");
}