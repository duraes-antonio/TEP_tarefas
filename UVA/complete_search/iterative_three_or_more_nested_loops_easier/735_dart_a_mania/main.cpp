#include <iostream>
#include <vector>
#include <algorithm>

#define MIN_VAL_D 0
#define MAX_VAL_D 20
#define MAX_MULT 3
#define MAX_DARDO_MULT (MAX_MULT*MAX_VAL_D)
#define N_DARDOS 3

#define MSG_COMB "NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n"
#define MSG_PERM "NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n"
#define MSG_END "END OF OUTPUT\n"
#define MSG_OVERFLOW "THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n"

/*Valor máximo que pode ser obtido com 3 dardos*/
#define MAX_VAL (N_DARDOS * MAX_MULT * MAX_VAL_D)

/*Número de asteríscos*/
#define N_ASTER 70

using namespace std;

bool in(vector<vector<int>> lista_vetores, vector<int> vet_buscado) {
    sort(vet_buscado.begin(), vet_buscado.end());

    for(auto vetor: lista_vetores) {
        sort(vetor.begin(), vetor.end());
        if (vetor == vet_buscado) return true;
    }

    return false;
}

int main()
{
    int temp_num, n_comb, n_permut;
    vector<int> val_possiv;
    vector<vector<int>> possibilidades;
    vector<int> vet_temp;

    /*Adicione todas possibilidades em um conjunto;
     *Trabalhar sem ter a lista de possibilidades geraria vários
      laços triplos*/

    /*Adicione os números de 0 a 19*/
    for(int i = 0; i < MAX_VAL_D; i++) val_possiv.push_back(i);

    /*Adicione os números de 20 a 40 (pulando de 2 em 2)*/
    for(int i = MAX_VAL_D / 2; i <= MAX_VAL_D; i++) val_possiv.push_back(i*2);

    /*Adicione os números de 21 a 60 (pulando de 3 em 3)*/
    for(int i = 7; i <= MAX_VAL_D; i++) {
        if (i < 13 && i % 2 == 0) continue;
        val_possiv.push_back(i*3);
    }

    val_possiv.push_back(50);
    sort(val_possiv.begin(), val_possiv.end());

    int tam = val_possiv.size();

    /*Enquanto houver entradas*/ 
    while(scanf("%d", &temp_num) == 1 && temp_num > 0){
        
        n_comb = n_permut = 0;

        if (temp_num <= MAX_VAL) {

            for (int i = 0; i < tam; i++) {
                for (int j = i; j < tam; j++) {
                    for (int k = j; k < tam; k++) {

                        if ((val_possiv[i] + val_possiv[j] + val_possiv[k]) == temp_num) {
                            vet_temp = {i, j, k};

                            if (!in(possibilidades, vet_temp)) {
                                n_comb++;

                                if (i != j && j != k) n_permut += 6;
                                else if (i != j || j != k) n_permut += 3;
                                else n_permut++;

                                possibilidades.push_back(vet_temp);
                            }
                        }
                    }
                }
            }
        }

        if (n_comb) {
            printf(MSG_COMB, temp_num, n_comb);
            printf(MSG_PERM, temp_num, n_permut);
        }

        else printf(MSG_OVERFLOW, temp_num);

        for(size_t i = 0; i < N_ASTER; i++) cout << '*';
        cout << endl;

        possibilidades.clear();
    }
    
    cout << MSG_END;


    return 0;
}