#include <stdio.h>
#include <stdlib.h>
#define IMPR 15

int* ones(int n);
int* oness(int n);


main()
{
	printf("\nEstamos imprimiendo %d posiciones\n\n", IMPR);
	ones(10);
	oness(10);
	ones(2);
	oness(2);
	ones(4);
	oness(4);
	ones(22);
	oness(22);
	printf("\n");
}

int* ones(int n)
{
  int i;
  int *p, *q, *w;
  p = (int*) malloc(n * sizeof(int));
	w = p;
	q = p;
	printf("Llamada a ones(%d):  ", n);

  for (i=0; i<n; i++){ 							/*el for completa la memoria reservada con unos*/
    *w = 1;  /*le da 1 como valor a donde estáapuntando p*/
    w++;  /*hace que p apunto a la próxima posición de memoria*/
  }

  for(i = 0;  IMPR > i; i++)
  {
      printf("%d, ", *q);
			q++;
  }
	printf("\n");
	/*free(p);*/   /*  ATENCION! ESTOY DEJANDO QUE ONES NO SE LIBERE*/


  return q; /*devuelve el apuntador q que apunta a la primer posición del array*/
}

int* oness(int n) /*la idea es hacer otro malloc con oness y ver si cuando imprimo 15 posiciones para el puntero de ones() que es mas corto, si empieza a aparecer oness()*/
{
  int i;
  int *p1, *q1, *w1;
  p1 = (int*) malloc(n * sizeof(int));
	w1 = p1;
	q1 = p1;

	printf("Llamada a oness(%d):  ", n);

  for (i=0; i<n; i++){ 							/*el for completa la memoria reservada con unos*/
    *w1 = 1;  /*le da 1 como valor a donde estáapuntando w1*/
    w1++;  /*hace que w1 apunto a la próxima posición de memoria*/
  }

	w1 = p1;

  for(i = 0;  *w1 == 1; i++)
  {
      printf("%d, ", *q1);
			w1++;
  }
	printf("\n");
	free(p1);


  return q1; /*devuelve el apuntador q que apunta a la primer posición del array*/
}
