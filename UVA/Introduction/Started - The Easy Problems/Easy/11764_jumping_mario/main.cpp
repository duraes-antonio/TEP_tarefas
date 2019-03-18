#include <iostream>

#include <iostream>
#include <map>

using namespace std;

int main() {

    int qtd_testes, qtd_paredes, altura, altura_anterior;
    int p_altos, p_baixos, i;

    i = 0;

    /*Leia a qtd. de testes*/
    cin >> qtd_testes;

    /*Enquanto houver testes*/
    while(qtd_testes--) {

        /*Leia a qtd. de paredes e a primeira altura*/
        cin >> qtd_paredes;
        cin >> altura_anterior;
        p_altos = p_baixos = 0;

        while(--qtd_paredes) {
            cin >> altura;

            /*Se a altura anterior for maior que a atual, será necessário um
             *pulo-alto, do contrário, um pulo-baixo já basta*/
            if (altura_anterior < altura) ++p_altos;

            else if (altura_anterior > altura) ++p_baixos;

            /*Atualize a altura anterior p/ a altura lida acima*/
            altura_anterior = altura;
        }

        cout << "Case " << i+1 << ": " << p_altos << ' ' << p_baixos << endl;
        i++;
    }

    return 0;
}