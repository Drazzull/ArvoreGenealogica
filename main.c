#include <stdio.h>

typedef struct sPessoa{
    char nome[100];
    struct sPessoa *pai;
    struct sPessoa *mae;
} PESSOA;

void salvar();
void abrir();
void mostrar();
void pesquisar();

int main(void)
{
    while(1)
    {
        int opcao = 0;
        printf("Selecione uma opção:\n");
        printf("1 - Construir árvore genealógica.\n");
        printf("2 - Salvar\n");
        printf("3 - Abrir\n");
        printf("4 - Mostrar\n");
        printf("5 - Pesquisar\n");
        printf("6 - Sair\n");

        switch(opcao)
        {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            return 0;
        default:
            printf("Opção inválida");
            break;
        }
    }
    return 0;
}

void salvar()
{

}

void abrir()
{

}

void mostrar()
{

}

void pesquisar()
{

}
