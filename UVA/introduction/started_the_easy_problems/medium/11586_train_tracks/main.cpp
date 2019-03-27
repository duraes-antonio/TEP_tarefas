#include <iostream>

using namespace std;

int main() {

    int qtd_pecas, qtd_macho, qtd_femea;
    string linha;

    while(cin >> qtd_pecas) {

        cin.ignore();

        while(qtd_pecas--) {

            /*Reinicie as variáveis que armazenam o total de peças machos e femêas*/
            qtd_femea = qtd_macho = 0;
            getline(cin, linha);

            /*Para cada caracter da linha, verifique se é 'F' ou 'M'*/
            for(auto letra: linha) {
                if (letra == 'M') qtd_macho++;
                else if (letra == 'F') qtd_femea++;
            }

            /*Se o núm. de peças for maior que 1
             *E a qtd. de extremidades machos foi igual de fêmeas*/
            (qtd_femea > 1 && qtd_femea == qtd_macho) ? cout << "LOOP\n" : cout << "NO LOOP\n";
        }
    }

    return 0;
}