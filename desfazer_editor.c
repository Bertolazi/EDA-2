#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_TAM_STR 100
#define MAX_TAM_PILHA 100

typedef struct {
    char* pilha[MAX_TAM_PILHA];
    int top;
} minha_pilha;


void inicio_pilha(minha_pilha* s)   // Inicializa a pilha em -1 assim informando que ela está vazia
{  
   s-> top = -1;
}

int empilha_string(minha_pilha* s, const char* str)   // Função para empilhar uma nova string na pilha
{
   if(s->top >= MAX_TAM_PILHA -1){
      return 0;
   }
   s->top++;
   s->pilha[s->top] = (char*)malloc(strlen(str)+1);
   strcpy(s->pilha[s->top], str);
   return 1;
}

char* desempilha(minha_pilha* s)   // Função para desempilhar uma string da pilha
{
   if(s->top < 0)
      return NULL;
   char* str = s->pilha[s->top];
   s->top--;
   return str;
}

void valida_opcao(char op[], minha_pilha* pilha) {
   if (strcmp(op, "desfazer") == 0) {
       char* lastChange = desempilha(pilha);
       if (lastChange) {
           printf("%s\n", lastChange);
           free(lastChange); 
       } else {
           printf("NULL\n");
       }
   } else if (strncmp(op, "inserir ", 8) == 0) {
       char* str = op + 8;
       empilha_string(pilha, str);
   }
}

int main() {
   minha_pilha pilha;
   inicio_pilha(&pilha);

   char input[MAX_TAM_STR + 10]; // Buffer para entrada

   while (fgets(input, sizeof(input), stdin)) {
       // Remove o caractere de nova linha
       input[strcspn(input, "\n")] = 0;

       valida_opcao(input, &pilha);
   }

   // Libera a memória restante na pilha
   while (pilha.top >= 0) {
       free(desempilha(&pilha));
   }

   return 0;
}
