#include <stdio.h>
#include <string.h>

#define QTD_CHAR 1024

int main() {

    char linha[QTD_CHAR];
    int i, tam_linha, inicio;

    /* MONITORA A ABERTURA E FECHAMENTO DE ASPAS DUPLAS DO TEXTO DE ENTRADA
     * O valor é 1 p/ indicar que a próx. é a do início da frase, 0, p/ indicar que é do final.
     */
    inicio = 1;

    while (fgets(linha, QTD_CHAR, stdin)) {

        //Percorra cada char, verificando se é ou não aspas duplas;
        for (i = 0, tam_linha = (int) strlen(linha); i < tam_linha; i++) {

            //SE for aspas duplas de ABERTURA;
            if (*(linha+i) == '\"' && inicio) {
                printf("``");
                inicio--;
            }

            //SE for aspas duplas de FECHAMENTO;
            else if (*(linha+i) == '\"') {
                printf("''");
                inicio++;
            }

            else printf("%c", *(linha+i));
        }
    }

    return 0;
}