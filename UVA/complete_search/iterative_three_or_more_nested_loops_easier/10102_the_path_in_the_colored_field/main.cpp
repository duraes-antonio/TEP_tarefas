#include <iostream>
#include <map>
#include <vector>
#include <tuple>

#define PONTO tuple<int, int>

using namespace std;

int calc_manhattan(PONTO pt_ini, PONTO pt_fim) {
    return abs(get<0>(pt_ini)- get<0>(pt_fim)) + abs(get<1>(pt_ini) - get<1>(pt_fim));
}

int main() {

    int m, menor_dist, maior_dist, dist;
    vector<PONTO> colors3_xy;
    vector<PONTO> colors1_xy;
    string temp_valor;

    /*Enquanto houver linhas a serem lidas*/
    while (cin >> m && m > 0) {

        colors3_xy.clear();
        colors1_xy.clear();

        /*Para cada linha até o número M*/
        for (int y = 0; y < m; ++y) {

            /*Leia e converta o valor lido*/
            cin >> temp_valor;

            /*Para cada coluna até o número M*/
            for (int x = 0; x < m; ++x) {

                char num = temp_valor[x];

                if (num == '3') colors3_xy.push_back(make_tuple(x, y));
                else if (num == '1') colors1_xy.push_back(make_tuple(x, y));
            }
        }

        maior_dist = 0;

        /*Para cada ponto da cor 1*/
        for (auto pt_cor1: colors1_xy) {

            menor_dist = 0;

            /*ENCONTRE O PONTO DE COR 3 COM A MENOR DISTÂNCIA ATÉ O PT ATUAL DE COR 1*/

            /*Tente sair de cada ponto de cor 1 e chegar até o de cor 3*/
            for (auto pt_cor3: colors3_xy) {

                /*Calcule a dist. e atualize a menor se a atual for mais curta*/
                dist = calc_manhattan(pt_cor1, pt_cor3);

                if (dist < menor_dist || !menor_dist) menor_dist = dist;
            }

            /*ENCONTRE A MAIOR DISTÂNCIA DENTRE AS MENORES*/
            if (menor_dist > maior_dist || !maior_dist) maior_dist = menor_dist;
        }

        cout << maior_dist << endl;
    }

    return 0;
}