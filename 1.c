#include <stdio.h>
#include <stdlib.h>

int main()
{
    int altura, largura, opcao;
    system("cls");

    printf ("digite altura: ");
    scanf("%d",&altura);

    printf ("digite largura: ");
    scanf("%d",&largura);

    printf ("vazio = 0 preenchido = 1: ");
    scanf("%d",&opcao);

    
if (opcao == 1) 
{
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= largura; j++) {
            printf(" * ");
        }
        printf("\n");
    } 
} 
else if (opcao == 0) 
{
    for (int i = 1; i <= altura; i++) {
        if (i == 1 || i == altura) {
            for (int j = 1; j <= largura; j++) {
                printf(" * ");
            }
        } else {
            printf(" * ");
            for (int j = 1; j <= largura - 2; j++) {
                printf("   ");
            }
            printf(" * ");
        }
        printf("\n");
}
} 
else 
{
    printf("Opcao invalida\n");
}
    

    return 0;
}