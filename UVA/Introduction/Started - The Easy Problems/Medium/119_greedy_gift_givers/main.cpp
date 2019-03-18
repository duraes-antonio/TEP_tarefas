#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

    int qtd_pessoas, val_doado, qtd_presentes;
    string nome_pessoa;
    map<string, int> map_doadores;
    vector<string> nomes_ordem;

    while(cin >> qtd_pessoas) {

        if (nomes_ordem.size()) {
            nomes_ordem.clear();
            map_doadores.clear();
            cout << endl;
        }

        for(int i = 0; i < qtd_pessoas; i++) {
            cin >> nome_pessoa;
            map_doadores[nome_pessoa] = 0;
            nomes_ordem.push_back(nome_pessoa);
        }

        for (int j = 0; j < qtd_pessoas; ++j) {
            cin >> nome_pessoa >> val_doado >> qtd_presentes;

            if (qtd_presentes) {
                map_doadores[nome_pessoa] += (val_doado % qtd_presentes - val_doado);

                for (int i = 0; i < qtd_presentes; ++i) {
                    cin >> nome_pessoa;
                    map_doadores[nome_pessoa] += val_doado / qtd_presentes;
                }
            }
        }

        for(int i = 0; i < nomes_ordem.size(); i++) {
            cout << nomes_ordem[i] << " " << map_doadores[nomes_ordem[i]] << endl;
        }
    }

    return 0;
}