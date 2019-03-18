#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int somar_digitos(int valor) {

    int acumulador, ult_digit;
    double val_div;
    int val_int;

    /*Retorne o próprio valor, se houver apenas 1 digito*/
    if (valor < 10) return valor;

    acumulador = 0;

    /*Enquanto houver digítos à somar*/
    while (valor > 0) {
        acumulador += valor % 10;
        valor = valor / 10;
    }

    return somar_digitos(acumulador);
}

int main() {

    int num_input, result;

    cin >> num_input;

    /*Enquanto houver casos p/ testar*/
    while(num_input > 0) {
        result = somar_digitos(num_input);
        
        cout << result << '\n';
        
        cin >> num_input;
    }

    return 0;
}