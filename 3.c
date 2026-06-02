#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int n, f;

    printf ("digite a altura do triangulo: ");
    scanf("%d",&n);
    printf("digite 0 para preenchido e 1 para vazado: ");
    scanf ("%d",&f);
    
    if (f == 0)
    {
    for (int linha = 1; linha <= n; linha++)
    {   

        for (int i = linha; i >= 1; i--)
        {
            printf("*");
        }
        printf("\n");
    }
    }
    else if (f == 1)
    {
      for (int linha = 1; linha <= n; linha++)
      {
        if (linha == 1)
        {
           printf("*\n");
        }
        else if (linha == n)
        {
            for (int i = linha; i >= 1; i--)
        {
            printf("*");
        }
        printf("\n");
        }
        else 
        {
            printf("*");

            for (int i = 1; i <= linha - 2; i++)
            {
                printf(" ");
            }
            printf("*");
            printf("\n");
        }
      }
    }
    else    
    {
        printf("opcao invalida");
    }
    return 0;
}