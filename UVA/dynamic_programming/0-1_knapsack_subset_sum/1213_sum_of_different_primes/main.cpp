#include <iostream>
#include <vector>
#include <cmath>

#define MAX_NUM 1121

using namespace std;

int primos[MAX_NUM];
vector<int> primos_somente;

bool primo(int num) {

    if(num < 2) return false;
    if(num % 2 == 0 && num != 2) return false;

    double raiz = sqrt(num);

    for (int i = 3; i <= raiz; i += 2) {
        if(num % i == 0) return false;
    }

    return true;
}

void gerar_primos() {

    for (int i = 0; i <= MAX_NUM; ++i) {
        primos[i] = primo(i);

        if(primos[i]) primos_somente.push_back(i);
    }
}

int main() {

    int num_input, n_formas;
    gerar_primos();

    while(cin >> num_input && num_input > 0) {

        cin >> n_formas;

        for (int i = 0; i < 14; ++i) {
            
        }
    }

    return 0;
}