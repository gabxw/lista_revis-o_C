#include <stdio.h>
#include <locale.h>
int main(){
  setlocale(LC_ALL,"Portuguese");
  int primo;
  printf("Qual n�mero deseja saber se � primo?: ");
  scanf("%i", &primo);
  if(primo == 2 || primo == 3 || primo == 5 || primo == 7){
    printf("O numero � primo");
  }else if (primo % 2 == 0 || primo % 3 == 0 || primo % 5 == 0 || primo == 1){
    printf("O numero n�o � primo");
  }else{
    printf("� primo");
  }
  
  return 0;
}
