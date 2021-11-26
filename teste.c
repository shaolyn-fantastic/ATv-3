#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50


int main()
{
    char nome1[TAM], nome2[TAM];

    printf("*** Exibe nomes em ordem alfab\x82tica ****\n\n");

    printf("\n\nDigite o primeiro nome: \n\n");
    //só para strings
    gets(nome1);
    //Scanf não lê espaços
    //scanf("%s", &nome1);

    printf("\n\nDigite o segundo nome: \n\n");
    gets(nome2);
    //scanf("%s", &nome1);

    printf("\n\nNomes em ordem alfab%ctica: \n\n", 130);


    // Retorna -1 se a primeira string for menor que a segunda  == -1   ou  < 0
    // Retorna 1 se a primeira string for maior que a segunda  == 1   ou  > 0
    // Retorna 0 se a primeira string for igual à segunda  == 0
                //ana   andré
    if (strcmp (nome1, nome2) < 0)
    {
        printf("%s\n\n%s\n\n", nome1, nome2);
    }
    else
    {
        printf("%s\n\n%s\n\n", nome2, nome1);
    }

    printf("Valor da strcmp: %d", strcmp (nome1, nome2));

    printf("\n\n\n");


    system("pause");
 }
