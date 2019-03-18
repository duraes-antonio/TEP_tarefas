#include <stdio.h>
#include <string.h>

#define INTERV_TOTAL 40
#define GRAU_POR_NUM 360/INTERV_TOTAL

int main()
{
    int inicio, prim_num, seg_num, terc_num;
    int total_graus = 0;

    scanf("%d %d %d %d", &inicio, &prim_num, &seg_num, &terc_num);

    while ((inicio + prim_num + seg_num + terc_num) > 0)
    {
        //São 3 giros completos;
        total_graus += 3 * 360;

        /*Quando o sentido do giro for horário, subtraie-se o núm. p/ onde vou;
         *Exemplo (inicio = 0, núm = 30): (40 - 5 + 30) % 40 = 25 passos*/
        total_graus += (INTERV_TOTAL + inicio - prim_num) % 40 * GRAU_POR_NUM;

        /*Quando o giro for anti-horário, subtraie-se o núm. de onde estou;
         *Exemplo (num_1 = 0, num_2 = 30): (40 + 5 - 30) % 40 = 15 passos*/
        total_graus += (INTERV_TOTAL - prim_num + seg_num) % 40 * GRAU_POR_NUM;

        total_graus += (INTERV_TOTAL + seg_num - terc_num) % 40 * GRAU_POR_NUM;

        printf("%d", total_graus);

        scanf("%d %d %d %d", &inicio, &prim_num, &seg_num, &terc_num);
    }

    return 0;
}