#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc_soma_aprox(vector<int> numeros, int valor_buscado) {

    int menor_diff = abs(numeros[0] + numeros[1] - valor_buscado);
    int diff = 0;
    pair<int, int> par_aprox = make_pair(numeros[1], numeros[0]);

    for (int i = 0; numeros[i] < valor_buscado && i < numeros.size() - 1; ++i) {

        for (int j = i+1; numeros[j] < valor_buscado && j < numeros.size(); ++j) {

            diff = abs(numeros[j] + numeros[i] - valor_buscado);

            if (diff < menor_diff) {
                menor_diff = diff;
                par_aprox = make_pair(numeros[j], numeros[i]);
            }
        }
    }

    return par_aprox.first + par_aprox.second;
}


int main() {

    int tam_entrada, n_query, temp_num, i_teste;
    vector<int> numeros_entrada;

    i_teste = 0;

    while (cin >> tam_entrada && tam_entrada > 0) {

        numeros_entrada.clear();

        /*Enquanto o tamanho da entrada for maior que 0, leia os núm. de entrada*/
        for (int i = 0; i < tam_entrada; ++i) {
            cin >> temp_num;
            numeros_entrada.push_back(temp_num);
        }

        cin >> n_query;
        sort(numeros_entrada.begin(), numeros_entrada.end());

        printf("Case %d:\n", ++i_teste);

        /*Enquanto o núm. de querys for maior que 0, leia os valores de teste*/
        for (int i = 0; i < n_query; ++i) {
            cin >> temp_num;

            printf("Closest sum to %d is %d.\n", temp_num, calc_soma_aprox(numeros_entrada, temp_num));
        }

        tam_entrada = 0;
    }
}