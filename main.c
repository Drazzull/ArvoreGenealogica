#include <stdio.h>

typedef struct sPessoa{
    char nome[100];
    struct sPessoa *pai;
    struct sPessoa *mae;
} PESSOA;

int main(void)
{
    printf("Hello World!\n");
    return 0;
}
