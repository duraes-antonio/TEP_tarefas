#include <iostream>

#define MAX_TAM     100
#define MAX_V_BYTE  255
#define HEX_LET     "ABCDEF"

using namespace std;

string num_to_hex(short num_max_255) {

    string saida;

    if(num_max_255 < 10) saida = "0" + to_string(num_max_255);

    else {
        int resto = num_max_255 % 16;
        int div_int = num_max_255 / 16;

        if(div_int < 10) saida = to_string(div_int);
        else saida = HEX_LET[div_int % 10];

        if(resto < 10) saida += to_string(resto);
        else saida += HEX_LET[resto % 10];
    }

    return saida;
}

int main() {

    short bytes[MAX_TAM], qtd_testes, index, temp_val;
    short resto, div_int, caso_index;
    string entrada, hex_saida[MAX_TAM];

    cin >> qtd_testes;
    caso_index = 0;

    while(qtd_testes--) {

        cin >> entrada;

        /*Reinicie o vetor de bytes, o iterador da entrada e vetor de saída*/
        for(short &byte : bytes) byte = 0;
        hex_saida->clear();
        index = 0;

        /*Para cada operação*/
        for (char op : entrada) {
            temp_val = bytes[index];

            /*Se o valor do byte for o 255, o incremento deve zerá-lo.
             *Se o valor for 0, o decremento deve voltá-lo para 255.
             *Aplique o mesmo mecanismo para o índice, porém de 0 a 99*/

            if(op == '+') bytes[index] = temp_val == MAX_V_BYTE ? 0 : ++temp_val;
            else if(op == '-') bytes[index] = temp_val ? --temp_val : MAX_V_BYTE;

            else if(op == '<') index = index ? --index : (MAX_TAM - 1);
            else if(op == '>') index = ++index == MAX_TAM ? 0 : index;
        }

        printf("Case %d:", ++caso_index);

        for(int i = 0; i < MAX_TAM; i++) cout << " " << num_to_hex(bytes[i]);

        cout << endl;
    }

    return 0;
}