//#include <iostream>
//#include <map>
//#include <vector>
//#include <algorithm>
//
//#define MAP_CHAR_CHAR map<char, vector<char>>
//
//using namespace std;
//
//MAP_CHAR_CHAR tratar_entrada(string entrada) {
//
//    MAP_CHAR_CHAR saida;
//    vector<char> temp_viz;
//    char ult_chave;
//    bool dois_pt = false;
//
//    for (char caract : entrada) {
//
//        if(caract == ':') dois_pt = true;
//
//            /*Se o char. for ';', crie a chave com a lista de vizinhos lidos;*/
//        else if(caract == ';') {
//            dois_pt = false;
//            saida[ult_chave] = temp_viz;
//            temp_viz.clear();
//        }
//
//            /*Salve a letra antes dos dois pontos*/
//        else if(not dois_pt) ult_chave = caract;
//
//            /*Se já leu ':', o caracter atual é um dos nós vizinhos, adicione na lista;
//             *O char. chave é vizinho do char atual também*/
//        else {
//            temp_viz.push_back(caract);
//
//            if(find(saida[caract].begin(), saida[caract].end(), ult_chave) == saida[caract].end()) {
//                saida[caract].push_back(ult_chave);
//            }
//        }
//    }
//
//    saida[ult_chave] = temp_viz;
//
//    return saida;
//}
//
//void imprimir_entrada(string entrada) {
//
//    MAP_CHAR_CHAR result = tratar_entrada(entrada);
//
//    for(auto par: result) {
//        cout << par.first << ": ";
//
//        for (char i : par.second) {
//            cout << i << " ";
//        }
//
//        cout << endl;
//    }
//}
//
//int busca_rec(MAP_CHAR_CHAR map, vector<char> cand, vector<char> black, char busc) {
//
//    int dist, menor_dist;
//    dist = menor_dist = 0;
//
//    if(cand.empty()) return 0;
//
//    /*Se o nó buscado for vizinho do atual analizado*/
//    if(find(cand.begin(), cand.end(), busc) != cand.end()) menor_dist = 1;
//
//    /*Senão, adicione os vizinhos do atual p/ serem analizados e incr. a dist.*/
//    else {
//
//        for (char vizinho: cand) {
//            black.push_back(cand[0]);
//            cand.erase(cand.begin() + 0);
//
//            for (char atual_viz: map[vizinho]) {
//
//                if (find(cand.begin(), cand.end(), atual_viz) == cand.end() &&
//                    find(black.begin(), black.end(), atual_viz) == cand.end()) {
//                    cand.push_back(atual_viz);
//                }
//            }
//
//            dist = 1 + busca_rec(map, cand, black, busc);
//
//            if(dist < menor_dist || !menor_dist) menor_dist = dist;
//        }
//    }
//
//    return menor_dist;
//}
//
//int calc_menor_dist(MAP_CHAR_CHAR map, char no1, char no2) {
//
//    int menor_dist, dist;
//
//    if(find(map[no1].begin(), map[no1].end(), no2) != map[no1].end()) return 1;
//
//    vector<char> candidatos;
//    candidatos = map[no1];
//
//    while(!candidatos.empty()) {
//
//    }
//
//    return 1;
//}
//
//int main() {
//
//    int max_custo;
//    string entrada;
//
//    while(cin >> entrada and entrada != "#") {
//        map<char, vector<char>> result = tratar_entrada(entrada);
//
//        for (auto par: result) {
//            vector<char> lista = {par.first};
//
//            for (auto dest: result) {
//                if(par.first == dest.first) continue;
//
//                printf("%c -> %c - D = %d\n", par.first, dest.first,
//                        busca_rec(result, result[par.first], lista, dest.first));
//            }
//
//            cout << endl;
//        }
//    };
//
//}