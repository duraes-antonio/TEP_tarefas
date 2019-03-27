#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int qtd_cursos, qtd_categ, curso_id;
    int qtd_categ_cursos, qtd_categ_min, i, j;
    vector<int> cursos;
    bool atende_requisitos;
    string limbo;

    while(cin >> qtd_cursos && qtd_cursos) {
        cin >> qtd_categ;
        atende_requisitos = true;
        cursos.clear();

        /*Armazene todos ids dos cursos desejados*/
        for (i = 0; i < qtd_cursos; ++i) {
            cin >> curso_id;
            cursos.push_back(curso_id);
        }

        /*Leia e armazene todas as categorias*/
        for (i = 0; i < qtd_categ && atende_requisitos; i++) {
            cin >> qtd_categ_cursos >> qtd_categ_min;
            j = 0;

            /*Enquanto todas categorias não forem lidas &&
             *houver requisitos mínimos a serem preenchidos*/
            while(j < qtd_categ_cursos && qtd_categ_min) {
                ++j;
                cin >> curso_id;

                /*Se encontrar o curso, um requisito foi satisfeito*/
                if(find(cursos.begin(), cursos.end(), curso_id) != cursos.end()) {
                    --qtd_categ_min;
                }

                /*Se o núm. de categ. restante for menor que o mín. necessário*/
                else if ((qtd_categ_cursos - j) < qtd_categ_min) break;
            }

            /*Enquanto ainda houver categorias na linha a serem lidas, leia-as*/
            while(j++ < qtd_categ_cursos) cin >> curso_id;

            if(qtd_categ_min) atende_requisitos = false;
        }

        cin.ignore();
        while(i++ < qtd_categ) getline(cin, limbo);

        printf((atende_requisitos) ? "yes\n" : "no\n");
    }

    return 0;
}