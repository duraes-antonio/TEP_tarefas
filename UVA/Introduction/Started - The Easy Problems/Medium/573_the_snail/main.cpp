#include <iostream>

using namespace std;

int main() {

    int qtd_dias, pes_objetivo, pes_noite, taxa_fadiga;
    double pes_total, pes_dia, pes_fadiga;
    cin >> pes_objetivo >> pes_dia >> pes_noite >> taxa_fadiga;

    /*Enquanto houver altura p/ o caracol escalar*/
    while(pes_objetivo) {

        /*Converta a taxa de fadiga em pés*/
        pes_fadiga = pes_dia * (taxa_fadiga/100.00);

        /*Reinicie as variáveis reusadas*/
        pes_total = qtd_dias = 0;

        /*Enquanto o caracol não subir o poço*/
        while(pes_total >= 0) {
            pes_total += pes_dia > 0 ? pes_dia : 0;
            qtd_dias++;

            if(pes_total <= pes_objetivo) {
                pes_total -= pes_noite;
                pes_dia -= pes_fadiga;
            }

            else break;
        }

        printf("%s on day %d\n", (pes_total > 0) ? "success" : "failure", qtd_dias);

        cin >> pes_objetivo >> pes_dia >> pes_noite >> taxa_fadiga;
    }

    return 0;
}