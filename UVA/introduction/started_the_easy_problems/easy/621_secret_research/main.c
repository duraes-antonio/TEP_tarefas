#include <stdio.h>
#include <string.h>

#define MAX_CHAR 1024

int main() {

    char linha[MAX_CHAR];
    int qtd_entrada, ult;

    scanf("%d", &qtd_entrada);

    while (qtd_entrada--) {
        
        scanf("%s", linha);
        ult = strlen(linha) - 1;

        if(strlen(linha) < 3) printf("+\n");

        else if (linha[0] == '9' && linha[ult] == '4') printf("*\n");

        else if (linha[ult - 1] == '3' && linha[ult] == '5') printf("-\n");

        else printf("?\n");
    }

    return 0;
}