#include <iostream>
#include <cstring>

#define MAX_TAM 101
#define LEFT    "LEFT"
#define RIGHT   "RIGHT"

using namespace std;

int main() {

    int qtd_testes, qtd_acoes, int_acao, pos_atual, acoes[MAX_TAM];
    char str_acao[25];

    cin >> qtd_testes;

    while(qtd_testes--) {

        cin >> qtd_acoes;
        pos_atual = 0;

        for (int i = 0; i < qtd_acoes; ++i) {

            cin >> str_acao;

            if (strcmp(str_acao, LEFT) == 0) {
                --pos_atual;
                acoes[i] = -1;
            }

            else if(strcmp(str_acao, RIGHT) == 0) {
                ++pos_atual;
                acoes[i] = 1;
            }

            else {
                cin >> str_acao;
                cin >> int_acao;
                acoes[i] = acoes[int_acao - 1];
                pos_atual += acoes[i];
            }
        }

        cout << pos_atual << endl;
    }

    return 0;
}