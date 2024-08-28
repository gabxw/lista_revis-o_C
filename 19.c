#include <stdio.h>
#include <locale.h>

int main() {
    int a, b,temp,i,soma;
    setlocale(LC_ALL, "Portuguese");

    printf("Insira um número: ");
    scanf("%d", &a);

    for(i=0; i>=a; i++){
        if(i % a == 0){
            soma += i; 
        }
    }
    if(soma == a){
        printf("O número é perfeito.");
    }else{
        printf("O número não é perfeito.");
    }
    
    return 0;
}
