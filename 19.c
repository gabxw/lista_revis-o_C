#include <stdio.h>
#include <locale.h>

int main() {
    int a, b,temp,i,soma;
    setlocale(LC_ALL, "Portuguese");

    printf("Insira um n�mero: ");
    scanf("%d", &a);

    for(i=0; i>=a; i++){
        if(i % a == 0){
            soma += i; 
        }
    }
    if(soma == a){
        printf("O n�mero � perfeito.");
    }else{
        printf("O n�mero n�o � perfeito.");
    }
    
    return 0;
}
