#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

void main()
{
    int op, loop = 0, c;
    int op2;
    unsigned short releaseDate;
    char genre[45], name[90], trash;
    read();
    do
    {
        if (loop == 0)
        {
            loop++;
        }
        system("clear");
        printf("Escolha uma das opções a seguir \n\t 1-Alugar um filme");
        printf("\n\t 2-Entregar um filme");
        printf("\n\t 3-Pesquisar um filme");
        printf("\n\t 4-Imprimir acervo completo");
        printf("\n\t 5-Gerar Relatorios");
        printf("\n\t 6-Terminar o programa\n");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            system("clear");
            printf("Digite o nome do filme que gostaria de entregar: ");
            scanf("%c", &trash);
            scanf("%[^\n]%*c", name);
            take(name);
            break;
        case 2:
            system("clear");
            printf("Digite o nome do filme que gostaria de entregar: ");
            scanf("%c", &trash);
            scanf("%[^\n]%*c", name);
            giveBack(name);
            break;
        case 3:
            system("clear");
            printf("Digite o criterio pelo qual gostarias de pesquisar: ");
            printf("\n\t 1-Por Código");
            printf("\n\t 2-Por nome");
            printf("\n\t 3-Por ano");
            printf("\n\t 4-Por genero\n");
            scanf("%i", &op);
            search(op);
            break;
        case 4:
            system("clear");
            show();
            break;
        case 5:

            system("clear");
            printf("1 - Relatorio por filtro de Genero e Data de Lancamento\n");
            printf("2 - Relatorio de todos os filmes\n");
            printf("3 - Voltar\n");
            scanf("%i", &op2);

            switch(op2)
            {
                case 1:
                    system("clear");
                    printf("Digite o Genero do Filme: ");
                    scanf("%s", genre);
                    printf("\n");
                    printf("Digite a Data de Lancamento do Filme: ");
                    scanf("%hu", &releaseDate);
                    generateReportByGenreYear(genre, releaseDate);
                break;

                case 2: 
                    generateReportAllMovies();
                break;

                case 3: 
                
                break;

                default:
                    printf("\n\nComando Invalido\n");
                break;
            }
        break;

        case 6:
            system("clear");
            loop = 0;
            printf("O programa foi encerrado");
            break;
        default:
            system("clear");
            printf("Comando Invalido");

            break;
        }
        printf("\n=================================================");
        printf("\nDigite 1 para continuar\n");
        scanf("%i", &c);
    } while (loop != 0);
}