#include <stdio.h>

#define PRINTLIMIT 80
#define MAXLINE 1000

int getlin(char line[], int limit);
void copy(char from[], char to[]);


/* 1-17: Write a program to print all input lines that are longer than
 * 80 characters.  MODIFIQUÉ GETLINE POR GETLIN PORQUE SE PISABA CON LA FUNCIÓN STANDARD. SIGUE SIN IMPRIMIR. VOY A REVOLEAR LA COMPU POR LA VENTANA PRONTO */

main()
{
    int len;
    char line[MAXLINE];

    while((len = getlin(line, MAXLINE)) > 0) {
        if (len > 80)
            printf("%s\n", line);
    }
}

int getlin(char line[], int limit)
{

    int i, c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void copy(char from[], char to[])
{
    int i;

    for (i = 0; (to[i] = from[i]) != '\0'; ++i)
            ;
}
