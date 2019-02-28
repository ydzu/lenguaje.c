#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int* ones(int n);
int* twos(int n);
char* ceros(int n);
void circulo(int n);
int* consultaPaso();



main()
{

	ceros(10);
	circulo(*(consultaPaso()));
	circulo(*(consultaPaso()));
	circulo(*(consultaPaso()));
	circulo(*(consultaPaso()));

	return 1;
}

////////////////////////////////////////////////////////////////


int* ones(int n) /*la idea es hacer otro malloc con oness y ver si cuando imprimo 15 posiciones para el puntero de ones() que es mas corto, si empieza a aparecer oness()*/
{
  int i;
  int *p1;
  p1 = (int*) malloc(n * sizeof(int));

	printf("(1*%d): ", n);

  for (i=0; i<n; i++){ 							/*el for completa la memoria reservada con unos*/
    *p1 = 1;  /*le da 1 como valor a donde estáapuntando w1*/
    p1++;  /*hace que w1 apunto a la próxima posición de memoria*/
  }
	p1 = p1-n;

  for(i = 0;  *p1 == 1; i++)
  {
      printf("%d", *p1);
			p1++;
  }

	p1 = p1-n;
	printf("\n");


  return p1; /*devuelve el apuntador q que apunta a la primer posición del array*/
}


////////////////////////////////////////////////////////////////

int* twos(int n) /*la idea es hacer otro malloc con oness y ver si cuando imprimo 15 posiciones para el puntero de ones() que es mas corto, si empieza a aparecer oness()*/
{
  int i;
  int *p1;
  p1 = (int*) malloc(n * sizeof(int));

	printf("(2*%d): ", n);

  for (i=0; i<n; i++){ 							/*el for completa la memoria reservada con unos*/
    *p1 = 2;  /*le da 1 como valor a donde estáapuntando w1*/
    p1++;  /*hace que w1 apunto a la próxima posición de memoria*/
  }
	p1 = p1-n;

  for(i = 0;  *p1 == 2; i++)
  {
      printf("%d", *p1);
			p1++;
  }

	p1 = p1-n;
	printf("\n");

  return p1; /*devuelve el apuntador q que apunta a la primer posición del array*/
}

char* ceros(int n) /*la idea es hacer otro malloc con oness y ver si cuando imprimo 15 posiciones para el puntero de ones() que es mas corto, si empieza a aparecer oness()*/
{
  int i;
  char *p1;
  p1 = (char*) malloc((n) * sizeof(char));

	printf("(1*%d): ", n);

	for (i=0; i<(floor(n/2)); i++){ 							/*el for completa la memoria reservada con unos*/
 	 *p1 = ' ';  /*le da 1 como valor a donde estáapuntando w1*/
 	 p1++;  /*hace que w1 apunto a la próxima posición de memoria*/
  }

  for (i=0; i<(floor(n/2)+1); i++){ 							/*el for completa la memoria reservada con unos*/
    *p1 = 'L';  /*le da 1 como valor a donde estáapuntando w1*/
    p1++;  /*hace que w1 apunto a la próxima posición de memoria*/
  }
	p1 = p1-n;

  for(i = 0;  *p1 == 'L' || *p1 == ' '; i++)
  {
      printf("%c", *p1);
			p1++;
  }

	p1 = p1-n;
	printf("\n");


  return p1; /*devuelve el apuntador q que apunta a la primer posición del array*/
}

void circulo(int n)
{
	int i, k;
	double j;

	for (i = 0; i < n; i++){
			j = (3.14/n)*i;
			k = 180*(sin(j));
			k = floor(k);
			ones(k);
			k = k+(1);
			ceros(k);
	}
}

int* consultaPaso()
{
	int paso;
	int *paso1;
	paso1 = (int*) malloc(sizeof(int));

	printf("De cuantos renglones quiere la curva?");
	scanf("%d", &paso);
	*paso1 = paso;
	return paso1;
}
