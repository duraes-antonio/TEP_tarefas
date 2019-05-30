#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Problema: 101131*/

struct Elefante {
    int peso;
    int qi;
    int ordem;
};

/*Compara dois elefantes com base em seu QI*/
bool comparar(Elefante elefante_1, Elefante elefante_2) {
    return elefante_1.qi > elefante_2.qi;
}

int main() {

    vector<Elefante> elefantes;
    Elefante temp_elef = Elefante();
    int ordem = 0;

    /*Enquanto houver dados a serem lidos*/
    while(scanf("%d %d", &temp_elef.peso, &temp_elef.qi) == 2) {
        temp_elef.ordem = ++ordem;
        elefantes.push_back(temp_elef);
    }

    sort(elefantes.begin(), elefantes.end(), comparar);

    for(auto par: elefantes) {
        cout << par.ordem << " " << par.peso << " " << par.qi << endl;
    }
    return 0;
}