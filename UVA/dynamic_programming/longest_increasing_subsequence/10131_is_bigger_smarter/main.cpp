#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*Problema: 101131*/

struct Elefante {
    int peso;
    int qi;
    int ordem;
};

map<int, Elefante> g_qi_elef;
vector<int> g_ordenacao_por_qi;
int g_indice = 0;

/*Compara dois elefantes com base em seu QI*/
bool comparar(Elefante elefante_1, Elefante elefante_2) {
    return elefante_1.qi > elefante_2.qi;
}

void lis(const vector<Elefante> elefantes) {

    int peso_elef_ant = 0;
    int tam_vetor = elefantes.size();
    Elefante elef_inic;

    while(g_indice < tam_vetor) {

        /*Enquanto o peso do i-ésimo elefante não for superior ao do anterior*/
        while(elefantes[g_indice].peso <= peso_elef_ant && g_indice < tam_vetor) ++g_indice;

        if(g_indice == tam_vetor) break;

        elef_inic = elefantes[g_indice];

        /*Enquanto o QI do i-ésimo elefante for igual do elefante atual*/
        while(elefantes[g_indice].qi == elef_inic.qi) {

            /*Verifique se o peso do i-ésimo é inferior ao do atual
             * E superior ao do elefante anterior (de QI superior)*/
            if(elefantes[g_indice].peso < elef_inic.peso && elefantes[g_indice].peso > peso_elef_ant) {
                elef_inic = elefantes[g_indice];
            }

            ++g_indice;
        }

        if(elef_inic.peso > peso_elef_ant) {
            g_qi_elef.insert(make_pair(elef_inic.qi, elef_inic));
            g_ordenacao_por_qi.push_back(elef_inic.qi);
        }

        peso_elef_ant = elef_inic.peso;
    }
}

int main() {

    vector<Elefante> elefantes;
    vector<int> subseq;
    int ordem;
    Elefante temp_elef = Elefante();

    ordem = 0;

    /*Enquanto houver dados a serem lidos*/
    while (scanf("%d %d", &temp_elef.peso, &temp_elef.qi) == 2) {
        temp_elef.ordem = ++ordem;
        elefantes.push_back(temp_elef);
    }

    sort(elefantes.begin(), elefantes.end(), comparar);
    lis(elefantes);

    /*Imprima a quantidade de elefantes encontradas e a ordem da cada elefante*/
    cout << g_qi_elef.size() << endl;
    for (int qi: g_ordenacao_por_qi) cout << g_qi_elef[qi].ordem << endl;

    return 0;
}