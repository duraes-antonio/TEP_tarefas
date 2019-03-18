#include <iostream>

using namespace std;

int main() {

    string str_entrada;
    int tam_atual, qtd_min;

    while(cin >> str_entrada && str_entrada != "END") {

        /*Armazene o tamanho atual da entrada*/
        tam_atual = (int) str_entrada.size();

        /*Sabe-se que será necessário ao menos 1 dígito*/
        qtd_min = 0;

        /*Condição para evitar laço sem fim.
         *O menor tamanho será 1, e "1".size() sempre será 1*/
        while(str_entrada != "1") {

            /*A nova string será o TAMANHO da string atual*/
            str_entrada = to_string(tam_atual);

            /*O novo tamanho será a qtd. de char da nova string*/
            tam_atual = (int) str_entrada.size();

            ++qtd_min;
        }

        cout << ++qtd_min << endl;
    }

    return 0;
}