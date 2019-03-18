#include <stdio.h>
#include <string.h>

#define RANGE_X 3
#define RANGE_Y 3

int main()
{
    int qtd_testes = 0;
    int num_linha, num_col;

    /*Leia a quantidade de testes a serem realizados;*/
    fscanf(stdin, "%d", &qtd_testes);

    while (qtd_testes--) {
        fscanf(stdin, "%d %d", &num_linha, &num_col);
        printf("%d\n", (num_linha / RANGE_Y) * (num_col / RANGE_X));
    }
    return 0;
}