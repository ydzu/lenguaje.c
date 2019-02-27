#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void cuestion();
int* ones(int n);
int* twos(int n);
int* aumentar(int *ptr); //devuelve el mismo puntero que se le pasó con sus ints aumentados en 1
void imprimirDesdePosicion(int *p, int n);
void circulo(int n);
int* consultaPaso();



main()
{
	int i, n = 2;
	int *p, *q;

	q = ones(n);
	p = twos(n*3);
	q = ones(n*8);
	p = twos(n*2);

	aumentar(p);
	aumentar(p);
	aumentar(p);
	aumentar(p);

	imprimirDesdePosicion(p,10);
	imprimirDesdePosicion(q,20);

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

	printf("Llamada a ones(%d):  ", n);

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

	printf("Llamada a twos(%d):  ", n);

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


void imprimirDesdePosicion(int *p, int n)
{
	int i, *e;
	printf("impresoDesdePosicion:");

	e=p;
	p--;
	printf("La posición -1 es (%d), ", *p);
	p=e;

	for(i = 0; i < n; i++)
  {
      printf("%d, ", *p);
			p++;
  }
	p = p - n;
	printf("\n");
}

int* aumentar(int *ptr) /*la idea es hacer otro malloc con oness y ver si cuando imprimo 15 posiciones para el puntero de ones() que es mas corto, si empieza a aparecer oness()*/
{
	int i, a, *ptrInit;
	a =	*ptr;
	while (*ptr == a){
		(*ptr)++;
		ptr++;
	}
	ptr = ptrInit;

  return ptr; /*devuelve el apuntador q que apunta a la primer posición del array*/
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
			k = k+(10);
			twos(k);
	}
}

int* consultaPaso()
{
	int paso;
	int *paso1;
	paso1 = (int*) malloc(sizeof(int));

	printf("Ingrese cantidad de elementos para la progresión de Fibonacci:");
	scanf("%d", &paso);
	*paso1 = paso;
	return paso1;
}
