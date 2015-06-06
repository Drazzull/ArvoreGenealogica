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
        fflush(stdin);
        scanf("%i", &opcao);

        switch(opcao)
        {
            case 1:
                construirArvore();
                break;

            case 2:
                salvar();
                break;

            case 3:
                abrir();
                break;

            case 4:
                mostrar();
                break;

            case 5:
                pesquisar();
                break;

            case 6:
                return 0;

            default:
                printf("Opcao invalida.\n");
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
    // Verifica se a árvore foi preenchida
    if (!arvorePreenchida)
    {
        printf("\nA arvore ainda nao foi preenchida.\nE necessario construi-la ou abrir um arquivo com as informacoes salvas ");
        printf("antes de tentar salvar as informacoes em um arquivo de texto.\n");
        return;
    }

    FILE *fp_destino;
    char destino[] = "C:\\temp\\arvoreGenealogica.txt";

    // Cria o arquivo desejado e verifica se foi possível criá-lo
    fp_destino = fopen(destino,"wb");
    if (fp_destino == NULL)
    {
        printf("Não foi possivel criar o arquivo em %s", destino);
        return;
    }

    // Percorre a arvore para armazenar os registros um a um
    int i;
    for(i = 0; i < 15; i++)
    {
        // Grava um número identificador da ordem
        if (!fwrite(&i, sizeof(int), 1, fp_destino) == 1)
        {
            // Fecha o arquivo
            fclose(fp_destino);
            printf("Ocorreu um erro ao gravar a arvore no arquivo.\n");
            return;
        }

        // Grava o nome da pessoa
        if (!fwrite(arvore[i].nome, sizeof(char[100]), 1, fp_destino) == 1)
        {
            // Fecha o arquivo
            fclose(fp_destino);
            printf("Ocorreu um erro ao gravar a arvore no arquivo.\n");
            return;
        }
    }

    printf("Arquivo salvo com sucesso.\n");

    // Fecha o arquivo
    fclose(fp_destino);

}

void abrir()
{

}

