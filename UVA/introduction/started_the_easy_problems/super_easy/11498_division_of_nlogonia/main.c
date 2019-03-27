#include <stdio.h>

int main()
{

    int qtd_coord, divisa_x, divisa_y, temp_x, temp_y;

    fscanf(stdin, "%d", &qtd_coord);

    /*Enquanto a quantidade de coordenads não for 0*/
    while (qtd_coord)
    {
        /*Leia x e y da divisa*/
        fscanf(stdin, "%d %d", &divisa_x, &divisa_y);

        /*Enquanto houver coordenadas a serem processadas;*/
        while (qtd_coord--)
        {
            /*Leia a plocalização da residência*/
            fscanf(stdin, "%d %d", &temp_x, &temp_y);

            /*Se estver em pelo menos uma das divisas*/
            if (temp_x == divisa_x || temp_y == divisa_y) printf("divisa\n");
            
            else if (temp_x > divisa_x && temp_y > divisa_y) printf("NE\n");

            else if (temp_x < divisa_x && temp_y > divisa_y) printf("NO\n");
            
            else if (temp_x < divisa_x && temp_y < divisa_y) printf("SO\n");
            
            else if (temp_x > divisa_x && temp_y < divisa_y) printf("SE\n");
        }

        /*Leia a quantidade de coordenads*/
        fscanf(stdin, "%d", &qtd_coord);
    }
    return 0;
}