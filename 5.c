#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
      int num1;
      int num2;
      int num3;

      printf("Digite o primeiro n�mero: ");
      scanf("%d", &num1);
      printf("Digite o segundo n�mero: ");
      scanf("%d", &num2);
      printf("Digite o terceiro n�mero: ");
      scanf("%d", &num3);
      float valor = (num1 + num2) / 2;
      printf("A m�dia ser�: %.2f",valor);
      
      
    return 0;
}
