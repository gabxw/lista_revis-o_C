#include <stdio.h>
#include <locale.h>
#include <math.h> 
int main(){
    setlocale(LC_ALL, "Portuguese");
      int raio;
      printf("Informe um valor para o raio: ");
      scanf("%d", &raio); 
      int areaTotal = (int)(pow(raio,2) * 3.14); 
      printf("A área do circulo será: %d", areaTotal);
      
    return 0;
}
