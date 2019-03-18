#include <stdio.h>
#include <string.h>

#define MAX_CHAR 1024
#define OLA_ENG "HELLO"
#define OLA_SPA "HOLA"
#define OLA_GER "HALLO"
#define OLA_FRE "BONJOUR"
#define OLA_ITA "CIAO"
#define OLA_RUS "ZDRAVSTVUJTE"

int main()
{
    char entrada[MAX_CHAR];
    int cont = 0;

    scanf("%s", entrada);

    while(strcmp(entrada, "#"))
    {
        printf("Case %d: ", ++cont);
        if (!strcmp(entrada, OLA_ENG)) printf("ENGLISH\n");
        else if (!strcmp(entrada, OLA_SPA)) printf("SPANISH\n");
        else if (!strcmp(entrada, OLA_GER)) printf("GERMAN\n");
        else if (!strcmp(entrada, OLA_FRE)) printf("FRENCH\n");
        else if (!strcmp(entrada, OLA_ITA)) printf("ITALIAN\n");
        else if (!strcmp(entrada, OLA_RUS)) printf("RUSSIAN\n");
        else printf("UNKNOWN\n");

        scanf("%s", entrada);
    }

    return 0;
}