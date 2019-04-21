#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define MSG_NO_PIZZA "No pizza can satisfy these requests.\n"
#define Pessoa vector<pair<char, bool>>

using namespace std;

map<char, bool> g_saidas;
vector<Pessoa> g_pessoas;
bool encontrado = false;

void add_pessoa(string linha) {

    Pessoa pessoa;

    /*Para cada letra, da primeira até a última;
     *i = 1 é o índice da primeira letra. O incremento de 2 é para saltar p/
     *próxima letra (ignorar o símbolo de '+' e '-')*/
    for(int i = 1, tam = linha.size(); i < tam; i += 2) {
        pessoa.emplace_back(linha[i], linha [i - 1] == '+');
    }
    g_pessoas.push_back(pessoa);
}

void ordernar_pessoas(vector<Pessoa> pessoas) {
    Pessoa temp;

    for (int i = 0; i < pessoas.size()-1; ++i) {
        for (int j = 0; j < pessoas.size() - i - 1; ++j) {
            if (pessoas[j].size() > pessoas[j + 1].size()) {
                temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }
}

void imprimir_coberturas() {
    cout << "Toppings: ";
    for(auto cobert: g_saidas) cout << cobert.first;
    cout << endl;
}

bool processar(int i_pessoa) {

    bool cobert_presente;

    if (i_pessoa == g_pessoas.size()) {
        encontrado = true;
        return true;
    }

    /*Para cada restrição da pessoa de índice 'i' da lista de pessoas*/
    for (auto &restr : g_pessoas[i_pessoa]) {
        cobert_presente = g_saidas.find(restr.first) != g_saidas.end();

        /*Se a cobertura estiver presente no resultado E a restrição atual
         * não for atendida, passe para próxima restrição*/
        if(cobert_presente && g_saidas[restr.first] != restr.second) continue;

        /*Senão, se a restrição não estiver na lista de saídas*/
        if (!cobert_presente) g_saidas[restr.first] = restr.second;

        if(processar(i_pessoa + 1)) return true;
    }

    return false;
}

int main() {

    string linha;

    /*Enquanto houverem linhas de entrada*/
    while(getline(cin, linha) && !linha.empty()) {

        /*Se finalizou um grupo de restrições de pessoas, processe!*/
        if(linha == ".") {
            ordernar_pessoas(g_pessoas);
            processar(0);

            if(not encontrado) cout << MSG_NO_PIZZA;
            else imprimir_coberturas();

            /*Reinicie as variáveis*/
            encontrado = false;
            g_saidas.clear();
            g_pessoas.clear();
        }

        else add_pessoa(linha);
    }

    return 0;
}