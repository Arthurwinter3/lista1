#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
      int B, L, A;

    do {
        printf("Digite o valor de B: ");
        scanf("%d", &B);
        if (B < 3 || B % 2 == 0) {
            printf("Valor invalido! B deve ser impar e maior ou igual a 3.\n");
        }
    } while (B < 3 || B % 2 == 0);


    do {
        printf("Digite o valor de L: ", B / 2);
        scanf("%d", &L);
        if (L < 1 || L > B / 2) {
            printf("Valor invalido! L deve ser pelo menos 1 e no maximo %d.\n", B / 2);
        }
    } while (L < 1 || L > B / 2);

    
    do {
        printf("Digite o valor de A: ", B / 2);
        scanf("%d", &A);
        if (A < 2 || A > B / 2) {
            printf("Valor invalido! A deve ser pelo menos 2 e no maximo %d.\n", B / 2);
        }
    } while (A < 2 || A > B / 2);

    int centro = B / 2;
    int niveis = (B + 1) / 2;

    printf("\n");

   
    for (int i = 0; i < niveis; i++) {
        int asteriscos = 2 * i + 1;
        int espacos = centro - i;

        // Espaços à esquerda
        for (int j = 0; j < espacos; j++) {
            printf(" ");
        }
        // Asteriscos
        for (int j = 0; j < asteriscos; j++) {
            printf("*");
        }
        printf("\n");
    }

 
    int espacos_tronco = centro - (L / 2);
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < espacos_tronco; j++) {
            printf(" ");
        }
        for (int j = 0; j < L; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}