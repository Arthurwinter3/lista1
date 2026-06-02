#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int n;

    
    do
    {

     printf ("digite um numeno maior ou igual a 2: ");
     scanf("%d",&n);

    } while (n < 2);

    for (int linha = 1; linha <= n; linha++)
    {   
        for(int espaço = 1; espaço <= n - linha; espaço++)
        {
            printf("  ");
        }
        for(int i = 1; i <= linha; i++)

        {
            printf("%d ",i);
        }

        for (int i = linha - 1; i >= 1; i--)
        {
            printf("%d ",i);
        }
        printf("\n");
    }

    return 0;
}