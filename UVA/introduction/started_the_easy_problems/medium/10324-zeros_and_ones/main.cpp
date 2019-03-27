#include <iostream>
#include <cstring>

using namespace std;

void swap_num(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main() {

    int qtd_testes, qtd_casos, index_min, index_max;
    string entrada;
    char ult_char;
    bool igual;

    qtd_testes = 0;

    while(cin >> entrada >> qtd_casos) {

        printf("Case %d:\n", ++qtd_testes);

        while(qtd_casos--) {
            cin >> index_min >> index_max;
            igual = true;

            if(index_min != index_max) {

                if(index_min > index_max) swap_num(&index_min, &index_max);

                ult_char = entrada[index_min];

                for(int i = index_min+1; i <= index_max; i++) {
                    if(ult_char != entrada[i]) igual = false;
                }
            }

            (igual) ? cout << "Yes\n" : cout << "No\n";
        }
    }

    return 0;
}