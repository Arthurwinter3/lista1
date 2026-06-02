#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");

    int N;

    
    do {
        printf("Digite o valor de N : ");
        scanf("%d", &N);
        if (N < 3) {
            printf("Valor invalido! N deve ser maior ou igual a 3.\n");
        }
    } while (N < 3);

    int matriz[N][N];
    int top = 0, bottom = N - 1, left = 0, right = N - 1;
    int num = 1;

    
    while (num <= N * N) {
     
        for (int i = left; i <= right; i++)
            matriz[top][i] = num++;
        top++;

       
        for (int i = top; i <= bottom; i++)
            matriz[i][right] = num++;
        right--;

        
        for (int i = right; i >= left; i--)
            matriz[bottom][i] = num++;
        bottom--;

       
        for (int i = bottom; i >= top; i--)
            matriz[i][left] = num++;
        left++;
    }

    
    int max = N * N;
    int largura = 0;
    while (max > 0) {
        largura++;
        max /= 10;
    }

    // Exibe a matriz
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%*d ", largura, matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}