#include <stdio.h>
#include <stdlib.h>

char* arrayGen(char charToRepeat, int howManyTimes); //consulta qué char querés repetir y cuántas veces. y devuelve un apuntador a ese arreglo
int* createCanvas();
void printCanvas(int *ptrToCanvas);


main()
{
  int* paso;
  arrayGen('R',10);

  paso=createCanvas();
  printCanvas(paso);

  return 0;
}

char* arrayGen(char c, int n){
  int i;
  char *p1;

  p1 = (char*)malloc (n * sizeof(int)); //reserva memoria según el largo que se ingresa en n

  printf("Array created: "); //va posición por posición n veces asignando el valor c, a su vez lo va imprimiendo
  for(i=0; i < n; i++){
    *p1 = c;
    printf("%c", *p1);
    p1++;
  }
  printf("\n\n");
  p1 = p1-n;

  return p1;
}

int* createCanvas(){
  int i,j;
  int canvas[10][10]={0};
  int *ptrCanvas, *copyCanvas;

  ptrCanvas = (int*)malloc (100 * sizeof(int));
  ptrCanvas = &canvas[0][0];
  copyCanvas = ptrCanvas;

  for (i=0; i<10; i++){
    for (j=0; j<10; j++){
      canvas[i][j]=3;
    }
  }

  canvas[0][0]=1;
  canvas[1][1]=1;
  canvas[4][6]=1;

  for (i=0; i<10; i++){
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

  for (i=0; i<10; i++){
    for (j=0; j<10; j++){
      printf("%d",*(a + (i * 10 + j)));
    }
    printf("\n");
  }

}
