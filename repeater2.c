#include <stdio.h>
#include <stdlib.h>

int* createCanvas();
void printCanvas(int *ptrToCanvas);


main()
{
  printCanvas(createCanvas());
  return 0;
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
