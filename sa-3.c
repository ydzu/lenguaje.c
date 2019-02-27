#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds);
int howMany();
int contin();
void cuestion();
int* oness(int n);


main()
{
	printf("\n");
	cuestion();
	howMany();

}


////////////////////////////////////////////////////////////////


void cuestion()
{
  char str1[20], str2[30];

	printf("Enter name: ");
	scanf("%s", str1);

	printf("Enter surname: ");
	scanf("%s", str2);


	printf("Sorry but... are you with someone else?");
	contin();
	printf("\nGreat, now we can start %s %s ...\n\n", str1, str2);

}

////////////////////////////////////////////////////////////////

int contin()
{
  char str11[3];


	scanf("%s", str11);

	if(str11[0]=='y' && str11[1]=='e' && str11[2]=='s'){
		printf("\n\n");
		cuestion();
		return 1;
	}

	else if(str11[0]=='n' && str11[1]=='o'){
		return 0;
	}

	else {
		printf("yes or no?\n");
		contin();

	}
	return 2;
}

////////////////////////////////////////////////////////////////

int howMany()
{
  int cant;

	printf("\nWe are going to execute the function oness(), but we've lost the parameter... Do you know it?");
	scanf("%d", &cant);
	oness(cant);
	return cant;
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
	free(p1);

  return p1; /*devuelve el apuntador q que apunta a la primer posición del array*/
}


////////////////////////////////////////////////////////////////

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}
