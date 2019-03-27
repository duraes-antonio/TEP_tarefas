#include <iostream>

using namespace std;

int main() {

    int qtd_testes, qtd_criancas, velocidades_criatura[10000];
    int veloc, maior_veloc, cont;

    cont = 0;
    cin >> qtd_testes;

    /*Enquanto houver testes a serem realizados*/
    while(qtd_testes--) {

        maior_veloc = 0;
        cin >> qtd_criancas;

        /*Para cada criança, verifique se a veloc. atual é maior do que a máxima
         *registrada.*/
        for(int i = 0; i < qtd_criancas; i++) {
            cin >> veloc;

            if (veloc > maior_veloc) maior_veloc = veloc;
        }

        cout << "Case " << ++cont << ": " << maior_veloc << endl;
    }
}