#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

  int **filas, *columnas, i, j, k=0, size;

  size=10;

  filas = (int**)malloc ((size) * sizeof(int*));
  for(i=0;i<size;i++){
    columnas = (int*)malloc ((size) * sizeof(int));
    printf("\n");
    *filas=columnas;
    for(j=0;j<size;j++){
      *columnas=k;
      columnas++;
      k++;
      printf("%i ", k);
    }
    filas++;
  }
  filas=filas-size;

  columnas = columnas+10;

  //USAR SINTAXIS DE ARRAYS CON LOS PUNTEROS PARA LOS QUE HICE MALLOS filas[]

  printf("\n%i ", *(columnas));
  printf("%i\n",*(*(filas+1)+3));

  return 0;
}
