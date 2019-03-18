#include <stdio.h>
#include <string.h>

#define MAX_DIM 20

int main()
{
    int qtd_testes, i, l, w, h;

    /*Leia a quantidade de testes*/
    scanf("%d", &qtd_testes);

    /*Para cada teste*/
    for (i = 0; i < qtd_testes; i++)
    {
        scanf("%d %d %d", &l, &w, &h);
        
        /*Imprima 'good' quando a mala possuir todas dimensões <= a 20*/
        if(l <= MAX_DIM && w <= MAX_DIM && h <= MAX_DIM) {
            printf("Case %d: good\n", i+1);
        }

        else printf("Case %d: bad\n", i+1);
    }

    return 0;
}