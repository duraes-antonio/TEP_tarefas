#include <stdio.h>
#include <string.h>

#define STR_RELAT   "report"
#define STR_DOAR    "donate"

int main()
{
    int qtd_op, temp_num;
    int saldo = 0;
    char operacao[10];

    /*Leia a quantidade de operações*/
    scanf("%d", &qtd_op);

    /*Enquanto houver operações a serem feitas*/
    while (qtd_op--)
    {
        scanf("%s", operacao);
        
        if (!strcmp(operacao, STR_DOAR))
        {
            scanf(" %d", &temp_num);
            saldo += temp_num;
        }

        else printf("%d\n", saldo);
    }

    return 0;
}