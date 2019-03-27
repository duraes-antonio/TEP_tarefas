#include <stdio.h>
#include <string.h>

#define HAJJ "Hajj"
#define UMRAH "Umrah"

int main()
{
    int i = 0;
    char nome_evento[10];

    /*Leia a quantidade de operações*/
    scanf("%s", nome_evento);

    /*Enquanto houver operações a serem feitas*/
    while (strcmp(nome_evento, "*"))
    {  
        printf("Case %d: ", ++i);

        if (!strcmp(nome_evento, HAJJ)) printf("Hajj-e-Akbar\n");

        else printf("Hajj-e-Asghar\n");

        scanf("%s", nome_evento);
    }

    return 0;
}