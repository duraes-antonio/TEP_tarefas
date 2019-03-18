#include <iostream>

using namespace std;

int main() {

    int qtd_testes, num_anterior, num_atual;
    int cresc, desc;

    cin >> qtd_testes;
    cout << "Lumberjacks:" << endl;

    /*Enquanto houver testes*/
    while(qtd_testes--) {

        cresc = desc = 0;
        cin >> num_anterior;

        /*Leia o pŕoximo número e compare com o anterior lido*/
        for (int i = 0; i < 9; i++) {
            cin >> num_atual;

            if (num_anterior <= num_atual) cresc = 1;
            else if (num_anterior > num_atual) desc = -1;

            num_anterior = num_atual;
        }

        (cresc + desc) ? cout << "Ordered" : cout << "Unordered";

        cout << endl;
    }

    return 0;
}