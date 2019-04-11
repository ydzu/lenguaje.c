#include <stdio.h>
#include <stdlib.h>

#define YMAX 30
#define XMAX 80

struct point{
  int x;
  int y;
};

struct rect{
  struct point pt1;
  struct point pt2;
};

struct point makepoint(int x, int y){  //makepoint es una func que solo funciona para stuct point ?
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
};

struct point addpoint(struct point p1, struct point p2){
  p1.x += p2.x;
  p1.y += p2.y;

  return p1;
};

int main(){

  struct rect screen;
  struct point middle;
  struct point makepoint(int, int);   // no entiendo para qué está esto. por qué no le paso valores directamente

  struct point testPt = {2,2};
  printf("Punto de test: %d,%d\n", testPt.x, testPt.y);

  screen.pt1 = makepoint(0,0);         //acá estamos creando el punto 0,0 que va a ser uno de los extremos del rect screen
  screen.pt2 = makepoint(XMAX, YMAX);   //acá creamos el otro extremo
  middle = makepoint((screen.pt1.x + screen.pt2.x)/2,    //acá calcula el valor medio entre los x de los pts //genera con esos dos puntos medios una estructura punto
                      (screen.pt1.y + screen.pt2.y)/2);  //acá lo mismo de los y

  printf("Los cuatro vertices de screen son: (%d,%d) ", screen.pt1.x, screen.pt1.y);
  printf("(%d,%d) ", screen.pt2.x, screen.pt1.y);
  printf("(%d,%d) ", screen.pt2.x, screen.pt2.y);
  printf("y (%d,%d)\n", screen.pt1.x, screen.pt2.y);
  printf("El centro es: (%d,%d)\n", middle.x, middle.y);


  //consulta a fefe: página 145 no entiendo como es el return
  //en el ejemplo de origin y *pp al final de la pagina 145 está haciendo un apuntador que apunta al stack? como el error que tuve la otra vez? eso es para usar el apuntador de forma local dentro del apuntador nada más?
  // **p
  return 0;
}
