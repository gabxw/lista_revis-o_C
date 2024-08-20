#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  int i;
  for(i = 10; i > 0; i--){
    printf("%i \n\n", i);
    sleep(1);
  }
  
  return 0;
}
