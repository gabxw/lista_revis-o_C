#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int num,valor,valor2;

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Informe um numero com mais de dois digitos: ");
    scanf("%i", &num);
    while(num > 0){
       valor = num % 10;
       valor2 = valor2 * 10 + valor;
       num = num / 10;
    }
    printf("%i",valor2);
    
    return 0;
}
