/* CREO QUE ESTA BIEN ESCRITO, CÓMO PODRÍA COMPROBARLO?*/

#include <stdio.h>
#define MAXLINE 1000 /* longitud maxima por linea de entrada*/

int getlin (char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "casa"; /* patron por buscar*/

/*encuantra todas las lineas que coincidan con el patrón*/

main()
{
  char line[MAXLINE];
  int found = 0;

  while(getlin(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0){
      printf("%s",line);
      found++;
    }
  return found;
}

/*getline: trae linea y la pone en s, regresa su longitud*/
int getlin(char s[], int lim)
{
  int c,i;

  i=0;
  while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: regresa el índice de t en s, -1 si no existe */
int strindex(char s[], char t[])
{
  int i, j, k;

  for (i=0; s[i] != '\0'; i++){
    for(j=i, k=0; t[k] != '\0'&& s[j]==t[k]; j++, k++)
      ;
      if(k> 0 && t[k] == '0')
        return i;
  }
  return -1;
}
