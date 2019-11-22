#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

void main()
{
    int op, loop = 0;
    unsigned short releaseDate;
    char gender[45], name[90], trash;
    read();
    do
    {
        if (loop == 0)
        {
            loop++;
        }

        printf("Escolha uma das opções a seguir \n\t 1-Alugar um filme");
        printf("\n\t 2-Entregar um filme");
        printf("\n\t 3-Pesquisar um filme");
        printf("\n\t 4-Pesquisar acervo completo");
        printf("\n\t 5-Pesquisar por ano e por genero\n");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            printf("Digite o nome do filme que gostaria de entregar: ");
            scanf("%c", &trash);
            scanf("%[^\n]%*c", name);
            take(name);
            break;
        case 2:
            printf("Digite o nome do filme que gostaria de entregar: ");
            scanf("%c", &trash);
            scanf("%[^\n]%*c", name);
            giveBack(name);
            break;
        case 3:
            printf("Digite o criterio pelo qual gostarias de pesquisar: ");
            printf("\n\t 1-Por Código");
            printf("\n\t 2-Por nome");
            printf("\n\t 3-Por ano");
            printf("\n\t 4-Por genero\n");
            scanf("%i", &op);
            search(op);
            break;
        case 5:
            printf("Digite o ano e o genero do filme: \n");
            printf("O genero: ");
            scanf("%s", gender);
            printf("O ano: ");
            scanf("%hu", &releaseDate);
            printf("\n");
            searchR(gender, releaseDate);
            break;
        default:
            show();
            break;
        }
        printf("Deseja continuar? 1-sim 0-nao ");
        scanf("%i", &loop);
    } while (loop != 0);
}