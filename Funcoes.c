#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes.h"
struct Movie
{
    unsigned long id;
    char name[32];
    unsigned short releaseDate;
    unsigned short quantity;
    char category[32];
    struct Movie *prox;
};
typedef struct Movie movie;
movie *lista;
movie *ini = NULL;
movie *fim = NULL;
void deleteString(char *string, char *sub)
{
    char *match;
    int len = strlen(sub);
    while ((match = strstr(string, sub)))
    {
        *match = '\0';
        strcat(string, match + len);
    }
}
void push(char string[5][32])
{
    if (fim == NULL)
    {
        ini = lista;
        fim = lista;
        lista->prox = NULL;
    }
    else
    {
        lista->prox = NULL;
        fim->prox = lista;
        fim = lista;
    }
    sscanf(string[0], "%ld", &lista->id);
    strcpy(lista->name, string[1]);
    sscanf(string[2], "%hd", &lista->releaseDate);
    sscanf(string[3], "%hd", &lista->quantity);
    deleteString(string[4], "\n");
    strcpy(lista->category, string[4]);
}
void read()
{
    char string[5][32];
    char *line = malloc(sizeof(char) * 256);
    char *tmp = malloc(sizeof(char) * 256);
    char *res = malloc(sizeof(char) * 32);

    FILE *fptr;
    fptr = fopen("entrada.txt", "r+");
    while (fgets(line, sizeof(char) * 256, fptr) != NULL)
    {
        lista = malloc(sizeof(movie));
        for (int i = 0; i < 5; i++)
        {
            strcpy(tmp, line);
            res = strtok(tmp, ";");
            strcpy(string[i], res);
            strcat(res, ";");
            deleteString(line, res);
        }
        push(string);
    }
}
void show()
{
    movie *aux;
    aux = ini;
    while (aux != NULL)
    {
        printf("Id: %lu\n", aux->id);
        printf("Nome: %s\n", aux->name);
        printf("Data de Lancamento: %hu\n", aux->releaseDate);
        printf("Quantidade: %hu\n", aux->quantity);
        printf("Categoria: %s\n", aux->category);
        printf("------------------------------------------------------\n");
        aux = aux->prox;
    }
}

void showSearchInt(unsigned long info)
{
    if (info == 0)
    {
        printf("Filme não encontrado\n");
        return;
    }
    movie *aux;
    aux = ini;
    int i = 0;

    while (aux != NULL)
    {
        if (info == aux->id || info == aux->releaseDate)
        {
            printf("Id: %lu\n", aux->id);
            printf("Nome: %s\n", aux->name);
            printf("Data de Lancamento: %hu\n", aux->releaseDate);
            printf("Quantidade: %hu\n", aux->quantity);
            printf("Categoria: %s\n", aux->category);
            printf("------------------------------------------------------\n");
            i++;
        }
        aux = aux->prox;
    }
    if (i == 0)
    {
        printf("Filme não encontrado\n");
    }
}
void showSearch(char info[90])
{
    movie *aux;
    aux = ini;
    int i = 0;
    while (aux != NULL)
    {
        if (strcmp(info, aux->name) == 0 || strcmp(info, aux->category) == 0)
        {
            printf("Id: %lu\n", aux->id);
            printf("Nome: %s\n", aux->name);
            printf("Data de Lancamento: %hu\n", aux->releaseDate);
            printf("Quantidade: %hu\n", aux->quantity);
            printf("Categoria: %s\n", aux->category);
            printf("------------------------------------------------------\n");
            i++;
        }
        aux = aux->prox;
    }
    if (i == 0)
    {
        printf("Filme não encontrado\n");
    }
}
void search(int op)
{
    char infoChar[90], trash;
    unsigned long info;
    switch (op)
    {
    case 1:
        printf("Digite o codigo do filme desejado: ");
        scanf("%lu", &info);
        showSearchInt(info);
        break;
    case 2:
        printf("Digite o codigo do filme desejado: ");
        scanf("%c", &trash);
        scanf("%[^\n]%*c", infoChar);
        showSearch(infoChar);
        break;
    case 3:
        printf("Digite o ano do filme desejado: ");
        scanf("%lu", &info);
        showSearchInt(info);
        break;
    case 4:
        printf("Digite o codigo do filme desejado: ");
        scanf("%s", infoChar);
        showSearch(infoChar);
        break;
    default:
        show();
        break;
    }
    return;
}
void searchR(char gender[45], unsigned short releaseDate)
{
    movie *aux;
    aux = ini;
    int i = 0;
    while (aux != NULL)
    {
        if (releaseDate == aux->releaseDate && strcmp(gender, aux->category) == 0)
        {
            printf("Id: %lu\n", aux->id);
            printf("Nome: %s\n", aux->name);
            printf("Data de Lancamento: %hu\n", aux->releaseDate);
            printf("Quantidade: %hu\n", aux->quantity);
            printf("Categoria: %s\n", aux->category);
            printf("------------------------------------------------------\n");
            i++;
        }
        aux = aux->prox;
    }
    if (i == 0)
    {
        printf("Filme não encontrado\n");
    }
}
void giveBack(char name[90])
{
    movie *aux;
    aux = ini;
    int i = 0;
    while (aux != NULL)
    {
        if (strcmp(name, aux->name) == 0)
        {
            aux->quantity++;
            return;
        }
        aux = aux->prox;
    }
    if (i == 0)
    {
        printf("Filme não encontrado\n");
    }
}
void take(char name[90])
{
    movie *aux;
    aux = ini;
    int i = 0;
    while (aux != NULL)
    {
        if (strcmp(name, aux->name) == 0)
        {
            if (aux->quantity == 0)
            {
                printf("Esgotado volte mais tarde\n");
                return;
            }
            aux->quantity--;
            return;
        }
        aux = aux->prox;
    }
    if (i == 0)
    {
        printf("Filme não encontrado\n");
    }
}