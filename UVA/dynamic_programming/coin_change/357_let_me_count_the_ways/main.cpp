#include <iostream>
#include <vector>
#include <cstring>

#define MAX_VAL     30001
#define MSG_MULT    "There are %lld ways to produce %d cents change.\n"
#define MSG_ONE     "There is only 1 way to produce %d cents change.\n"

using namespace std;

unsigned long long g_cents_possib[MAX_VAL];
vector<int> moedas = {1, 5, 10, 25, 50};

void calc_possibilidades() {

    memset(g_cents_possib, 0, MAX_VAL* sizeof(unsigned long long));
    g_cents_possib[0] = 1;

    /*Abordagem: Bottom-UP*/
    for (int moeda: moedas) {

        /*Ignore valores menores que a moeda atual (pois a subtração dará valor
         * menor que o menor valor válido)*/
        for (int valor = moeda; valor < MAX_VAL; ++valor) {
            g_cents_possib[valor] += g_cents_possib[valor - moeda];
        }
    }
}

int main() {

    int cents;
    calc_possibilidades();

    while(cin >> cents) {

        if(g_cents_possib[cents] == 1){
            printf(MSG_ONE, cents);
        }

        else {
            printf(MSG_MULT, g_cents_possib[cents], cents);
        }
    }

    return 0;
}