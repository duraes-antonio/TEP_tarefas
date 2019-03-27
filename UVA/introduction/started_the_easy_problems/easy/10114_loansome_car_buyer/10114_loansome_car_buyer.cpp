#include <iostream>

using namespace std;

int main() {

    /*Primeira linha com os 4 valores*/
    int qtd_parcelas, num_descontos, qtd_mes;
    double val_entrada, total_emprestimo, val_parcela;

    /*Número do mês que ocorre o desconto e porcentagem de desconto*/
    int mes_desc;
    double porct_desc;

    /*Valor do carro E lista com as porcentagens a serem descontadas*/
    double val_carro;
    double descts_porct[101];

    cin >> qtd_parcelas >> val_entrada >> total_emprestimo >> num_descontos;

    while(qtd_parcelas > 0) {

        val_carro = val_entrada + total_emprestimo;
        val_parcela = total_emprestimo / qtd_parcelas;

        /*Leia e enfilere o núm. do mês e a porcentagem de desconto*/
        for (int i = 0; i < num_descontos; i++) {
            cin >> mes_desc >> porct_desc;

            for (int j = mes_desc; j <= qtd_parcelas; j++) {
                descts_porct[j] = porct_desc;
            }
        }

        /*Quantidade final de meses*/
        qtd_mes = 0;

        /*Desconto inicial, logo no mês 0*/
        val_carro = val_carro * (1 - descts_porct[0]);
        
        /*Enquanto o empréstimo devido valer mais que o carro*/
        while (total_emprestimo > val_carro) {
            val_carro = val_carro * (1 - descts_porct[++qtd_mes]);
            total_emprestimo -= val_parcela;
        }

        printf("%d %s\n", qtd_mes, (qtd_mes == 1) ? "month" : "months");

        cin >> qtd_parcelas >> val_entrada >> total_emprestimo >> num_descontos;
    }

    return 0;
}