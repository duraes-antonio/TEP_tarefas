#include <iostream>
#include <cmath>

using namespace std;

bool num_primo(int num) {

    bool primo = true;
    int result = 2;

    if(num == 2 || num == 3 || num == 5) return true;

    if (num % 2 == 0) return false;

    double raiz = sqrt(num);

    while(primo && result < raiz) {
        if (num % result == 0) primo = false;
        result++;
    }

    return primo;
}

int main() {

    int valor, min_den;

    while (cin >> valor && valor > 0) {

        min_den = valor + 1;

        while(min_den <= valor*2) {

            if ((min_den * valor) % (min_den - valor) == 0) {
                printf("1/%d + 1/%d\n", (min_den * valor) / (min_den - valor), min_den);
            }

            min_den++;
        }

        cout << endl;
        valor = 0;
    }

    return 0;
}