#include <stdio.h>
#include <stdlib.h>

char* arrayGen(char charToRepeat, int howManyTimes); //consulta qué char querés repetir y cuántas veces. y devuelve un apuntador a ese arreglo
void printer(char *firstPrintingPosition); //imprime un arreglo de caracteres
void progres();
int* createCanvas();
void printCanvas(int *ptrToCanvas);


main()
{
  arrayGen('R',10);
  progres();
  printCanvas(createCanvas());

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

void printer(char *r){
  int i;

  printf("Concatenated results: ");
  for(i=0; *r != '\0'; i++){ //imprimo r1
    printf("%c", *r);
    r++;
  }
  printf("\n");
  r = r-i;
}

void progres(){
  int i, w=30;

  for(i=0; i < w ; i++){

    if(i%2==1)
      arrayGen('D',i);
    else
      arrayGen('d',i);

  }
}

int* createCanvas(){
  int i,j,a=10,b=10,canvas[a][b];
  int *ptrCanvas;
  ptrCanvas = malloc(sizeof(int[a][b]));
  ptrCanvas = &canvas[0][0];

  for (i=0; i<10; i++){
    for (j=0; j<10; j++){
      canvas[i][j]=0;
    }
  }
  canvas[0][0]=1;


  return ptrCanvas;
}

void printCanvas(int *g){
  int i,j;
  int *a;
  a=g;

  for (i=0; i<10; i++){
    for (j=0; j<10; j++){
      printf("%d", *a;
      a++;
    }
    printf("\n");
  }



}
