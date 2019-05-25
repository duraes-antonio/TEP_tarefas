#include <iostream>

using namespace std;

int main() {

    int qtd_pessoas, cash_max, qtd_hoteis, qtd_semanas;
    int val_hotel, qtd_quartos, custo_total, i;

    while(cin >> qtd_pessoas >> cash_max >> qtd_hoteis >> qtd_semanas) {

        /*Apenas hóteis c/ valor ATÉ minha renda me interessam*/
        custo_total = cash_max + 1;

        /*Enquanto houver hotéis a serem lidos*/
        while(qtd_hoteis--) {
            cin >> val_hotel;

            i = qtd_semanas;

            /*Enquanto houver a quatidade de quartos por semana a ser lida*/
            while(i--) {
                cin >> qtd_quartos;

                if (qtd_pessoas <= qtd_quartos && (val_hotel * qtd_pessoas) < custo_total) {
                    custo_total = val_hotel * qtd_pessoas;
                }
            }
        }

        (custo_total < cash_max) ? cout << custo_total << endl : cout << "stay home" << endl;
    }

    return 0;
}