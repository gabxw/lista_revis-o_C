#include <stdio.h>
#include <string.h>

int main() {
  char string[100];
  int vogais = 0;

  printf("Digite uma string: ");
  fgets(string, 100, stdin);

  // Remove o caractere de nova linha do final da string
  string[strcspn(string, "\n")] = 0;

  // Verifica cada caractere da string
  for (int i = 0; string[i] != '\0'; i++) {
    switch (string[i]) {
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
        vogais++;
        break;
    }
  }

  printf("O número de vogais na string é: %d\n", vogais);

  return 0;
}
