#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int num1;
    int num2;
    printf("Digite o primeiro n�mero: ");
    scanf("%d", &num1);
    printf("Digite o segundo n�mero: ");
    scanf("%d", &num2);
    if(num1 > num2){
      printf("O numero %d � maior que o numero %d", num1, num2);
    }else{
      printf("O numero %d � maior que o numero %d", num2, num1);
    }
}
