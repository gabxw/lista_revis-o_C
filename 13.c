#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int a, b, auxiliar, i, num;
    a = 0;
    b = 1;
    printf("Digite um n�mero: ");
    scanf("%d", &num);
    printf("\nS�rie de Fibonacci:\n\n");
    printf("%d\n%d\n",a, b);
    for(i = 0; i <= num; i++) {
        auxiliar = a + b;
        a = b;
        b = auxiliar;
        printf("%d\n", auxiliar);
    }
}
