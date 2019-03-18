#include <stdio.h>
#include <string.h>

#define QTD_CHAR 1024

int main() {

    char entrada[QTD_CHAR];

    while (fgets(entrada, QTD_CHAR, stdin)) printf("%s", entrada);

    return 0;
}