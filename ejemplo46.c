#include <stdio.h>
#define MAXLINE 1000 /* longitud maxima por linea de entrada*/

int getlin (char line[], int max);
int countpattern(char source[], char searchfor[]);

char pattern[] = "casa"; /* patron por buscar*/

main()
{
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
        printf("\n       (en el índice %d)\n", j);
        /* Cómo podría hacer para acumular en un array los valores que toma j y llevarlos al main?*/
        break;
        }
  }

  return l;
}

int changepattern(char s[], char t[], char npattern[])
{
  int i=0;

  int j=0;

  char *q, *w, *e, *r;
  q = &pattern[0];
  w = &pattern[1];
  e = &pattern[2];
  r = &pattern[3]; /* sería correcto hacer esto pero con arreglos (para poder hacerlo con diferentes largos), pero si hago un arreglo dentro de esta func no puedo apuntarlo a pattern[] */

  if (s[0]== 'd' && s[1]== 'e' && s[2]== ' '){
    if (t[0]==s[3] && t[1]==s[4] && t[2]==s[5] && t[3]==s[6]){
      if (s[7]==' ' && s[8]=='a' && s[9]==' '){
        /* printf("%c%c%c%c\n", s[10], s[11], s[12], s[13]); */
        /*s[10] = *q;
        s[11] = *w;
        s[12] = *e;
        s[13] = *r;*/
        *q = s[10];
        *w = s[11];
        *e = s[12];
        *r = s[13];

        return 1;
      }
    }
  }

  return 0;
}



/* ahora me devuelve el indice de s en donde coincide t  */
/* lograr que cuente la cantidad de casa dentro de s */
