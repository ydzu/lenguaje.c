#include <stdio.h>
#include <stdlib.h>


int* howMany();
void cuestion();
int* oness(int n);


main()
{
	int *e;
	e = howMany();
	howMany();
	free(e);

}





////////////////////////////////////////////////////////////////

int *howMany()
{
  int cant;
	int *s;

	printf("We are going to execute the function oness(), but we've lost the parameter... Do you know it?");
	scanf("%d", &cant);
	s = oness(cant);
	return s;
}

////////////////////////////////////////////////////////////////

int* oness(int n) /*la idea es hacer otro malloc con oness y ver si cuando imprimo 15 posiciones para el puntero de ones() que es mas corto, si empieza a aparecer oness()*/
{
  int i;
  int *p1;
  p1 = (int*) malloc(n * sizeof(int));

	printf("Llamada a oness(%d):  ", n);

  for (i=0; i<n; i++){ 							/*el for completa la memoria reservada con unos*/
    *p1 = 1;  /*le da 1 como valor a donde estáapuntando w1*/
    p1++;  /*hace que w1 apunto a la próxima posición de memoria*/
  }

	p1 = p1-n;

  for(i = 0;  *p1 == 1; i++)
  {
      printf("%d, ", *p1);
			p1++;
  }

	p1 = p1-n;

	printf("\n");


  return p1; /*devuelve el apuntador q que apunta a la primer posición del array*/
}


////////////////////////////////////////////////////////////////
