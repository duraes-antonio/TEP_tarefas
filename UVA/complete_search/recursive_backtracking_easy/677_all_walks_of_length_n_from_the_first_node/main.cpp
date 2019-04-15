#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAP_MATRIZ  map<ushort, vector<ushort>>

using namespace std;

vector<vector<ushort>> saidas;

MAP_MATRIZ ler_matriz(ushort dimensao) {

    ushort temp_num;
    MAP_MATRIZ mapa;

    /*Para cada linha até a dimensão da matriz*/
    for (ushort i = 0; i < dimensao; ++i) {

        /*Para cada valor lido*/
        for (ushort j = 0; j < dimensao; ++j) {
            cin >> temp_num;

            /*Se o valor for 1, crie uma ligação com o nó i e o nó j*/
            if(temp_num) mapa[i+1].push_back(j+1);
        }
    }

    return mapa;
}

void calc_caminho(MAP_MATRIZ mapa, vector<ushort> visitados, ushort no_atual, ushort tam_path) {

    vector<ushort> caminho;

    /*Se o tamanho do caminho for 1*/
    if(!tam_path) {

        /*Para cada nó, se ele foi visitado, adicione-o no caminho*/
        for(ushort visitado: visitados) {
            caminho.push_back(visitado);
        }

        /*Por fim, adicione o nó atual no caminho, e o caminho na saida*/
        caminho.push_back(no_atual);
        saidas.push_back(caminho);
    }

    else {
        /*Marque o nó atual como visitado*/
        visitados.push_back(no_atual);

        /*Para cada filho do nó atual*/
        for(ushort filho: mapa[no_atual]) {

            /*Se o filho foi visitado, ignore-o, senão, chame a função e passe-o*/
            if(find(visitados.begin(), visitados.end(), filho) != visitados.end()) continue;
            calc_caminho(mapa, visitados, filho, tam_path - 1);
        }
    }
}

void imprimir_saida(ushort tam_path) {

    int tam;

    if(saidas.empty()) printf("no walk of length %d\n", tam_path);

    else {
        for (const vector<ushort> &caminho: saidas) {
            tam = caminho.size();
            cout << '(';

            for (int i = 0; i < tam; ++i) {
                cout << caminho[i] << (i + 1 < tam ? "," : ")\n");
            }
        }
    }
}

int main() {

    int n_dimensao, tam_path;
    MAP_MATRIZ mapa_num;

    /*Enquanto houver a dimensão da matriz*/
    while (cin >> n_dimensao) {

        if(n_dimensao == -9999) {
            cin >> n_dimensao;
            cout << endl;
        }

        /*Leia o tamanho do caminho e a matriz*/
        cin >> tam_path;
        mapa_num = ler_matriz(n_dimensao);

        calc_caminho(mapa_num, {}, 1, tam_path);

        imprimir_saida(tam_path);

        /*Reinicie as variáveis a serem reutilizadas*/
        saidas.clear();
    }

    return 0;
}