#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_V 10000
#define MAX_IT 100

using namespace std;

int main() {

    int n_testes, a, b, c;
    int soma, mult, quad, z;
    vector<int> xyz;
    int x, y;

    cin >> n_testes;

    /*Enquanto houver casos de testes*/
    while (n_testes--) {

        /*Leia A, B e C*/
        cin >> a >> b >> c;
        bool resolvido = false;

        /*Se os valores forem inválidos ou houver algum igual, finalize*/
        if (a > b or a > c) x = y = MAX_IT;

        for (x = -MAX_IT; x < MAX_IT && not resolvido; ++x) {

            for (y = -MAX_IT; y <= MAX_IT && not resolvido; ++y) {

                /*Calcule o valor de Z*/
                z = a -x -y;

                /*Se uma das icógnitas forem duplicadas, vá p/ próxima iteração*/
                if(x == y or x == z or y == z) continue;

                /*Realize as operações e verifique se os val. x, y, z estão certos*/
                soma = x + y + z;
                mult = x * y * z;
                quad = x * x + y * y + z * z;

                if (soma == a and mult == b and quad == c) {
                    xyz = {x, y, z};
                    resolvido = true;
                }
            }
        }

        if (not resolvido) printf("No solution.\n");
        else {
            sort(xyz.begin(), xyz.end());
            printf("%d %d %d\n", xyz[0], xyz[1], xyz[2]);
        }

        xyz.clear();
    }

    return 0;
}