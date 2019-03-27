#include <iostream>

using namespace std;

int main() {

    int qtd_testes, qtd_blocos, y_nort, y_sul, tam_anterior;
    bool falha;

    /*Leia a quantidade de testes;*/
    cin >> qtd_testes;

    /*Enquanto houver casos p/ testar*/
    while(qtd_testes--) {

        /*Leia a quantidade de blocos (par c/ y-norte e y-sul)*/
        cin >> qtd_blocos;

        falha = false;

        /*Leia: y-norte e y-sul*/
        cin >> y_nort >> y_sul;

        tam_anterior =  y_nort - y_sul;

        /*Enquanto houver blocos a serem lidos*/
        while(--qtd_blocos) {

            cin >> y_nort >> y_sul;

            /*Se o bloco anterior possuir tamanho diferente do anterior
             *não é possível fechar todos buracos, finalize este caso de teste*/
            if ((y_nort - y_sul) != tam_anterior) {
                falha = true;
            }
        }

        (falha)? cout << "no\n" : cout << "yes\n";

        if (qtd_testes) cout << '\n';
    }

    return 0;
}