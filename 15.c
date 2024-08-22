#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int num,potencia,resultado;

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Informe um numero: ");
    scanf("%i", &num);
    printf("Informa um numero para ser sua pôtencia: ");
    scanf("%d", &potencia);
    resultado = (int)pow(num, potencia);
    printf("o número %d elevado a %d será: %d",num,potencia,resultado);
    return 0;
}
