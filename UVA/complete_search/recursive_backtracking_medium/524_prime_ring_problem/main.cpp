#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX_N 16
#define UVECTOR vector<ushort>

using namespace std;

bool primos[MAX_N*2];
vector<vector<ushort>> saidas;

bool primo_valido(ushort numero) {

    /*Se o número for um dos 3 primeiros primos*/
    if (numero == 1 || numero == 2 || numero == 3) return true;

    /*Senão, se for um número par e diferente de 2, ele não é primo*/
    else if(numero % 2 == 0) return false;

    int raiz = (int) sqrt(numero) + 1;

    for (int div = 3; div < raiz; div += 2) {
        if (numero % div == 0) return false;
    }

    return true;
}

void calcular_primos() {
    for (ushort i = 1; i <= MAX_N*2; ++i) primos[i] = primo_valido(i);
}

void calc_ciclo(UVECTOR valores, UVECTOR usados, ushort num_atual, ushort tam_ciclo) {

    usados.push_back(num_atual);

    /*Se for o último número para completar o ciclo
     * E sua soma com o primeiro número for primo, o ciclo é uma saída aceita*/
    if(tam_ciclo == 1 && primos[usados[0] + num_atual]) {
        const vector<ushort> &temp = usados;
        saidas.push_back(temp);
    }

    for(ushort prox: valores) {
        /*Se o número próximo número já foi investigado, ignore-o*/
        if(find(usados.begin(), usados.end(), prox) != usados.end()) continue;

        /*Se a soma do próximo número com o atual não for primo, ignore-o*/
        else if(!primos[prox + num_atual]) continue;
        else calc_ciclo(valores, usados, prox, tam_ciclo - 1);
    }

}

void imprimir_saida() {

    for(int i = 0, tam = saidas.size(); i < tam; ++i) {

        for (int j = 0, tam_v = saidas[i].size(); j < tam_v; ++j) {
            if (j + 1 < tam_v) cout << saidas[i][j] << " ";
            else cout << saidas[i][j];
        }

        cout << endl;
    }
}

int main() {

    ushort n;
    ushort cont = 0;
    UVECTOR numeros;
    calcular_primos();

    while(cin >> n) {
        for (int i = 1; i <= n; ++i) numeros.push_back(i);

        calc_ciclo(numeros, {}, 1, n);

        if(cont) cout << endl;
        printf("Case %d:\n", ++cont);
        imprimir_saida();

        saidas.clear();
        numeros.clear();
    }

    return 0;
}