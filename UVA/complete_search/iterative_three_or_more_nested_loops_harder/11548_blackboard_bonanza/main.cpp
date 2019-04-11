#include <iostream>
#include <vector>

using namespace std;

int calc_similaridade(string texto_1, string texto_2) {

    int max_cont, temp_cont;

    max_cont = 0;

    for(int i = 0; i < texto_1.length(); i++) {
        temp_cont = 0;

        for(int j = 0; j < texto_2.length(); j++) {
            if ((i + j) >= texto_1.length()) continue;
            if (texto_1[i+j] == texto_2[j]) temp_cont++;
        }

        if (temp_cont > max_cont) max_cont = temp_cont;
    }

    return max_cont;
}

int main() {

    int n_testes, n_palavras, n_max_doces, n_doces;
    string temp_entrada;
    vector<string> palavras;

    cin >> n_testes;

    while(n_testes > 0) {

        cin >> n_palavras;
        n_max_doces = 0;
        palavras.clear();

        /*Leia e adicione todos textos lidos no vetor*/
        for (int i = 0; i < n_palavras; ++i) {
            cin >> temp_entrada;
            palavras.push_back(temp_entrada);
        }

        /*Intercale as os textos*/
        for (int i = 0; i < n_palavras; ++i) {

            for (int j = 0; j < n_palavras; ++j) {

                /*Se os textos forem os mesmos
                 *OU seu tamanho for até o núm. máx. de doces, pule o texto J*/
                if(i == j) continue;
                if(palavras[i].length() <= n_max_doces || palavras[j].length() <= n_max_doces) continue;

                /*Calcule a similaridade do texto A com texto B*/
                n_doces = calc_similaridade(palavras[i], palavras[j]);

                if(n_doces > n_max_doces) n_max_doces = n_doces;
            }
        }

        cout << n_max_doces << endl;
        --n_testes;
    }

    return 0;
}