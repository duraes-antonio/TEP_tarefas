#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*Problema: 101131*/

struct Elefante {
    int peso;
    int qi;

    /*Ordem em que os dados deste elefante foi lido*/
    int ordem;

    /*Quantidade de elefantes que podem ser associados a este*/
    int qtd = 1;

    /*Índice do próximo elefante ligado ao atual*/
    int prox = -1;
};


/*Compara dois elefantes com base em seu QI*/
bool comparar(Elefante elefante_1, Elefante elefante_2) {
    return elefante_1.qi > elefante_2.qi;
}


bool maior(Elefante* elefante_1, Elefante* elefante_2) {
    return elefante_1->peso > elefante_2->peso && elefante_1->qi < elefante_2->qi;
}


Elefante lis(vector<Elefante> &elefantes) {

    Elefante elef_maior_lis = elefantes[0];
    Elefante* elef_anterior;
    Elefante* elef_atual;
    int tam = elefantes.size();

    for(int i = tam - 1; i >= 0; i--) {
        elef_anterior = &(elefantes[i]);
        
        for (int j = i + 1; j < tam; j++) {
            elef_atual = &(elefantes[j]);
            
            if(maior(elef_atual, elef_anterior) && elef_atual->qtd >= elef_anterior->qtd) {
                elef_anterior->qtd = 1 + elef_atual->qtd;
                elef_anterior->prox = j;
            }
        }

        if (elef_anterior->qtd > elef_maior_lis.qtd) elef_maior_lis = *elef_anterior;
    }

    return elef_maior_lis;
}


int main() {

    vector<Elefante> elefantes;
    Elefante temp_elef = Elefante();
    int ordem = 0;

    /*Pré-aloque o máximo de Elefantes descrito no problema*/
    elefantes.reserve(1000);

    /*Enquanto houver dados a serem lidos*/
    while (scanf("%d %d", &temp_elef.peso, &temp_elef.qi) == 2) {
        temp_elef.ordem = ++ordem;
        elefantes.push_back(temp_elef);
    }

    sort(elefantes.begin(), elefantes.end(), comparar);
    Elefante elef_maior_lis = lis(elefantes);

    /*Imprima a quantidade de elefantes encontradas e a ordem da cada elefante*/
    cout << elef_maior_lis.qtd << endl;

    /*Para cada elefante incluído na subsequência, imprima a ordem em que foi lido*/
    for(int i = elef_maior_lis.qtd; i; --i) {
        cout << elef_maior_lis.ordem << endl;
        elef_maior_lis = elefantes[elef_maior_lis.prox];
    }

    return 0;
}