#include <stdio.h>

int main()
{
    int qtd_testes, temp_cont, temp_num, i, num_teste;

    scanf("%d", &qtd_testes);
    num_teste = 0;

    /*Enquanto o número de testes for != 0*/
    while(qtd_testes)
    {
        /*zere o contador de eventos*/
        temp_cont = 0;

        /*Leia cada número do evento*/
        for(i = 0; i < qtd_testes; i++) {

            scanf("%d", &temp_num);

            if (temp_num > 0) temp_cont++;
            else temp_cont--;
        }

        printf("Case %d: %d\n", ++num_teste, temp_cont);
        scanf("%d", &qtd_testes);
    }

    return 0;
}