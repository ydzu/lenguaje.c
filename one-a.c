#include <stdio.h>
#include <stdlib.h>

/* En esta version el one devuelve la cantidad de elementos que tiene el array. el printArray necesita saber d'onde empieza
el puntero y la cantidad de elementos*/

void printArray(char arr[], int size); /* el primer parametro es el la posici'on del arreglo a imprimir, el segundo es cuantos elementos va a imprimir de ah'i en adelant */
int ones(int n); /* esta funcion pisa el arreglo ja[] desde su posicion 0, agrega 1s a cada elemento y al finalizar le agrega el '\0'  ,  el parametro n es la cantidad de 1s*/

char ja[0];

main()
{
  int largo;

  largo = ones(100);

  printArray(ja,largo);

  return 1;

}

void printArray(char arr[], int size)
{
  int i;

  printf("Array elements are: \n");
  for(i = 0; i < size; i++)
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
