#include <iostream>
#include <algorithm>

#define MAX_M 100
#define MAX_N 100

using namespace std;

int matriz_acess[MAX_N][MAX_M];
int matriz[MAX_N][MAX_M];
int n_lin, n_col;

/*Ideia para resolução: Criar uma matriz de acessibilidade:
 *Para cada posição, salvar o número máximo de áreas acessíveis a frente*/
void criar_matriz_acess(int n_lin, int n_col) {

    int acumulador;

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
}

int calc_max_de_um_ponto(int i_lin, int i_col) {

    int comprimento, val_menor, val_max, val_atual;
    comprimento = 0;
    val_max = matriz_acess[i_lin][i_col];
    val_menor = matriz_acess[i_lin][i_col];

    while(i_lin < n_lin) {
        ++comprimento;
        val_atual = matriz_acess[i_lin][i_col];

        /*Se o valor atual for zero, retorne o máximo encontrado*/
        if(!val_atual) return val_max;

        /*Se o valor atual for inferior ao menor, atualize o menor valor*/
        if(val_atual < val_menor) val_menor = val_atual;

        /*Senão, se o valor atual for maior que o máx, atualize o máximo*/
        else if(val_atual > val_max) val_max = val_atual;

        if(val_menor*comprimento > val_max) val_max = val_menor*comprimento;

        ++i_lin;
    }

    return val_max;
}

int main() {

    int val_max, val_atual;

    /*Enquanto houver linhas a serem lidas*/
    while(cin >> n_lin && n_lin > 0) {

        cin >> n_col;

        /*Para cada linha*/
        for (int i = 0; i < n_lin; ++i) {

            /*Para cada coluna, preencha a célula com número lido*/
            for (int j = 0; j < n_col; ++j) cin >> matriz[i][j];
        }

        /*Cria matriz com valor máximo alcançado por cada ponto da matriz*/
        criar_matriz_acess(n_lin, n_col);

        val_max = 0;

        /*Para cada ponto(coluna i, linha i) na matriz*/
        for(int i_col = 0; i_col < n_col; ++i_col) {

            for(int i_lin = 0; i_lin < n_lin; ++i_lin) {

                /*Calcule o máximo alcançável a partir da coluna atual para baixo*/
                val_atual = calc_max_de_um_ponto(i_lin, i_col);

                if(val_atual > val_max) val_max = val_atual;
            }
        }

        cout << val_max << endl;
    }

    return 0;
}
