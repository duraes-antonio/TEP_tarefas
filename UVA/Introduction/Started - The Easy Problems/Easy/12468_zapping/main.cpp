#include <iostream>

#define MAX_CANAL 99

using namespace std;

int main() {
    
    int canal_atual, canal_destino;
    int de_0_ao_dest, dest_ao_atual;

    cin >> canal_atual;
    
    while(canal_atual > -1) {

        cin >> canal_destino;

        if (canal_atual > canal_destino) {

            /*Do canal atual até o 0 (MAX_CANAL - canal_atual + 1).
             *Do canal 0 até o canal destino; (distância até o 0 + canal_destino)*/
            de_0_ao_dest = MAX_CANAL - canal_atual + 1 + canal_destino;

            dest_ao_atual = canal_atual - canal_destino;
        }

        else {
            dest_ao_atual = canal_destino - canal_atual;

            /*Do canal destino até o 0 (MAX_CANAL - canal_destino + 1).
             *Do canal 0 até o canal atual; (distância até o 0 + canal_atual)*/
            de_0_ao_dest = MAX_CANAL - canal_destino + 1 + canal_atual;
        }

        if (de_0_ao_dest < dest_ao_atual) cout << de_0_ao_dest << endl;
        else cout << dest_ao_atual << endl;

        cin >> canal_atual;
    }
    
    return 0;
}