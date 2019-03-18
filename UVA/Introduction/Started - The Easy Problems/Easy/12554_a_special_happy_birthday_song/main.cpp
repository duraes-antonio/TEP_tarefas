#include <iostream>
#include <cstring>

#define MAX_CHAR 100
#define MAX_NOME 100

using namespace std;

int main() {

    int qtd_pessoas, qtd_repet, nao_imprimir_ruja;
    char nomes[MAX_CHAR][MAX_NOME];
    char musica_plvs[][9] = {"Happy", "birthday", "to", "you"};
    char rujia[] = "Rujia";

    cin >> qtd_pessoas;

    /*Leia todos os nomes dos participantes*/
    for (int i = 0; i < qtd_pessoas; i++) cin >> nomes[i];

    /*Calcule quantas vezes a música se repetirá*/
    qtd_repet = qtd_pessoas / 16;

    if (qtd_pessoas % 16 != 0) ++qtd_repet;

    /*Marque quando a palavra 'you' é substituída por 'Rujia'*/
    nao_imprimir_ruja = 11;

    for(int i = 0; i < (qtd_repet * 16); i++, nao_imprimir_ruja--) {

        if (nao_imprimir_ruja) {
            cout << nomes[i % qtd_pessoas] << ": " << musica_plvs[i % 4] << endl;
        }

        else {
            cout << nomes[i % qtd_pessoas] << ": " << rujia << endl;
            nao_imprimir_ruja = 16;
        }
    }

    return 0;
}