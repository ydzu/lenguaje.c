#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

  int **filas, *columnas, i, j, k=0, size;

  size=10;

  filas = (int**)malloc ((size) * sizeof(int*));
  columnas = (int*)malloc ((size*size) * sizeof(int));

  for(i=0;i<size;i++){

    filas=&columnas;
    for(j=0;j<size;j++){
      *columnas=k;
      k++;
      printf("%i\n", *columnas);
      columnas++;
    }
    filas++;

  }

  filas = filas-size;
  columnas = columnas-(size*size);


  printf("%i\n",*(columnas+10));
  printf("%i\n",**(filas));


  return 0;
}
