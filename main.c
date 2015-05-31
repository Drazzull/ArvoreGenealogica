#include <stdio.h>
#include <string.h>

typedef struct sPessoa{
    char nome[100];
    struct sPessoa *pai;
    struct sPessoa *mae;
} PESSOA;

int numeroReg = 15;
PESSOA arvore[15];

void construirArvore();
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
        scanf("%i", &opcao);

        switch(opcao)
        {
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

void inserirRegistro(int atual, int filho, char tipoRegistro)
{
    char valor[100];
    int i = 0;
    for(i = 0; i < 100; i++)
    {
        valor[i] = ' ';
    }

    fflush(stdin);
    gets(valor);
    strcpy(arvore[atual].nome, valor);

    switch(tipoRegistro)
    {
    case 'M':
        arvore[filho].mae = &arvore[atual];
        break;

    case 'P':
        arvore[filho].pai = &arvore[atual];
        break;
    }
}

void construirArvore()
{
    printf("Informe seu nome: ");
    inserirRegistro(0, 0, 'F');

    printf("Informe o nome da sua mãe: ");
    inserirRegistro(1, 0, 'M');

    printf("Informe o nome do seu pai: ");
    inserirRegistro(2, 0, 'P');

    printf("Informe o nome da avó materna: ");
    inserirRegistro(3, 1, 'M');

    printf("Informe o nome do avô materno: ");
    inserirRegistro(4, 1, 'P');

    printf("Informe o nome da avó paterna: ");
    inserirRegistro(5, 2, 'M');

    printf("Informe o nome do avô paterno: ");
    inserirRegistro(6, 2, 'P');

    printf("Informe o nome da mãe da avó materna: ");
    inserirRegistro(7, 3, 'M');

    printf("Informe o nome do pai da avó materna: ");
    inserirRegistro(8, 3, 'P');

    printf("Informe o nome da mãe do avô materno: ");
    inserirRegistro(9, 4, 'M');

    printf("Informe o nome do pai do avô materno: ");
    inserirRegistro(10, 4, 'P');

    printf("Informe o nome da mãe da avó paterna: ");
    inserirRegistro(11, 5, 'M');

    printf("Informe o nome do pai da avó paterna: ");
    inserirRegistro(12, 5, 'P');

    printf("Informe o nome da mãe do avô paterno: ");
    inserirRegistro(13, 6, 'M');

    printf("Informe o nome do pai do avô paterno: ");
    inserirRegistro(14, 6, 'P');
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
