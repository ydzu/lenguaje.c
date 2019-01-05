#include <stdio.h>
#define MAXLINE 1000 /* longitud maxima por linea de entrada*/

int getlin (char line[], int max);
int countpattern(char source[], char searchfor[]);

/*encuantra todas las lineas que coincidan con el patrón*/
/*no entiendo por qué el printf de main no imprime??????*/
main()
{
  char pattern[] = "casa"; /* patron por buscar*/
  char line[MAXLINE];
  int found = 0, count, change, i;

  while(getlin(line, MAXLINE) > 0)

    /*  printf("Has tenido %s matches\n", line);  */
    if ((change=changepattern(line, pattern))==1){
      printf("\n  ---- ahora estás buscando la palabra %s   ---- \n\n", pattern);
      ;
    }

    else if ((count=countpattern(line, pattern))==1){
      printf("\n  ---- se encontró %i vez! ---- \n\n",count);
      found++;
    }
    else if (count>1){
      printf("\n  ---- se encontró %i veces! ---- \n\n",count);
      for(i=0; i < count; i++)
        found++;
    }
    else
      printf("\n  ---- no se encontró la palabra %s ---- \n\n", pattern);

  printf("Has tenido %d matches\n", found);

  return found;

}

/*getline: trae linea y la pone en s, regresa su longitud*/
int getlin(char s[], int lim)
{
  int c,i;

  i=0;
  while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: regresa el índice de t en s, -1 si no existe */
int countpattern(char s[], char t[])
{
  int i, j, k, l;
  l= 0;

  for (i=0; s[i] != '\0'; i++) {
    for(j=i, k=1; s[j]==t[k]; j++, k++)
      if(k> 0 && t[k+1] == '\0'){
        ++l;
        printf("\n       (en el índice %d)\n", j); /* Cómo podría hacer para acumular en un arreglo los valores que toma j e imprimirlos desde el main?*/
        break;
        }
  }

  return l;
}

int changepattern(char line[], char pattern[])
{
  int i;
  int j=0;

  if (line[j++]== 'd' && line[j++]== 'e' && line[j++]== ' '){
    for (i=0; pattern[i] !=  '\0'; i++, j++)
      if (pattern[i]!=line[j])
        return 0;

    if (line[j++]==' ' && line[j++]=='a' && line[j++]==' '){

      for (i=0; line[i] != '\n'; i++, j++)
        pattern[i] = line[j];
      pattern[i] = '\0';
      return 1;
    }
  }

  return 0;
}



/* ahora me devuelve el indice de s en donde coincide t  */
/* lograr que cuente la cantidad de casa dentro de s */
