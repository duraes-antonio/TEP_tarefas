#include <iostream>
#include <vector>

using namespace std;

int main() {

    int qtd_testes, qtd_fazendeiros;
    int tam_fazenda, qtd_animais,grau_cuidado_ambiente;
    int premio;

    cin >> qtd_testes;

    while (qtd_testes--) {

        cin >> qtd_fazendeiros;
        premio = 0;

        while (qtd_fazendeiros--) {
            cin >> tam_fazenda >> qtd_animais >> grau_cuidado_ambiente;
            premio += tam_fazenda * grau_cuidado_ambiente;
        }

        printf("%d\n", premio);
    }

    return 0;
}