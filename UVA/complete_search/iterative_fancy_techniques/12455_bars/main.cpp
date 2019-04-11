#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {

    int n_testes, comprimento, n_barras, temp_num;
    vector<int> val_barras;

    cin >> n_testes;

    /*Enquanto houver casos de testes*/
    while(n_testes--) {

        /*Leia o comprimento desejado*/
        cin >> comprimento;

        /*Leia a quantidade de barras*/
        cin >> n_barras;

        val_barras.clear();

        /*Inicialize o vetor booleano com zeros.
         *Alocado aqui para ter exatamente o tamanho necessário*/
        vector<u_short> c_possiv;

        c_possiv.reserve(comprimento);
        for (int j = 0; j <= comprimento; ++j) c_possiv.push_back(0);

        /*Leia o comprimento de cada barra*/
        for(int i = 0; i < n_barras; ++i) {
            cin >> temp_num;
            val_barras.push_back(temp_num);
        }

        c_possiv[0] = 1;

        /*Para cada barra com comprimento lido*/
        for(auto x1: val_barras) {

            for(int x2 = comprimento - x1; x2 >= 0; x2--) {

                /*Se há valor p/ x2 e p/ x1, mas não há para x1 + x2, defina;*/
                if(c_possiv[x2] && !c_possiv[x1 + x2]) c_possiv[x1 + x2] = 1;
            }
        }

        if(c_possiv[comprimento]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}