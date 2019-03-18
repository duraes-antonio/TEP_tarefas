#include <iostream>

using namespace std;

int main() {

    int altura, comprimento, qtd_cortes;
    int temp_alt, alt_anterior;

    /*Enquanto a altura for diferente de 0*/
    while(cin >> altura && altura) {

        /*Leia o comprimento do bloco e a altura da primeira coluna*/
        cin >> comprimento;
        cin >> alt_anterior;

        /*Calcule a dif. entre a altura do bloco e a altura da prim. coluna*/
        qtd_cortes = altura - alt_anterior;

        for (int i = 1; i < comprimento; i++) {
            cin >> temp_alt;

            /*Se a altura atual for diferente da anterior*/
            if(alt_anterior > temp_alt) qtd_cortes += alt_anterior - temp_alt;

            alt_anterior = temp_alt;
        }

        cout << qtd_cortes << endl;
    }
    return 0;
}