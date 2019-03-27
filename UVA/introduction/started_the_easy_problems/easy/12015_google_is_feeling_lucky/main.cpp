#include <iostream>
#include <map>
#define  MAX_TAM 10
using namespace std;

int main() {

    int qtd_testes, peso, maior_peso, cont_case;
    string site;
    pair<string, int> sites_pesos[MAX_TAM];

    cin >> qtd_testes;
    cont_case = 0;

    /*Enquanto houver testes a serem feitos*/
    while(qtd_testes--) {

        /*Guarde o maior peso p/ priorizar a busca posteriormente*/
        maior_peso = 0;

        /*P/ cada par (site, peso), leia o site, peso e determine se o peso
         *atual é maior do que o anterior*/
        for (auto site_peso : sites_pesos) {
            cin >> site >> peso;
            site_peso.first = site;
            site_peso.second = peso;

            if (peso > maior_peso) maior_peso = peso;
        }

        cout << "Case #" << ++cont_case << ":" << endl;

        /*Busque e imprima somente os sites que possuem peso igual ao peso máx.*/
        for (auto site_peso : sites_pesos) {
            if (site_peso.second == maior_peso) cout << (site_peso.first) << endl;
        }
    }

    return 0;
}