#include <iostream>

#define CUST_MILE   10
#define T_MILE      30
#define CUST_JUICE  15
#define T_JUICE     60

using namespace std;

int main() {

    int qtd_testes, qtd_duracoes, duracao, custo_mile, custo_juice;

    cin >> qtd_testes;
    int cont = 0;

    while(qtd_testes--) {

        cin >> qtd_duracoes;

        /*Reinicie os acumuladores de custo*/
        custo_juice = custo_mile = 0;

        for(int i = 0; i < qtd_duracoes; i++) {
            cin >> duracao;
            custo_juice += (duracao / T_JUICE + 1)*CUST_JUICE;
            custo_mile += (duracao / T_MILE + 1)*CUST_MILE;
        }

        cout << "Case " << ++cont << ": ";

        if (custo_mile < custo_juice) cout << "Mile " << custo_mile << endl;
        else if (custo_juice < custo_mile) cout << "Juice " << custo_juice << endl;
        else cout << "Mile Juice " << custo_juice << endl;
    }

    return 0;
}