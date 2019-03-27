#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int somar_ate_um_dig(int numero) {

    int result = 0;

    if (numero < 10) return numero;

    while(numero > 0) {
        result += round(((double) numero / 10 - numero / 10) * 10);
        numero /= 10;
    }

    return somar_ate_um_dig((int) result);
}

int obter_soma_nome(map<char, int> letra_valor, string nome) {

    int result = 0;
    for(auto letra: nome) result += letra_valor[letra];
    return result;
}

int main() {

    int soma_1, soma_2, val;
    string nome1, nome2;
    double result;
    map<char, int> map_letra_val;

    val = 0;

    /*Crie a estrutura contendo cada letra e seu peso numérico*/
    for(auto letra: "abcdefghijklmnopqrstuvwxyz") {
        ++val;
        map_letra_val[letra] = val;
        map_letra_val[toupper(letra)] = val;
    }

    /*Enquanto houver um nome a ser lido (Não for fim de arquivo)*/
    while (getline(cin, nome1)) {
        getline(cin, nome2);
        soma_1 = somar_ate_um_dig(obter_soma_nome(map_letra_val, nome1));
        soma_2 = somar_ate_um_dig(obter_soma_nome(map_letra_val, nome2));

        if (soma_1 > soma_2) result = soma_2 / (double) soma_1;
        else result = soma_1 / (double) soma_2;

        printf("%.2lf %%\n", result*100);
    }

    return 0;
}