#include <stdio.h>
#include <stdlib.h>

/* En esta version el printArray solo necesita saber d'onde comienza el array. la fguncion ones( ) devuelve el largo pero no se est'a usando*/

void printArray(char arr[]);
int ones(int n);

char ja[0];

main()
{

  ones(40);
  printArray(ja);

  return 1;

}

void printArray(char arr[])
{
  int i;

  printf("Array elements are: \n");
  for(i = 0; arr[i] != '\0'; i++)
  {
      printf("%d, ", arr[i]);
  }
  printf("\n");
}


int ones(int n)
{
  int i,j=0;

  for (i=0; i<n; i++){
    ja[i] = 1;
    j++;
  }

  ja[i] = '\0';

  return j;

}



/* PARA LA VERSI'ON CON MALLOC, CONCEPTUALMENTE CREO QUE SER'IA INICIALIZAR EL JA CON UN ESPACIO GRANDE Y PODER GUARDAR AH'I LA CANTIDAD DE 1S QUE SEA NECESARIA
*/
