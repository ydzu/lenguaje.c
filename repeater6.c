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
int randomNumber(int min_num, int max_num, int seed);
struct canvas bubbleCreator(int circlesToFit, int maxDiameter, int minDiameter, struct canvas canvasForBubbles);



main(){
  struct canvas theCanvas;
  theCanvas = createCanvas(84);
  drawCircle(60,20,40,theCanvas);
  drawCircle(60,20,180,theCanvas);
  drawCircle(60,20,520,theCanvas);
  drawCircle(20,50,40,theCanvas);
  drawCircle(20,50,180,theCanvas);
  drawCircle(20,50,520,theCanvas);
  bubbleCreator(12,30,80,theCanvas);
  printCanvas(theCanvas);

  return 0;
}


struct canvas createCanvas(int size){

  int **filas, *columnas, i, j, k=0;
  struct canvas canvasForExport;

  filas = (int**)malloc ((size) * sizeof(int*));
  for(i=0;i<size;i++){
    columnas = (int*)malloc ((size) * sizeof(int));
    filas[i]=columnas;
    for(j=0;j<size;j++){
      columnas[j]=k;
    }
  }

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
      if(sqrt((double)(((i-x)*(i-x))+((j-y)*(j-y)))<(ratio)) && sqrt((double)(((i-x)*(i-x))+((j-y)*(j-y)))>(ratio-(0.5*ratio)))){                        // si el valor es 0 entonces imprime "-"
        canvasForCircle.filas[i][j]++;
      }
    }
  }

  return canvasForCircle;
}

struct canvas bubbleCreator(int circlesToFit, int maxDiameter, int minDiameter, struct canvas canvasForBubbles){
  int count=0,i,j,*x1,*y1,random, *list, **filasPuntos, seed = time(NULL);;

  list = (int*)malloc ((circlesToFit) * sizeof(int));
  x1 = (int*)malloc ((circlesToFit) * sizeof(int));
  y1 = (int*)malloc ((circlesToFit) * sizeof(int));

  for(i=0; count<circlesToFit; i++){
    x1[i]=randomNumber(0,canvasForBubbles.size,seed);
    y1[i]=randomNumber(0,canvasForBubbles.size,seed);
    canvasForBubbles.filas[x1[i]][y1[i]]=4;
    drawCircle(x1[i],y1[i],maxDiameter,canvasForBubbles);
    count++;

      //el random pont podría ser una estructura
      /*
    for(j=0;j){           //aca la idea es que verifique si todos los puntos ya creados están ok, esto se va almacenando en list
      if((randomPointDistToOther/2)>)   //pensar en un booleano para saber sio llego al final de list o no*/
  }
    //acá ponemos un if para verificar si el booleano nos da OK. Si es así entonces crea el circulo, disminuye el radio del próximo circulo, y aumenta i++

          //elijo una posición en canvasForBubbles con x e y random
    //si este no choca con otro circulo
      //creo un circulo con max maxDiameter
      //aumento 1 el contador de circulos

  return canvasForBubbles;
}

int randomNumber(int min_num, int max_num,int seed)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(seed);
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

/*
  random = rand()/10;
  printf("%f\n", random);
*/
