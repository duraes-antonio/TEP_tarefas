#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

    int qtd_tot_req, qtd_propostas, qtd_req_atend, qtd_testes;

    double preco_atual;
    string nome_item, temp_nome_item;

    /*Guarde o menor preço, o nome do item promissor e a qtd máx. de req. atend.*/
    int qtd_req_max;
    double menor_preco = 0;
    string nome_item_promissor;

    qtd_testes = 0;

    /*Leia as entradas Enquanto houver um número de requisições maior que zero*/
    while(cin >> qtd_tot_req >> qtd_propostas && qtd_tot_req) {

        if (qtd_testes) cout << endl;

        /*Reinicie a qtd. máx. de req. atendidos e limpe o buffer de entrada*/
        qtd_req_max = 0;
        cin.ignore();

        /*Leia o nome dos itens de requisitos e descarte (É DESNECESSÁRIO ARMAZENAR)*/
        for (int i = 0; i < qtd_tot_req; i++) getline(cin, temp_nome_item);

        /*Para cada proposta*/
        for(int i = 0; i < qtd_propostas; i++) {

            /*Leia o nome do Item proposto, seu preço e a qtd. de req. atendidos*/
            getline(cin, nome_item);
            cin >> preco_atual >> qtd_req_atend;

            cin.ignore();
            for (int j = 0; j < qtd_req_atend; j++)
                getline(cin, temp_nome_item);

            /*Se o item atual (atender mais requisitos) OU
             * (atender a mesma qtd. E tiver menor preço)*/
            if ((qtd_req_atend > qtd_req_max) ||
                (qtd_req_atend == qtd_req_max && preco_atual < menor_preco))
            {
                menor_preco = preco_atual;
                qtd_req_max = qtd_req_atend;
                nome_item_promissor = nome_item;
            }
        }

        cout << "RFP #" << ++qtd_testes << endl << nome_item_promissor << endl;
    }

    return 0;
}