#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

#define MAP_PAI_FILHOS map<char, vector<char>>

using namespace std;

/*Retorna um MAP com um char pai(chave) e seus nós associados(valor)*/
MAP_PAI_FILHOS tratar_entrada(string entrada) {

    MAP_PAI_FILHOS saida;
    vector<char> temp_viz;
    char ult_chave = 0;
    bool dois_pt = false;

    for (char caract : entrada) {

        if (caract == ':') dois_pt = true;

        /*Se o char. for ';', crie a chave com a lista de vizinhos lidos;*/
        else if (caract == ';') {
            dois_pt = false;
            saida[ult_chave] = temp_viz;
            temp_viz.clear();
        }

        /*Salve a letra antes dos dois pontos*/
        else if (not dois_pt) ult_chave = caract;

        /*Se já leu ':', o caracter atual é um dos nós vizinhos, adicione na lista;
         *O char. chave é vizinho do char atual também*/
        else {
            temp_viz.push_back(caract);

            if (find(saida[ult_chave].begin(), saida[ult_chave].end(), caract) == saida[ult_chave].end()) {
                saida[ult_chave].push_back(caract);
            }
        }
    }

    return saida;
}

/*Retorna a sequência com todas letras que foram lidas*/
string obter_letras_entrada(MAP_PAI_FILHOS mapa) {

    set<char> letras;
    string saida;

    for(auto par: mapa) {
        letras.insert(par.first);
        for(char letra: par.second) letras.insert(letra);
    }
    for(char letra: letras) saida += letra;

    return saida;
}

/*Cria um MAP c/ cada letra (chave) e sua posição (valor) na seq. de entrada*/
map<char, u_short> obter_letra_indice(string seq) {

    map<char, u_short> char_ind;
    for(u_short i = 0, tam = seq.size(); i < tam; i++) char_ind[seq[i]] = i;

    return char_ind;
}

u_short calc_max_dist(MAP_PAI_FILHOS mapa, map<char, u_short> letra_ind) {

    u_short dist_max = 0;
    u_short dist_atual;

    /*Para cada par(pai e vetor de filhos)*/
    for(auto &par: mapa) {

        /*Para cada nó filho*/
        for(char filho: par.second) {
            dist_atual = abs(letra_ind[par.first] - letra_ind[filho]);

            /*Se a dist. do pai até filho atual for maior que a máxima, atualize-a*/
            if(dist_atual > dist_max) dist_max = dist_atual;
        }
    }

    return dist_max;
}

int main() {

    u_short min_custo, custo_atual;
    string entrada, letras_ordem, melhor_seq;
    MAP_PAI_FILHOS mapa;
    map<char, u_short> char_index;

    /*Leia a entrada enquanto ela for diferente de '#'*/
    while (cin >> entrada and entrada != "#") {

        /*Crie o map contendo os nós pais como chave e seus nós filhos como valor*/
        mapa = tratar_entrada(entrada);

        /*Obtenha a sequência com todas as letras(string 'limpa')*/
        letras_ordem = obter_letras_entrada(mapa);

        /*Defina, inicialmene, o menor custo como o núm. de chars da entrada*/
        min_custo = letras_ordem.size();
        melhor_seq = letras_ordem;

        /*Enquanto houver permutações (ordenação diferente da string de entrada)*/
        do {

            /*Obtenha o map contendo cada char e sua posição na sequência acima*/
            char_index = obter_letra_indice(letras_ordem);

            custo_atual = calc_max_dist(mapa, char_index);

            if(custo_atual < min_custo || string(letras_ordem) < string(melhor_seq)) {
                min_custo = custo_atual;
                melhor_seq = letras_ordem;
            }
        } while(next_permutation(letras_ordem.begin(), letras_ordem.end()));

        /*Imprima a saída*/
        for(char letra: melhor_seq) cout << letra << ' ';
        printf("-> %d\n", min_custo);
    }
}