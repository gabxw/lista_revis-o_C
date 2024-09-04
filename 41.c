#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para cifrar uma mensagem usando a Cifra de César
char* caesarCipher(char* message, int shift) {
  int i;

  for (i = 0; message[i] != '\0'; i++) {
    if (isalpha(message[i])) {
      // Calcula a nova letra cifrada
      char base = isupper(message[i]) ? 'A' : 'a';
      message[i] = base + (message[i] - base + shift) % 26;
    }
  }

  return message;
}

int main() {
  char message[100];
  int shift;

  printf("Digite a mensagem a ser cifrada: ");
  fgets(message, 100, stdin);
  message[strcspn(message, "\n")] = '\0';

  printf("Digite o deslocamento (chave): ");
  scanf("%d", &shift);

  char* encryptedMessage = caesarCipher(message, shift);

  printf("Mensagem cifrada: %s\n", encryptedMessage);

  return 0;
}
