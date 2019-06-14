#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define MAX_NUM 1121
#define MAX_N   15

using namespace std;

vector<int> g_primos_somente;
int g_num_n[MAX_NUM][MAX_N];

/*Verifica se o inteiro de entrada é um número primo*/
bool primo(int num) {

    if (num < 2) return false;
    if (num % 2 == 0 && num != 2) return false;

    double raiz = sqrt(num);

    for (int i = 3; i <= raiz; i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

/*Preenche o vetor global com a quant. suficiente de primos p/ resolver o problema */
void gerar_primos() {

    for (int i = 0; i <= MAX_NUM; ++i) {

        if (primo(i)) g_primos_somente.push_back(i);
    }
}

void gerar_resposta() {

    /*Inicialize toda as células da matriz com 0*/
    memset(g_num_n, 0, MAX_NUM*MAX_N);

    /*Caso base (CB): importante, pois ao subtrair um primo de si próprio, a
     * o número de combinações dependerá do resultado do caso inicial*/
    g_num_n[0][0] = 1;

    /*Para cada número primo no vetor que contém apenas primos*/
    for (int primo: g_primos_somente) {

        /*Para cada número entre máximo permitido e o primo atual*/
        for (int num = MAX_NUM-1; num > 0; --num) {

            if(num < primo) break;

            for (int n = 1; n < MAX_N; ++n) {
                g_num_n[num][n] += g_num_n[num - primo][n-1];
            }
        }
    }
}

int main() {

    int num_input, n_primos;

    gerar_primos();
    gerar_resposta();

    while (cin >> num_input) {

        cin >> n_primos;
        if (num_input < 1 && n_primos < 1) break;

        cout << (g_num_n[num_input])[n_primos] << endl;
    }

    return 0;
}