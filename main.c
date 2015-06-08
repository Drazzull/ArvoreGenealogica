/*
    Equipe:
            Arthur B. Bilibio
            Johnatan M. Rosa
            Welenton A. Webler
*/

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
void inserirRegistro(int atual, int filho, char tipoRegistro, char *nome)
{
    // Altera o nome do registro atual conforme o passado por parâmetro
    strcpy(arvore[atual].nome, nome);

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
    // Apresenta uma mensagem ao usuário e obtém o valor do nome que o mesmo digitará
    printf("Informe seu nome: ");
    char valor[100];
    fflush(stdin);
    gets(valor);
    inserirRegistro(0, 0, 'F', valor);

    printf("Informe o nome da sua mae: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(1, 0, 'M', valor);

    printf("Informe o nome do seu pai: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(2, 0, 'P', valor);

    printf("Informe o nome da avo materna: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(3, 1, 'M', valor);

    printf("Informe o nome do avo materno: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(4, 1, 'P', valor);

    printf("Informe o nome da avo paterna: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(5, 2, 'M', valor);

    printf("Informe o nome do avo paterno: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(6, 2, 'P', valor);

    printf("Informe o nome da mae da avo materna: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(7, 3, 'M', valor);

    printf("Informe o nome do pai da avo materna: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(8, 3, 'P', valor);

    printf("Informe o nome da mae do avo materno: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(9, 4, 'M', valor);

    printf("Informe o nome do pai do avo materno: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(10, 4, 'P', valor);

    printf("Informe o nome da mae da avo paterna: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(11, 5, 'M', valor);

    printf("Informe o nome do pai da avo paterna: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(12, 5, 'P', valor);

    printf("Informe o nome da mae do avo paterno: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(13, 6, 'M', valor);

    printf("Informe o nome do pai do avo paterno: ");
    fflush(stdin);
    gets(valor);
    inserirRegistro(14, 6, 'P', valor);

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
    fclose(fp_destino);
}

void abrir()
{
    FILE *fp_origem;
    char origem[] = "C:\\temp\\arvoreGenealogica.txt";

    int n = 0, i = 0;
    char nomes[15][100];

    // Abre o arquivo para que seja possível lê-lo
    fp_origem = fopen(origem,"rb");
    if (fp_origem == NULL)
    {
        printf("Não foi possivel abrir o arquivo em %s", origem);
        return;
    }

    n = fread(nomes, sizeof(char[100]), 15, fp_origem);

    for(i = 0; i < n; i++)
    {
        int filho = 0;
        char tipoRegistro = ' ';
        switch(i)
        {
            case 0:
                filho = 0;
                tipoRegistro = 'F';
                break;

            case 1:
                filho = 0;
                tipoRegistro = 'M';
                break;
            case 2:
                filho = 0;
                tipoRegistro = 'P';
                break;

            case 3:
                filho = 1;
                tipoRegistro = 'M';
                break;

            case 4:
                filho = 1;
                tipoRegistro = 'P';
                break;

            case 5:
                filho = 2;
                tipoRegistro = 'M';
                break;

            case 6:
                filho = 2;
                tipoRegistro = 'P';
                break;

            case 7:
                filho = 3;
                tipoRegistro = 'M';
                break;

            case 8:
                filho = 3;
                tipoRegistro = 'P';
                break;

            case 9:
                filho = 4;
                tipoRegistro = 'M';
                break;

            case 10:
                filho = 4;
                tipoRegistro = 'P';
                break;

            case 11:
                filho = 5;
                tipoRegistro = 'M';
                break;

            case 12:
                filho = 5;
                tipoRegistro = 'P';
                break;

            case 13:
                filho = 6;
                tipoRegistro = 'M';
                break;

            case 14:
                filho = 6;
                tipoRegistro = 'P';
                break;

            default:
                printf("O registro no arquivo de texto nao corresponde ao grupo familiar.\n");
                fclose(fp_origem);
                return;
        }

        // Após definir as informações do registro, insere o mesmo na árvore
        inserirRegistro(i, filho, tipoRegistro, nomes[i]);

        // Define que a árvore foi preenchida
        arvorePreenchida = 1;
    }

    printf("Arvore recuperada com sucesso.\n");
    fclose(fp_origem);
}

void mostrar()
{
    // Verifica se a árvore foi preenchida
    if (!arvorePreenchida)
    {
        printf("\nA arvore ainda nao foi preenchida.\nE necessario construi-la ou abrir um arquivo com as informacoes salvas ");
        printf("antes de tentar mostrá-la.\n");
        return;
    }

    //variável para guardar a quantia de caracteres do maior nome
    unsigned int tam = 0, i, aux = 0;

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
    // Verifica se a árvore foi preenchida
    if (!arvorePreenchida)
    {
        printf("\nA arvore ainda nao foi preenchida.\nE necessario construi-la ou abrir um arquivo com as informacoes salvas ");
        printf("antes de tentar pesquisar por um nome.\n");
        return;
    }

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
    for(i=0; i<15; i++)
    {
        if (strcmp(arvore[i].nome, valor) == 0)
        {
            break;
        }
    }

    //de acordo com o índice, imprime a relação familiar
    switch(i)
    {
        case 0:
            printf("Você digitou seu nome.\n");
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
