#include <locale.h>
#include <math.h>
#include <stdio.h>
int main() {
  setlocale(LC_ALL, "Portuguese");
  int celcius;
  printf("Escolha uma temperatura para a conversão: ");
  scanf("%d", &celcius);
  float fahrenheit = (celcius * 1.8) + 32;
  printf("A conversão para fahrenheit será: %f", fahrenheit);

  return 0;
}
