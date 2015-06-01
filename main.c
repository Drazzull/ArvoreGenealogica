#include <stdio.h>
#include <string.h>

// Estrutura com as informações necessárias para cada pessoa
typedef struct sPessoa{
    char nome[100];
    struct sPessoa *pai;
    struct sPessoa *mae;
} PESSOA;

// Array com as pessoas
PESSOA arvore[15];

///
/// \brief construirArvore - Método utilizado para construção da árvore genealógica
///
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
        printf("Selecione uma opcao:\n");
        printf("1 - Construir arvore genealogica.\n");
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
            printf("Opcao invalida");
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

    printf("Informe o nome da sua mae: ");
    inserirRegistro(1, 0, 'M');

    printf("Informe o nome do seu pai: ");
    inserirRegistro(2, 0, 'P');

    printf("Informe o nome da avo materna: ");
    inserirRegistro(3, 1, 'M');

    printf("Informe o nome do avo materno: ");
    inserirRegistro(4, 1, 'P');

    printf("Informe o nome da avo paterna: ");
    inserirRegistro(5, 2, 'M');

    printf("Informe o nome do avo paterno: ");
    inserirRegistro(6, 2, 'P');

    printf("Informe o nome da mae da avo materna: ");
    inserirRegistro(7, 3, 'M');

    printf("Informe o nome do pai da avo materna: ");
    inserirRegistro(8, 3, 'P');

    printf("Informe o nome da mae do avo materno: ");
    inserirRegistro(9, 4, 'M');

    printf("Informe o nome do pai do avo materno: ");
    inserirRegistro(10, 4, 'P');

    printf("Informe o nome da mae da avo paterna: ");
    inserirRegistro(11, 5, 'M');

    printf("Informe o nome do pai da avo paterna: ");
    inserirRegistro(12, 5, 'P');

    printf("Informe o nome da mae do avo paterno: ");
    inserirRegistro(13, 6, 'M');

    printf("Informe o nome do pai do avo paterno: ");
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
