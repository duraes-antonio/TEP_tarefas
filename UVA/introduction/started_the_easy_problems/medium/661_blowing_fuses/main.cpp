#include <iostream>
#include <vector>

using namespace std;

int main() {

    int qtd_disp, qtd_op, limite_amper;
    int consumo_atual, id_disp, consumo_total, max_consumo, qtd_testes;

    vector<int> disp_consumos;
    vector<bool> disp_estados;

    qtd_testes = 0;

    while(cin >> qtd_disp >> qtd_op >> limite_amper && qtd_disp) {

        consumo_total = max_consumo = 0;
        disp_consumos.clear();
        disp_estados.clear();

        while(qtd_disp--) {
            cin >> consumo_atual;
            disp_consumos.push_back(consumo_atual);
            disp_estados.push_back(false);
        }

        /*Enquanto a soma da potência não superar o máximo E houver operações*/
        while(consumo_total <= limite_amper && qtd_op--) {

            cin >> id_disp;

            /*Se o dispositivo estiver desligado, some o seu consumo*/
            if (!disp_estados[id_disp - 1]) {
                consumo_total += disp_consumos[id_disp - 1];

                if (consumo_total > max_consumo) max_consumo = consumo_total;
            }

            /*Senão, ele estava ligado, desligue e subtraia seu consumo*/
            else consumo_total -= disp_consumos[id_disp - 1];

            /*Inverta seu estado, ligado p/ desligado (vice-versa)*/
            disp_estados[id_disp - 1] = !disp_estados[id_disp - 1];
        }

        /*Se o fusível queimou antes de ler todos casos, termine a leitura*/
        for (int j = 0; j < qtd_op; ++j) cin >> id_disp;

        ++qtd_testes;

        cout << "Sequence " << qtd_testes << endl;

        if (consumo_total > limite_amper) cout << "Fuse was blown.\n\n";

        else {
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", max_consumo);
        }
    }

    return 0;
}