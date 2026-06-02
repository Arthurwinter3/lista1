#include <stdio.h>
#include <stdlib.h>

int main() 
{
    system("clear"); // ou "cls" se der ruim no seu terminal
    
    int n;

    printf("Informe a largura central do losango: ");
    scanf("%d", &n);

    
    if (n % 2 == 0) {
        n++; 
    }


    for (int i = 1; i <= n; i += 2) 
    {
       
        for (int espaco = 0; espaco < (n - i) / 2; espaco++) 
        {
            printf(" ");
        }
        
        
        for (int x = 0; x < i; x++) 
        {
            printf("x");
        }
        
        printf("\n");
    }

   
    for (int i = n - 2; i >= 1; i -= 2) 
    {
        
        for (int espaco = 0; espaco < (n - i) / 2; espaco++) 
        {
            printf(" ");
        }
        
        
        for (int x = 0; x < i; x++) 
        {
            printf("x");
        }
        
        printf("\n");
    }

    return 0;
}