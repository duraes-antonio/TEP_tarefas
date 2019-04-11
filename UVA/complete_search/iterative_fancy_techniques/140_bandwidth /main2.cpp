#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>

#define MAP_CHAR_CHAR map<char, vector<char>>

using namespace std;

MAP_CHAR_CHAR tratar_entrada(string entrada) {

    MAP_CHAR_CHAR saida;
    vector<char> temp_viz;
    char ult_chave;
    bool dois_pt = false;

    for (char caract : entrada) {

        if(caract == ':') dois_pt = true;

            /*Se o char. for ';', crie a chave com a lista de vizinhos lidos;*/
        else if(caract == ';') {
            dois_pt = false;
            saida[ult_chave] = temp_viz;
            temp_viz.clear();
        }

            /*Salve a letra antes dos dois pontos*/
        else if(not dois_pt) ult_chave = caract;

            /*Se já leu ':', o caracter atual é um dos nós vizinhos, adicione na lista;
             *O char. chave é vizinho do char atual também*/
        else {
            temp_viz.push_back(caract);

            if(find(saida[caract].begin(), saida[caract].end(), ult_chave) == saida[caract].end()) {
                saida[caract].push_back(ult_chave);

                if(find(saida[ult_chave].begin(), saida[ult_chave].end(), caract) == saida[ult_chave].end()) {
                    saida[ult_chave].push_back(caract);
                }
            }
        }
    }

    return saida;
}

void imprimir_entrada(string entrada) {

    MAP_CHAR_CHAR result = tratar_entrada(entrada);

    for(auto par: result) {
        cout << par.first << ": ";

        for (char i : par.second) {
            cout << i << " ";
        }

        cout << endl;
    }
}

bool in(vector<char> vetor, char buscado) {
    return find(vetor.begin(), vetor.end(), buscado) != vetor.end();
}

void obter_caminhos(MAP_CHAR_CHAR grafo, vector<char> black, char inic, char obj, string caminho, vector<string>* saida) {

    caminho += inic;

    /*Se o nó já estiver na lista de visitados, saia da função*/
    if(in(black, inic)) return;

    /*Adicione o nó na lista de visitados;*/
    black.push_back(inic);

    /*Se encontrou o nó buscado;
     *Adicione o caminho ao conjunto de caminhos possíveis;
     *Reinicie o texto do caminho*/
    if(inic == obj) {
        saida -> push_back(caminho + "\n");
        caminho.clear();
    }

    /*Senão, repita o processo para cada vizinho do nó corrente*/
    else for(char &i : grafo[inic]) {
        obter_caminhos(grafo, black, i, obj, caminho, saida);
    }
}

int main() {

    int max_custo;
    string entrada;
    vector<string> saida;
    vector<char> chars_in;
    MAP_CHAR_CHAR mapa;

    /*Leia a entrada enquanto ela for diferente de '#'*/
    while(cin >> entrada and entrada != "#") {
        mapa = tratar_entrada(entrada);

        for(auto par: mapa) chars_in.push_back(par.first);

        /*Para cada nó do map*/
        for (int i = 0; i < mapa.size(); ++i) {

            /*Obtenha todos possíveis caminhos até o nó adjacente*/
            for (int j = i+1; j < mapa.size(); ++j) {

                /*Obtenha o conjunto com os caminhos possíveis*/
                obter_caminhos(mapa, {}, chars_in[i], chars_in[j], "", &saida);

                for(const string &str: saida) cout << str;
            }
        }
    };
}