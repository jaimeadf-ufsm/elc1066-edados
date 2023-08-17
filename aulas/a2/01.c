#include <stdio.h>

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y)
{
    return (x0 <= x && x <= x1 && y0 <= y && y <= y1);
}

int main()
{
    int x0, y0, x1, y1, x, y;
    printf("Digite as coordenadas do retangulo: ");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    printf("Digite as coordenadas do ponto: ");
    scanf("%d %d", &x, &y);
    
    if (dentro_ret(x0, y0, x1, y1, x, y))
        printf("O ponto esta dentro do retangulo\n");
    else
        printf("O ponto esta fora do retangulo\n");

    return 0;
}