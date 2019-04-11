#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 80

int* createCanvas();
void printCanvas(int *ptrToCanvas);
int* drawCross(int x, int y, int distance, int *canvasForDrawing);
int* drawLine(int x1, int y1, int x2, int y2, int *canvasForDrawing);


main(){
  int *paso, i, j;

  paso=createCanvas();
  /*
  drawCross(4,4,8,paso);
  drawCross(15,19,2,paso);
  drawCross(38,38,8,paso);
  drawCross(8,4,12,paso);
  drawCross(12,13,12,paso);
  drawCross(23,20,6,paso);
  printCanvas(paso);
  */


  for (i=0; i<32; i++){
    drawCross(i*2,i*2,i,paso);
    //drawCross(SIZE-(i*2),i*2,i,paso);
    drawCross(i*2,SIZE-(i*2),i,paso);
    drawCross(SIZE-(i*2),SIZE-(i*2),i,paso);
  }


  drawLine(4,4,2,8,paso);

  printCanvas(paso);



  return 0;
}


int* createCanvas(){
  int i,j;
  int canvas[SIZE][SIZE]={0};
  int *ptrCanvas;

  ptrCanvas = (int*)malloc ((SIZE*SIZE) * sizeof(int));

  for (i=0; i<SIZE; i++){
    for (j=0; j<SIZE; j++){
      *ptrCanvas = canvas[i][j];
      ptrCanvas++;
    }
  }

  ptrCanvas = ptrCanvas-(SIZE*SIZE);
  *(ptrCanvas+5) = 12;

  return ptrCanvas;
}

void printCanvas(int *a){   //el print imprime el puntero y deduce la cantidad a imprimir con el SIZE
  int i,j;

  for (i=0; i<SIZE; i++){
    for (j=0; j<SIZE; j++){
      if(*a==0){                        // si el valor es 0 entonces imprime "-"
        printf("-");
      }
      else if(*a>9){                     // si el valor es mayor a 9 entonces imprime "X"
        printf("X");
      }
      else{
        printf("%d",*a);
      }
      a++;
    }
    printf("\n");
  }

}

int* drawCross(int x, int y, int distance, int *a){   // le pasas coordenadas, tamano y canvas y dibuja una cruz
  int i, j;
  int canvas[SIZE*2][SIZE*2];    //acá reservé el doble de lugar para no tener problemas de Segmentation fault 11

  for (i=0; i<SIZE; i++){         //convertimos el puntero a array 2D para poder trabajar comodo con coordenadas
    for (j=0; j<SIZE; j++){
      canvas[i][j] = *a;
      a++;
    }
  }
  a = a-(SIZE*SIZE);

  canvas[x][y]=(canvas[x][y])+1;  //acá sumamos 1 al punto del centro
  for (i=1; i<distance; i++){     //esto es para armar la cruz. crece en las cuatro direcciones hasta que llega al parametro distancia
    if(x+i>SIZE){                 //esto es para evitar Segmentation fault 11.  No va a agregar valores en fuera del array 2D
      break;
    }
    canvas[x+i][y]=(canvas[x+i][y])+1;
    canvas[x][y+i]=(canvas[x][y+i])+1;
    canvas[x-i][y]=(canvas[x-i][y])+1;
    canvas[x][y-i]=(canvas[x][y-i])+1;
  }

  for (i=0; i<SIZE; i++){
    for (j=0; j<SIZE; j++){
      *a = canvas[i][j];
      a++;
    }
  }

  a = a-(SIZE*SIZE);

  return a;

}



int* drawLine(int x1, int y1, int x2, int y2, int *a){   // le pasas coordenadas, tamano y canvas y dibuja una cruz
  int i, j;
  int alto, ancho;
  int canvas[SIZE][SIZE];

  for (i=0; i<SIZE; i++){         //convertimos el puntero a array 2D para poder trabajar comodo con coordenadas
    for (j=0; j<SIZE; j++){
      canvas[i][j] = *a;
      a++;
    }
  }
  a = a-(SIZE*SIZE);
/*
  ancho = abs(x1-x2);
  largo = abs(y1-y2);


  hacer acá la linea
  */

  printf("%i\n", ancho);

  canvas[x1][y1]=(canvas[x1][y1])+1;  //acá sumamos 1 al punto del centro


  for (i=0; i<SIZE; i++){
    for (j=0; j<SIZE; j++){
      *a = canvas[i][j];
      a++;
    }
  }

  a = a-(SIZE*SIZE);

  return a;

}
