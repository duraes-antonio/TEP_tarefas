#include <stdio.h>

#define MAX_DIST 0
#define MIN_DIST 99

int main() {


    int qtd_testes, qtd_lojas, temp_num;

    /*Inicializar com valores extremos p/ permitir a comparação;*/
    int max_dist = MAX_DIST;
    int min_dist = MIN_DIST;

    fscanf(stdin, "%d", &qtd_testes);

    while(qtd_testes--) {
        fscanf(stdin, "%d", & qtd_lojas);

        /*Enquanto houver lojas a serem processadas;*/
        while (qtd_lojas--) {

            /*Leia a posição da loja corrente;*/
            fscanf(stdin, "%d", &temp_num);

            if (temp_num > max_dist) max_dist = temp_num;
            if (temp_num < min_dist) min_dist = temp_num;
        }

        /*O resultado é a (posição maior - a menor)*2 [Ida e volta ao carro];*/
        printf("%d\n", (max_dist - min_dist) * 2);
        max_dist = MAX_DIST;
        min_dist = MIN_DIST;
    }
    return 0;
}