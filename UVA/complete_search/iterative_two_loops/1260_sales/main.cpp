#include <iostream>
#include <vector>

using namespace std;

int cont_valor_anterior_menor_igual(vector<int> numeros, int index_inicio) {

    int cont = 0;

    for (int i = index_inicio - 1; i >= 0; i--) {
        if (numeros[i] <= numeros[index_inicio]) ++cont;
    }

    return cont;
}

int main() {

    int n_testes, tam_entrada, temp_num, cont_tam_b;
    vector<int> numeros_entrada;

    cin >> n_testes;

    while (n_testes > 0) {

        numeros_entrada.clear();

        cin >> tam_entrada;
        cont_tam_b = 0;

        for (int i = 0; i < tam_entrada; ++i) {
            cin >> temp_num;
            numeros_entrada.push_back(temp_num);
            cont_tam_b += cont_valor_anterior_menor_igual(numeros_entrada, i);
        }

        cout << cont_tam_b << endl;

        --n_testes;
    }
}