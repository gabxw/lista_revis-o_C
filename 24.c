#include <stdio.h>
#include <math.h>

int main() {
  long long binario, decimal = 0, base = 1, resto;

  printf("Digite um número binário: ");
  scanf("%lld", &binario);

  while (binario != 0) {
    resto = binario % 10;
    decimal += resto * base;
    binario /= 10;
    base *= 2;
  }

  printf("O número decimal equivalente é: %lld\n", decimal);

  return 0;
}
