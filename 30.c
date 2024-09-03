#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *str) {
  int sign = 1;
  int result = 0;
  int i = 0;

  // Ignora espaços em branco no início
  while (str[i] == ' ') {
    i++;
  }

  // Verifica o sinal
  if (str[i] == '-' || str[i] == '+') {
    sign = (str[i] == '-') ? -1 : 1;
    i++;
  }

  // Converte os dígitos para inteiro
  while (str[i] >= '0' && str[i] <= '9') {
    result = result * 10 + (str[i] - '0');
    i++;
  }

  return sign * result;
}

int main() {
  char str[] = "12345";

  int num = my_atoi(str);

  printf("O inteiro convertido é: %d\n", num);

  return 0;
}
