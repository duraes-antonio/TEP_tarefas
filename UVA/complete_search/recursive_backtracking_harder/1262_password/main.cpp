#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define N_LIN   6
#define N_COL   5

using namespace std;

int g_cont = 0;
bool finalizar = false;
map<char, bool> letras[N_COL];
vector<char> grupo_1[N_LIN];
vector<char> grupo_2[N_LIN];

void ler_entrada() {

    char temp_int;

    for (int i = 0; i < N_LIN; ++i) {
        for (int j = 0; j < N_COL; ++j) {
            cin >> temp_int;
            grupo_1[j].push_back(temp_int);
        }
    }

    for (int i = 0; i < N_LIN; ++i) {
        for (int j = 0; j < N_COL; ++j) {
            cin >> temp_int;
            grupo_2[j].push_back(temp_int);
        }
    }
}

void gerar_password(map<char, bool> letras_aceitas[], int i_dic, int num_pass, const string &temp) {

    /*Se encontrou uma senha com o comprimento correto*/
    if(temp.size() == N_COL) ++g_cont;

    /*Se a senha atual é a N-ésima senha, imprima-a e finalize*/
    if(g_cont == num_pass && !finalizar) {
        cout << temp << endl;
        finalizar = true;
        return;
    }

    /*Se já encontrou a senha ou é o último grupo de letras*/
    if(finalizar || i_dic == N_COL) return;

    else {
        for(auto par: letras_aceitas[i_dic]) {
            gerar_password(letras_aceitas, i_dic+1, num_pass, temp + par.first);
        }
    }
}

int main() {

    int n_testes, num_senha, max_possib;
    string linha;

    cin >> n_testes;

    while(n_testes--) {
        cin >> num_senha;

        ler_entrada();

        /*Para cada coluna das primeiras linhas lidas*/
        for(int i = 0, tam = N_LIN; i < tam; ++i) {

            for(char letra: grupo_1[i]) {

                /*Se o char lido aparecer no segundo grupo de linhas lidas*/
                if(find(grupo_2[i].begin(), grupo_2[i].end(), letra) != grupo_2[i].end()) {
                    letras[i][letra] = true;
                }
            }
        }

        /*Verifique se é possível gerar a N-ésima senha*/
        max_possib = 1;
        for(auto &dic : letras) max_possib *= dic.size();

        if(num_senha <= max_possib) gerar_password(letras, 0, num_senha, "");
        else cout << "NO\n";

        /*Reinicie as variáveis*/
        for(auto &dic: letras) dic.clear();
        for(auto &vetor: grupo_1) vetor.clear();
        for(auto &vetor: grupo_2) vetor.clear();
        g_cont = 0;
        finalizar = false;
    }

    return 0;
}