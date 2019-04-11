#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 20

int getlin (char line[], int max);

//consulta fefe: que es **int ?

int main(){
  struct people{
    char name[20];
    int age;
  }person1, person2;

  char line[MAXLINE];
  int i;

  printf("What's your name?\n");
  getlin(line, MAXLINE);
  for (i=0; line[i] != '\0'; i++){
    person1.name[i] = line[i];
  }
  printf("What's your age?\n");
  scanf("%i*c",&person1.age);

  printf("What's your name?\n");  //no entiendo por qué cuando llega a este punto no queda a la espera de que se ingrese un valor por terminal
  getlin(line, MAXLINE);
  for (i=0; line[i] != '\0'; i++){
    person2.name[i] = line[i];
  }
  printf("What's your age?\n");
  scanf("%i\n",&person2.age);

  printf("1.Name: %s\n",person1.name);
  printf("1.Age: %i\n",person1.age);

  printf("2.Name: %s\n",person2.name);
  printf("2.Age: %i\n",person2.age);
}

/*getline: trae linea y la pone en s, regresa su longitud*/
int getlin(char s[], int lim)
{
  int c,i;

  i=0;
  while ((c = getchar()) != '\n' && c != EOF);
  while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
