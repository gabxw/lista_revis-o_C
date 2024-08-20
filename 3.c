#include <stdio.h>
#include <locale.h>
int numero;

int main(void) {
  setlocale(LC_ALL,"");
  
  printf("informe um numero: \n");
  scanf("%d", &numero);
  if(numero % 2 == 0){
    printf("o numero é par");
  }else{
    printf("o numero é impar");
  } 
  return 0;
}

