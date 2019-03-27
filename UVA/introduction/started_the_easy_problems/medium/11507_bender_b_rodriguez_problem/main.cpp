#include <iostream>
#include <string>

using namespace std;

int main() {

    int cumprimento;
    string opcao, result;
    char sinal_invert;

    while(cin >> cumprimento && cumprimento) {

        result = "+x";
        --cumprimento;

        for (int i = 0; i < cumprimento; i++) {
            cin >> opcao;

            if (result == "No" && opcao != "No") result = opcao;

            /*Se o eixo atual for igual ao eixo anterior*/
            else if (opcao != "No" && opcao[1] == result[1]) {
                result[1] = 'x';
                result[0] = (opcao[0] != result[0]) ? '+' : '-';
            }

            else if (result[1] == 'x' && opcao != "No") {
                sinal_invert = (opcao[0] == '+') ? '-' : '+';
                result[1] = opcao[1];
                result[0] = (result[0] == '+') ? opcao[0] : sinal_invert;
            }
        }

        cout << result << endl;
    }

    return 0;
}