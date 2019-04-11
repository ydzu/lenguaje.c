#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct canvas{
  int size;
  int **filas;
};

struct canvas createCanvas(int size);
void printCanvas(struct canvas canvasToPrint);
struct canvas drawCross(int x, int y, int distance, struct canvas canvasForCross);
int* drawLine(int x1, int y1, int x2, int y2, int *canvasForDrawing);
struct canvas drawCircle(int x, int y, int ratio, struct canvas canvasForCircle);



main(){
  int i, k;

  struct canvas theCanvas;
  theCanvas = createCanvas(84);
  printf("%i\n", theCanvas.filas[2][4]);
  drawCross(2,2,8,theCanvas);   //podría hacer que cuando se haga una nueva forma geometrica Cross o Circle se guarde en un puntero asi des[ués se pueden rotar por ej
  drawCross(62,55,8,theCanvas);

  for(i=0;i<30;i=i+3){
    drawCross(i+28,i+20,8+(0.6*i),theCanvas);
  }

  for(i=0;i<22;i=i+3){
    k=2*(i/4);
    if (k>6){
      k=6;
    }
    drawCircle(i*2+2,i*2+20,k,theCanvas);
  }
  drawCross(2,16,8,theCanvas);
  drawCross(19,20,8,theCanvas);
  drawCross(10,10,11,theCanvas);
  drawCircle(5,5,5,theCanvas);
  drawCircle(65,25,15,theCanvas);
  drawCircle(56,5,2,theCanvas);
  drawCircle(3,55,22,theCanvas);
  drawCircle(60,40,10,theCanvas);
  printCanvas(theCanvas);

  return 0;
}


struct canvas createCanvas(int size){

  int **filas, *columnas, i, j, k=0;
  struct canvas canvasForExport;

  filas = (int**)malloc ((size) * sizeof(int*));
  for(i=0;i<size;i++){
    columnas = (int*)malloc ((size) * sizeof(int));
    printf("\n");
    filas[i]=columnas;
    for(j=0;j<size;j++){
      columnas[j]=k;
      printf("%i ", k);
    }
  }
  printf("\n%i ", *(columnas));
  printf("%i\n",*(*(filas+1)+3));

  canvasForExport.size = size;
  canvasForExport.filas = filas;

  return canvasForExport;
}


void printCanvas(struct canvas canvasToPrint){
  int i,j;

  for (i=0; i<canvasToPrint.size; i++){
    for (j=0; j<canvasToPrint.size; j++){
      if(canvasToPrint.filas[i][j]==0){                        // si el valor es 0 entonces imprime "-"
        printf("- ");
      }
      else if(canvasToPrint.filas[i][j]>9){                     // si el valor es mayor a 9 entonces imprime "X"
        printf("X ");
      }
      else{
        printf("%d ",canvasToPrint.filas[i][j]);
      }
    }
    printf("\n");
  }

}


struct canvas drawCross(int x, int y, int distance, struct canvas canvasForCross){   // le pasas coordenadas, tamano y canvas y dibuja una cruz
  int i;

  canvasForCross.filas[x][y]=(canvasForCross.filas[x][y])+1;  //acá sumamos 1 al punto del centro

  for (i=1; i<distance && i<(canvasForCross.size)-x; i++){            //acá crece en una de las cuatro direcciones por cada for
    canvasForCross.filas[x+i][y]=(canvasForCross.filas[x+i][y])+1;
  }
  for (i=1; i<distance && i<(canvasForCross.size)-y; i++){
    canvasForCross.filas[x][y+i]=(canvasForCross.filas[x][y+i])+1;
  }
  for (i=1; i<distance && i<=x; i++){
    canvasForCross.filas[x-i][y]=(canvasForCross.filas[x-i][y])+1;
  }
  for (i=1; i<distance && i<=y; i++){
    canvasForCross.filas[x][y-i]=(canvasForCross.filas[x][y-i])+1;
  }
  return canvasForCross;

}

struct canvas drawCircle(int x, int y, int ratio, struct canvas canvasForCircle){   // le pasas coordenadas, tamano y canvas y dibuja una cruz
  int i,j;

  canvasForCircle.filas[x][y]=(canvasForCircle.filas[x][y])+1;

  for (i=0; i<canvasForCircle.size; i++){
    for (j=0; j<canvasForCircle.size; j++){
      if(sqrt((double)(((i-x)*(i-x))+((j-y)*(j-y)))>(ratio) && sqrt((double)((i-x)*(i-x))+((j-y)*(j-y)))<(ratio+0.8))){                        // si el valor es 0 entonces imprime "-"
        canvasForCircle.filas[i][j]++;
      }
    }
  }

  return canvasForCircle;

}
