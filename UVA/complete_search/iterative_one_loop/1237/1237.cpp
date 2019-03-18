#include <iostream>
#include <map>

using namespace std;

string buscar_veiculo(int preco, map<string, pair<int, int>> veiculos) {

    int n_candidatos = 0;
    string nome;

    for(const auto &elem: veiculos) {

        if (preco >= elem.second.first && preco <= elem.second.second) {
            nome = elem.first;
            n_candidatos++;

            /*Se houver mais que um fabricante, finalize a busca*/
            if (n_candidatos > 1) break;
        }
    }

    /*Se houver 0 ou mais que 1 fabricante, return 'undetermined'.
     *Senão, retorne o nome do fabricante*/
    return n_candidatos != 1 ? "UNDETERMINED" : nome;
}

int main()
{
    short qtd_testes;
    int preco_baixo, preco_alto, preco_atual, qtd_linhas;
    string nome;

    map<string, pair<int, int>> veiculos;
    
    cin >> qtd_testes;

    /*Enquanto houver casos de teste*/
    while(qtd_testes--){

        cin >> qtd_linhas;
        veiculos.clear();

        /*Enquanto houver dados dos veículos*/
        while(qtd_linhas--) {
            /*Leia o nome, menor preço de fabricação e maior preço*/
            cin >> nome >> preco_baixo >> preco_alto;

            /*Crie o veículo com seu nome como chave e seus preços como valor*/
            veiculos[nome] = make_pair(preco_baixo, preco_alto);
        }

        cin >> qtd_linhas;

        /*Leia os preços de busca e busque pelo fabricante*/
        while(qtd_linhas--) {
            cin >> preco_atual;
            cout << buscar_veiculo(preco_atual, veiculos) << endl;
        }

        if (qtd_testes) cout << endl;
    }
    
    return 0;
}