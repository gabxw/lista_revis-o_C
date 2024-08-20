#include <locale.h>
#include <math.h>
#include <stdio.h>
int main() {
  setlocale(LC_ALL, "Portuguese");
  int num, i;
  printf("Insira um número para ver a tabuada: ");
  scanf("%d", &num);
  for(i = 0; i <= 10; i++){
    printf("%d \n\n", num * i);
  }
  
  return 0;
}
