#include <iostream>
#include <vector>
#define MAX_N_PLV   100
#define MAX_T_REG   256
#define MAX_N_ZERO  7

using namespace std;

string palavras[MAX_N_PLV];
string saidas_str[MAX_T_REG + MAX_N_ZERO];

void imprimir_seq(int n_plv, string regra, int index_regra) {

    /*Se for o último caractere da regra atual*/
    if (regra.size() == index_regra) {

        /*Para cada índice da regra, imprima a string já armazenada previamente*/
        for (int j = 0; j < regra.size(); j++) cout << saidas_str[j];
        cout << endl;
    }

    /*Se o símbolo for tralha*/
    else if (regra[index_regra] == '#') {

        /*Armazene cada uma das palavras no índice atual da regra*/
        for(int i = 0; i < n_plv; i++) {
            saidas_str[index_regra] = palavras[i];
            imprimir_seq(n_plv, regra, index_regra + 1);
        }
    }

    /*Senão, o símbolo é um zero*/
    else {

        /*Então armazene cada dígito de 0 a 9, sempre intercalando c/ a auto-chamada*/
        for (int j = 0; j < 10; ++j) {
            saidas_str[index_regra] = to_string(j);
            imprimir_seq(n_plv, regra, index_regra + 1);
        }
    }
}

int main() {

    string temp_entrada;
    int n_plv, n_regras;

    /*Enquanto houverem dados a serem lidos*/
    while(cin >> n_plv and n_plv > 0) {

        /*Leia todas palavras*/
        for (int i = 0; i < n_plv; ++i) cin >> palavras[i];

        /*Leia o número de regras*/
        cin >> n_regras;

        /*Leia cada regra, calcule e imprima as possibilidades*/
        for (int i = 0; i < n_regras; ++i) {
            cin >> temp_entrada;
            cout << "--\n";
            imprimir_seq(n_plv, temp_entrada, 0);
        }
    }

    return 0;
}