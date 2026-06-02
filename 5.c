#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
   

int n, linha, coluna, espaco, valor;

printf("Digite a altura: ");
scanf("%d",&n);


for (linha = 0; linha < n; linha++) 
{
    valor = 1;

   
   for (espaco = 1; espaco <= n - linha; espaco++) 
    {
        printf(" "); 
    }

    
    for (coluna = 0; coluna <= linha; coluna++) 
    {
        printf("%d",valor); 
        printf(" ");
        
      
        valor = valor * (linha - coluna) / (coluna + 1);
    }
    
   printf("\n");
}

    return 0;
}