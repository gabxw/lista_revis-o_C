#include <stdio.h>
#include <locale.h>
int numero;

int main(void) {
  setlocale(LC_ALL,"");
  
  printf("informe um numero: \n");
  scanf("%d", &numero);
  if(numero % 2 == 0){
    printf("o numero � par");
  }else{
    printf("o numero � impar");
  } 
  return 0;
}

