#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int dist, menor_dist, temp_dist;
    string linha;
    vector<int> r_locals;
    vector<int> d_locals;

    while(cin >> dist && dist) {

        menor_dist = dist;
        cin.ignore();
        cin >> linha;
        d_locals.clear();
        r_locals.clear();

        /*Preencha os vetores c/ a posição atual de cada Drogaria e Restaurante*/
        for(int i = 0; i < linha.size() && menor_dist; i++) {
            if(linha[i] == 'Z') menor_dist = 0;
            else if(linha[i] == 'R') r_locals.push_back(i + 1);
            else if(linha[i] == 'D') d_locals.push_back(i + 1);
        }

        /*Se não encontrou algum Z (Drogaria E Restaurante)*/
        if(menor_dist) {

            for (auto r_dist: r_locals) {

                for (auto d_dist: d_locals) {
                    temp_dist = abs(r_dist - d_dist);

                    if(temp_dist < menor_dist) menor_dist = temp_dist;
                }
            }
        }

        cout << menor_dist << endl;
    }
    return 0;
}