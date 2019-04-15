#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define IVECTOR vector<int>

using namespace std;

map<IVECTOR, bool> saidas;

void imprimir_saida(IVECTOR num_selecionados) {

    for (int i = 0, tam = num_selecionados.size(); i < tam; ++i) {
        if (i + 1 < tam) cout << num_selecionados[i] << "+";
        else cout << num_selecionados[i];
    }
    cout << endl;
}

void calc_ciclo(IVECTOR valores, IVECTOR visitados, int resto, int index_ini) {

    int no;

    /*Se o resto da soma for zero E a combinação for inédita*/
    if (resto == 0) {

        /*Se a combinação não estiver duplicada, armazene-a e a imprima*/
        if(saidas.find(visitados) != saidas.end()) return;
        saidas[visitados] = true;
        imprimir_saida(visitados);
        return;
    }

    else if(resto < 0) return;

    /*Para cada valor dentro da lista de valores possíveis*/
    for (int i = index_ini, tam = valores.size(); i < tam; ++i) {
        no = valores[i];
        visitados.push_back(no);
        calc_ciclo(valores, visitados, resto - no, i+1);
        visitados.erase(visitados.end() - 1);
    }
}

int main() {

    int temp_num, n_entrada, soma;
    IVECTOR entrada;

    /*Enquanto houver dados a serem lidos*/
    while (cin >> soma && soma > 0) {
        cin >> n_entrada;

        /*Leia e armazene a quantidade especificada de inteiros*/
        for (int i = 0; i < n_entrada; ++i) {
            cin >> temp_num;
            entrada.push_back(temp_num);
        }

        /*Imprima a saída*/
        printf("Sums of %d:\n", soma);
        calc_ciclo(entrada, {}, soma, 0);
        if (saidas.empty()) cout << "NONE\n";

        /*Reinicie as variáveis a serem reutilizadas*/
        saidas.clear();
        entrada.clear();
    }

    return 0;
}