void mostrar()
{
    //variável para guardar a quantia de caracteres do maior nome
    int tam = 0;
    int i, aux;

    //verifica o tamanho do maior nome e atribui para a variável tam
    for(i = 0; i <15; i++)
    {
        if (tam<strlen(arvore[i].nome))
        {
            tam = strlen(arvore[i].nome)+2;
        }
    }

    //caso os nomes sejam todos mais curtos do que "Bisavo"+2, atribui esse tamanho para tam
    if (tam < (strlen("Bisavo")+2))
    {
        tam = strlen("Bisavo")+2;
    }

    //imprime underlines para formar a caixa
    aux=0;
    while(aux<tam*8)
    {
        printf("_");
        aux++;
    }
    printf("\n");

    //imprime 8 vezes Bisavo, sempre preenchendo com espaços até atingir o tamanho do maior nome
    for(i = 0; i < 8; i++)
    {
        aux = strlen("Bisavo");
        printf("Bisavo");
        while(aux<tam)
        {
            printf(" ");
            aux++;
        }
    }
    printf("\n");

    //imprime underlines para formar a caixa
    aux=0;
    while(aux<tam*8)
    {
        printf("_");
        aux++;
    }
    printf("\n");

    //imprime o nome dos 8 bisavós, sempre preenchendo com espaços até atingir o tamanho do maior nome
    printf(arvore[14].nome);
    aux = strlen(arvore[14].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }

    printf(arvore[13].nome);
    aux = strlen(arvore[13].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[12].nome);
    aux = strlen(arvore[12].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[11].nome);
    aux = strlen(arvore[11].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[10].nome);
    aux = strlen(arvore[10].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[9].nome);
    aux = strlen(arvore[9].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[8].nome);
    aux = strlen(arvore[8].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[7].nome);
    aux = strlen(arvore[7].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    printf("\n");

    //imprime underlines para formar a caixa
    aux=0;
    while(aux<tam*8)
    {
        printf("_");
        aux++;
    }
    printf("\n");

    //avança tam/2 caracteres para deixar a apresentação tabulada
    aux=0;
    while(aux<tam/2)
    {
        printf(" ");
        aux++;
    }

    //imprime 4 vezes Avo, sempre preenchendo com espaços até atingir o tamanho do maior nome
    for(i = 0; i < 4; i++)
    {
        aux = strlen("Avo");
        printf("Avo");
        while(aux<tam*2)
        {
            printf(" ");
            aux++;
        }
    }
    printf("\n");

    //imprime underlines para formar a caixa
    aux=0;
    while(aux<tam*8)
    {
        printf("_");
        aux++;
    }
    printf("\n");

    //avança tam/2 caracteres para deixar a apresentação tabulada
    aux=0;
    while(aux<tam/2)
    {
        printf(" ");
        aux++;
    }

    //imprime o nome dos 4 avós, sempre preenchendo com espaços até atingir o tamanho do maior nome
    printf(arvore[6].nome);
    aux = strlen(arvore[6].nome);
    while(aux<tam*2)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[5].nome);
    aux = strlen(arvore[5].nome);
    while(aux<tam*2)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[4].nome);
    aux = strlen(arvore[4].nome);
    while(aux<tam*2)
    {
        printf(" ");
        aux++;
    }
    printf(arvore[3].nome);
    aux = strlen(arvore[3].nome);
    while(aux<tam*2)
    {
        printf(" ");
        aux++;
    }
    printf("\n");

    //imprime underlines para formar a caixa
    aux=0;
    while(aux<tam*8)
    {
        printf("_");
        aux++;
    }
    printf("\n");

    //avança 1.5*tam caracteres para deixar a apresentação tabulada
    aux=0;
    while(aux<(tam+tam/2))
    {
        printf(" ");
        aux++;
    }
    //imprime Pai e Mae, avançando com espaços até atigir o tamanho do maior nome
    printf("Pai");
    aux = strlen("Pai");
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    aux=0;
    while(aux<(tam*3))
    {
        printf(" ");
        aux++;
    }
    printf("Mae");
    aux=0;
    while(aux<(tam*3))
    {
        printf(" ");
        aux++;
    }
    printf("\n");

    //imprime underlines para formar a caixa
    aux=0;
    while(aux<tam*8)
    {
        printf("_");
        aux++;
    }
    printf("\n");

    //imprime o nome dos pais
    aux=0;
    while(aux<(tam+tam/2))
    {
        printf(" ");
        aux++;
    }
    printf(arvore[2].nome);
    aux = strlen(arvore[2].nome);
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    aux=0;
    while(aux<(tam*3))
    {
        printf(" ");
        aux++;
    }
    printf(arvore[1].nome);
    aux=0;
    while(aux<(tam*3))
    {
        printf(" ");
        aux++;
    }
    printf("\n");

    //imprime underlines para formar a caixa
    aux=0;
    while(aux<tam*8)
    {
        printf("_");
        aux++;
    }
    printf("\n");

    //avança 3.5*tam e imprime o nome do usuário
    aux=0;
    while(aux<(tam*3)+(tam/2))
    {
        printf(" ");
        aux++;
    }
    printf("Usuario");
    aux = strlen("Usuario");
    while(aux<tam)
    {
        printf(" ");
        aux++;
    }
    aux=0;
    while(aux<(tam*3)+(tam/2))
    {
        printf(" ");
        aux++;
    }
    printf("\n");
    aux=0;
    while(aux<(tam*3)+(tam/2))
    {
        printf(" ");
        aux++;
    }
    printf(arvore[0].nome);
    aux=0;
    while(aux<(tam*3)+(tam/2))
    {
        printf(" ");
        aux++;
    }
    printf("\n");
    //imprime underlines para formar a caixa
    aux=0;
    while(aux<tam*8)
    {
        printf("_");
        aux++;
    }
    printf("\n");
}

void pesquisar()
{
    printf("Nome: ");
    char valor[100];
    int i = 0;
    for(i = 0; i < 100; i++)
    {
        valor[i] = ' ';
    }

    fflush(stdin);
    gets(valor);

    //busca o nome digitado na arvore
    for(i=0; i<15; i++){
        if (strcmp(arvore[i].nome, valor))
        {
            // PROBLEMA AQUI!!!
            break;
        }
    }

    //de acordo com o índice, imprime a relação familiar
    switch(i)
    {
        case 0:
            printf("O nome corresponde ao seu.\n");
            break;
        case 1:
            printf("O nome corresponde a sua mae.\n");
            break;
        case 2:
            printf("O nome corresponde ao seu pai.\n");
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            printf("O nome corresponde a um avo.\n");
            break;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            printf("O nome corresponde a um bisavo.\n");
            break;
        default:
            printf("O nome nao corresponde ao grupo familiar.\n");
            break;
    }
}
