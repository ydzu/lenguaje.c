#include <stdio.h>
#include <stdlib.h>

int* createCanvas();                    //crea un array 2D y devuelve un puntero que apunta a su primer posición
void printCanvas(int *ptrToCanvas);     //le pasas un puntero a array 2D y lo imprime


main()
{
  printCanvas(createCanvas());
  return 0;
}


int* createCanvas(){
  int i,j;
  int canvas[10][10]={0};
  int *ptrCanvas, *copyCanvas;

  ptrCanvas = (int*)malloc (100 * sizeof(int)); //como no podía acceder al array 2D desde printCanvas, hice esto por si era un problema de memoria
  ptrCanvas = &canvas[0][0]; //apunto a la primer posición del array 2D
  copyCanvas = ptrCanvas;

  for (i=0; i<10; i++){        //para asegurarme de que estoy manipulando bien el array 2D hice esto. FUNCIONA BIEN
    for (j=0; j<10; j++){
      canvas[i][j]=3;
    }
  }

  canvas[0][0]=1;  //también para asegurarme de que las posiciones funcionan OK. FUNCIONA BIEN
  canvas[1][1]=1;
  canvas[4][6]=1;

  for (i=0; i<10; i++){               //como no puedo hacer esto mismo desde printCanvas() lo hice acá con el ptr y FUNCIONA BIEN
    for (j=0; j<10; j++){
      printf("%d",*ptrCanvas);
      ptrCanvas++;
    }
    printf("\n");
  }

  return copyCanvas;
}

void printCanvas(int *a){
  int i,j;
                                  // NO PUEDO ACCEDER AL ARRAY 2D DE NINGUNA MANERAAA. NO SE QUÉ ESTOY HACIENDO MAL
  for (i=0; i<10; i++){          //  lrpm acá es donde nada funciona. solamente me da bien la primer posición del puntero. a partir de la segunda da valore random
    for (j=0; j<10; j++){
      printf("%d",*(a + (i * 10 + j)));  //itenté acceder de esta forma con ROW y COLUMN. también intenté moviendo el ptr *a de forma lineal.
    }
    printf("\n");
  }

}
