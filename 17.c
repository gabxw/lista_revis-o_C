#include <stdio.h>
#include <locale.h>


int main() {
    int a, b,temp;
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um n�mero: ");
    scanf("%d", &a);
    printf("Insira outro n�mero: ");
    scanf("%d", &b);

	    while (b != 0) {
	        temp = b;
	        b = a % b;
	        a = temp;
	    }
	    printf("%d", temp);
    return 0;
}
