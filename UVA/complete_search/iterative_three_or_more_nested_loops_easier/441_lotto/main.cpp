#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tam_lista, temp_num;
    vector<int> numeros;

    while(cin >> tam_lista && tam_lista > 0) {

        if (!numeros.empty()) cout << endl;

        numeros.clear();
        
        /*Adicione os números da entrada*/
        for (int i = 0; i < tam_lista; i++) {
            cin >> temp_num;
            numeros.push_back(temp_num);
        }

        for (int i = 0; i < tam_lista; ++i) {
            for (int j = i + 1; j < tam_lista; ++j) {
                for (int k = j + 1; k < tam_lista; ++k) {
                    for (int l = k + 1; l < tam_lista; ++l) {
                        for (int m = l + 1; m < tam_lista; ++m) {
                            for (int n = m + 1; n < tam_lista; ++n) {
                                printf("%d %d %d %d %d %d\n", numeros[i],
                                       numeros[j], numeros[k], numeros[l],
                                       numeros[m], numeros[n]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

