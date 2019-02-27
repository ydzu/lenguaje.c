#include <stdio.h>
#include <stdlib.h>

/* En esta version vamos a intetar que el array sea ja[] sea generado con la función ones y no declarado antes*/

void printArray(char arr[]);
int ones(int n, char s); /* acá la idea es que s sea el char a repetir n veces*/
char ja[0];

main()
{
  ones(40, 2);
  printArray(ja);

  ones(40, 3);
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


int ones(int n, char s)
{
  int i,j=0;

  for (i=0; i<n; i++){
    ja[i] = s;
    j++;
  }

  ja[i] = '\0';

  return j;

}



/* PARA LA VERSI'ON CON MALLOC, CONCEPTUALMENTE CREO QUE SER'IA INICIALIZAR EL JA CON UN ESPACIO GRANDE Y PODER GUARDAR AH'I LA CANTIDAD DE 1S QUE SEA NECESARIA
*/
