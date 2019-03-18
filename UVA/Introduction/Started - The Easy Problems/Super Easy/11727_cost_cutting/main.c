#include <stdio.h>

int main()
{
    int qtd_testes, num_1, num_2, num_3, i;

    fscanf(stdin, "%d", &qtd_testes);

    /*Enquanto a quantidade de testes não for 0*/
    for (i = 0; i < qtd_testes; i++)
    {
        /*Leia os números, faça o calculo e imprima*/
        fscanf(stdin, "%d %d %d", &num_1, &num_2, &num_3);
        
        printf("Case %d: ", i + 1);

        if (num_1 > num_2 && num_1 < num_3) printf("%d\n", num_1);
        else if (num_1 > num_3 && num_1 < num_2) printf("%d\n", num_1);
        else if (num_2 > num_1 && num_2 < num_3) printf("%d\n", num_2);
        else if (num_2 > num_3 && num_2 < num_1) printf("%d\n", num_2);
        else if (num_3 > num_1 && num_3 < num_2) printf("%d\n", num_3);
        else if (num_3 > num_2 && num_3 < num_1) printf("%d\n", num_3);
    }

    return 0;
}