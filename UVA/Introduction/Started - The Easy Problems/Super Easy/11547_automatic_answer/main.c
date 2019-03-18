#include <stdio.h>
#include <math.h>

int calc_qtd_dezenas(int num)
{
    int result_num = (num * 567 / 9 + 7492) * 235 / 47 - 498;
    return abs((result_num - (result_num / 100 * 100)) / 10);
}

int main()
{
    int qtd_testes, temp_num;

    fscanf(stdin, "%d", &qtd_testes);

    /*Enquanto a quantidade de coordenads não for 0*/
    while (qtd_testes--)
    {
        /*Leia o número, faça o calculo e imprima*/
        fscanf(stdin, "%d", &temp_num);

        printf("%d\n", calc_qtd_dezenas(temp_num));
    }

    return 0;
}