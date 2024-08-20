#include <locale.h>
#include <stdio.h>
int main() {
  setlocale(LC_ALL, "Portuguese");
  int num;
  int fatorial = 1;
  int i;
  printf("Insira um número: ");
  scanf("%d", &num);
  for( i = 1; i <= num; i++){
    fatorial = fatorial * i;
  }
  printf("O fatorial deste número será %d \n\n", fatorial); 
  
  return 0;
}
