#include <iostream>
#include <map>

using namespace std;

int main() {

    int qtd_bancos, qtd_parcelas, temp_quantia, b_credor, b_devedor;
    int pagamento_possivel;
    int bancos_creds[20];

    /*Leia a qtd de bancos e de pagamentos*/
    cin >> qtd_bancos >> qtd_parcelas;

    /*Enquanto houver bancos a serem processados*/
    while(qtd_bancos) {

        pagamento_possivel = 1;

        /*Leia e associe cada quantia a seu respectivo banco*/
        for (int i = 0; i < qtd_bancos; i++) {
            cin >> temp_quantia;
            bancos_creds[i] = temp_quantia;
        }

        /*Enquanto houver parcelas, subtraia do devedor e acrescente ao credor*/
        while (qtd_parcelas--) {
            cin >> b_devedor >> b_credor >> temp_quantia;
            bancos_creds[b_devedor - 1] -= temp_quantia;
            bancos_creds[b_credor - 1] += temp_quantia;
        }

        /*Se após todas transações, algum banco estiver c/ saldo negativo,
         *marque que NÃO é possível ter a liquidez de TODOS os bancos*/
        for(int i = 0; i < qtd_bancos && pagamento_possivel; i++) {

            if (bancos_creds[i] < 0) pagamento_possivel = 0;
        }

        (pagamento_possivel) ? cout << "S\n" : cout << "N\n";

        cin >> qtd_bancos >> qtd_parcelas;
    }

    return 0;
}