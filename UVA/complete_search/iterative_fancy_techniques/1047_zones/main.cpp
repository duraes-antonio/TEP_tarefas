#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

    int n_torres, n_possiveis, temp_n_atend, n_comum;
    int n_torres_comum, torre_id, custo;
    vector<int> n_atendidos;
    vector<int> v_temp;
    map<pair<int, int>, int> par_desc;
    map<pair<int, int>, int> par_torre;
    vector<pair<int, int>> v_pares;

    while(cin >> n_torres && n_torres > 0) {
        cin >> n_possiveis;

        /*Leia o número de clientes que cada torre suporta*/
        for (int i = 0; i < n_torres; ++i) {
            cin >> temp_n_atend;
            n_atendidos.push_back(temp_n_atend);
        }


        cin >> n_comum;

        for (int i = 0; i < n_comum; ++i) {

            cin >> n_torres_comum;
            v_temp.clear();

            /*Leia o id de cada torre com área em comum*/
            for (int j = 0; j < n_torres_comum; ++j) {
                cin >> torre_id;
                v_temp.push_back(torre_id);
            }

            cin >> custo;

            for (int j = 0; j < v_temp.size(); ++j) {
                for (int k = j + 1; k < v_temp.size(); ++k) {
                    pair<int, int> par1 = make_pair(v_temp[j], v_temp[k]);

                    if(par_desc[par1]) par_desc[par1] += custo;
                    else par_desc[par1] = custo;
                }
            }
        }


        for (int j = 0; j < n_torres; ++j) {
            for (int k = j + 1; k < n_torres; ++k) {
                pair<int, int> par = make_pair(j+1, k+1);
                par_torre[par] = n_atendidos[j] + n_atendidos[k] - par_desc[par];
                v_pares.push_back(par);
            }
        }

        /*Bubble Sort*/
        for (int i = 1; i < v_pares.size(); i++) {

            for (int j = 0; j < v_pares.size() - 1; j++) {

                if (par_torre[v_pares[j]] < par_torre[v_pares[j + 1]]) {
                    pair<int, int> aux = v_pares[j];
                    v_pares[j] = v_pares[j + 1];
                    v_pares[j + 1] = aux;
                }
            }
        }

        vector<int> ja_usados;

        for(int i = 0; i < n_possiveis; i++) {

            if (n_possiveis - i == 1) {
                printf("torre<%d, %d> = %d\n", v_pares[i].first, v_pares[i].second, par_torre[v_pares[i]]);
            }

            else {
                printf("torre<%d, %d> = %d\n", v_pares[i].first, v_pares[i].second, par_torre[v_pares[i]]);
                ja_usados.push_back(v_pares[i].first);
                ja_usados.push_back(v_pares[i].second);
            }
            i++;
        }
    }

    return 0;
}