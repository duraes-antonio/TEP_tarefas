//#include <stdio.h>
//
//int main() {
//
//    int qtd_disp, qtd_op, limite_amper;
//    int consumo_atual, id_disp, consumo_total, max_consumo, i, j;
//
//    int disp_consumos[20];
//    int disp_estados[20];
//
//    i = 0;
//
//    while(scanf("%d %d %d", &qtd_disp, &qtd_op, &limite_amper) == 3 && qtd_disp) {
//
//        consumo_total = max_consumo = 0;
//
//        for (j = 0; j < qtd_disp; ++j) {
//            scanf("%d", &consumo_atual);
//            disp_consumos[j] = consumo_atual;
//            disp_estados[j] = 0;
//        }
//
//        /*Enquanto a soma da potência não superar o máximo E houver operações*/
//        while(qtd_op--) {
//
//            scanf("%d", &id_disp);
//
//            if (consumo_total < limite_amper) {
//
//                /*Se o dispositivo estiver desligado, some o seu consumo*/
//                if (!disp_estados[id_disp - 1]) {
//                    consumo_total += disp_consumos[id_disp - 1];
//                    disp_estados[id_disp - 1] = 1;
//
//                    if (consumo_total > max_consumo) max_consumo = consumo_total;
//                }
//
//                    /*Senão, ele estava ligado, desligue e subtraia seu consumo*/
//                else {
//                    consumo_total -= disp_consumos[id_disp - 1];
//                    disp_estados[id_disp - 1] = 0;
//                }
//            }
//        }
//
//        ++i;
//
//        printf("Sequence %d\n", i);
//
//        if (consumo_total > limite_amper) printf("Fuse was blown.\n\n");
//
//        else {
//            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", max_consumo);
//        }
//    }
//
//    return 0;
//}