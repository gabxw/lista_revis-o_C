#include <locale.h>
#include <math.h>
#include <stdio.h>
int main() {
  setlocale(LC_ALL, "Portuguese");
  int celcius;
  printf("Escolha uma temperatura para a convers�o: ");
  scanf("%d", &celcius);
  float fahrenheit = (celcius * 1.8) + 32;
  printf("A convers�o para fahrenheit ser�: %f", fahrenheit);

  return 0;
}
