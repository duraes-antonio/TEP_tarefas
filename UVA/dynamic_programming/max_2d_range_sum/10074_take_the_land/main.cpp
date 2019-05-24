#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n_lin, n_col, acumulador;

    /*Enquanto houver linhas a serem lidas*/
    while(cin >> n_lin && n_lin > 0) {

        cin >> n_col;

        int matriz_acess[n_lin][n_col];
        int matriz[n_lin][n_col];

        /*Para cada linha*/
        for (int i = 0; i < n_lin; ++i) {

            /*Para cada coluna*/
            for (int j = 0; j < n_col; ++j) {

                /*Preencha a célula com o número lido*/
                cin >> matriz[i][j];
            }

        }

        /*Ideia para resolução: Criar uma matriz de acessibilidade:
         *Para cada posição, salvar o número máximo de áreas acessíveis a frente*/

        /*Para cada linha*/
        for (int i = 0; i < n_lin; ++i) {
            acumulador = 0;

            /*Para cada coluna*/
            for (int j = n_col - 1; j >= 0; --j) {

                /*Se o número atual for diferente de 0:
                 * reinicie o acumulador e marque a área como inacessível*/
                if(matriz[i][j]) matriz_acess[i][j] = acumulador = 0;

                /*Senão, a área não possui árvores: Incremente o acumulador
                 * e salve o número de áreas acessíveis a partir da posição atual*/
                else matriz_acess[i][j] = ++acumulador;
            }
        }


        /*IMPRIME matriz de acessibilidade*/
        cout << endl << endl;

        for (int i = 0; i < n_lin; ++i) {
            for (int j = 0; j < n_col; ++j) {
                cout << matriz_acess[i][j] << ' ';
            }
            cout << endl;
        }

    }

    return 0;
}