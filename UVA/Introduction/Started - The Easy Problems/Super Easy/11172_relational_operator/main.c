#include <stdio.h>

int main() {

    int qtd_testes = 0;
    int prim_num, seg_num;

    /*Leia a quantidade de testes a serem realizados;*/
    fscanf(stdin, "%d", &qtd_testes);

    while (qtd_testes--) {
        fscanf(stdin, "%d %d", &prim_num, &seg_num);

        if (prim_num < seg_num) printf("<\n");
        else if (prim_num > seg_num) printf(">\n");
        else printf("=\n");
    }

    return 0;
}