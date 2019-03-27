#include <stdio.h>
#include <string.h>

int main()
{
    int qtd_testes, i;
    char numero[10];

    scanf("%d", &qtd_testes);

    /*Leia cada número em extensop*/
    for (i = 0; i < qtd_testes; i++)
    {
        scanf("%s", numero);

        if(strlen(numero) > 3) printf("3\n");

        else if (
            (numero[0] == 'o' && numero[1] == 'n')
        || (numero[0] == 'o' && numero[2] == 'e')
        || (numero[1] == 'n' && numero[2] == 'e')) {
            printf("1\n");
        }

        else printf("2\n");
    }

    return 0;
}