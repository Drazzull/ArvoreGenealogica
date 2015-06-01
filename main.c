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
int arvorePreenchida = 0;

///
/// \brief construirArvore - Método utilizado para construção da árvore genealógica
///
void construirArvore();

///
/// \brief salvar - Método utilizado para salvar a árvore em um arquivo de texto
///
void salvar();

///
/// \brief abrir - Método utilizado para abrir o arquivo de texto contendo a árvore pronta
///
void abrir();

///
/// \brief mostrar - Imprime a árvore genealógica na tela
///
void mostrar();

///
/// \brief pesquisar - Pesquisa por uma pessoa para saber o nível de parentesco
///
void pesquisar();

///
/// \brief main - Método principal contendo o menu e as demais chamadas de método
/// \return - 0
///
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
            construirArvore();
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

///
/// \brief inserirRegistro - Insere um registro no array
/// \param atual - ID do registro que será inserido
/// \param filho - ID do filho do registro atual
/// \param tipoRegistro - (M) Mãe, (P) Pai, (F) Filho
///
void inserirRegistro(int atual, int filho, char tipoRegistro)
{
    // Cria uma variável para conter a string digitada pelo usuário
    char valor[100];
    int i = 0;
    for(i = 0; i < 100; i++)
    {
        valor[i] = ' ';
    }

    // Limpa o buffer de entrada, obtém o valor que o usuário digitar e armazena no array
    fflush(stdin);
    gets(valor);
    strcpy(arvore[atual].nome, valor);

    // Preenche a mãe ou o pai do filho de acordo com o registro
    switch(tipoRegistro)
    {
    case 'M':
        // Registro do tipo Mãe
        arvore[filho].mae = &arvore[atual];
        break;

    case 'P':
        // Registro do tipo Pai
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

    // Define que a árvore foi preenchida
    arvorePreenchida = 1;
}

void salvar()
{
    if (!arvorePreenchida)
    {
        printf("A arvore ainda não foi preenchida.\nE necessario construi-la ou abrir um arquivo com as informacoes salvas ");
        printf("antes de tentar salvar as informacoes em um arquivo de texto.");
        return;
    }

    FILE *fp_destino;
    char destino[] = "C:\\temp\\arvoreGenealogica.txt";

    // Cria o arquivo desejado e verifica se foi possível criá-lo
    fp_destino = fopen(destino,"wb");
    if(fp_destino == NULL)
    {
        printf("Não foi possivel criar o arquivo em %s", destino);
        return;
    }

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
