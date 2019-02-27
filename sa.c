#include <stdio.h>
#include <stdlib.h>

int* ones(int n);
void printArray(int* a);

main()
{
	int *b;
	b = ones(10);
	printArray(b);
}

int* ones(int n)
{
  int i;
  int *p, *q;
  p = (int*) malloc(n * sizeof(int));
	q = p;
	printf("me");

  for (i=0; i<n; i++){ 							/*el for completa la memoria reservada con unos*/
    *p = 1;  /*le da 1 como valor a donde estáapuntando p*/
    p++;  /*hace que p apunto a la próxima posición de memoria*/
  }

  return q; /*devuelve el apuntador q que apunta a la primer posición del array*/
}


void printArray(int* a)
{
	int i;
  for(i = 0;  15 > i; i++)
  {
      printf("%d, ", *a);
			a++;
  }

}
