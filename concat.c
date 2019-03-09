#include <stdio.h>
#include <stdlib.h>

char* arrayGen(); //consulta qué char querés repetir y cuántas veces. y devuelve un apuntador a ese arreglo
char* concat(char *firstPtrToConcatenate, char *secondPtrToConcatenate); //recibe dos arreglos de caracteres y los concatena
void printer(char *firstPrintingPosition); //imprime un arreglo de caracteres

main()
{
  printer(concat(arrayGen(),arrayGen()));
  return 0;
}

char* concat(char *p, char *q)
{
  int i, j=0, k=0;
  char *r1;

  for(i=0; *p != '\0'; i++){ //cuenta el largo de *p y lo guardo en j
    j++;
    p++;
  }
  p = p-j;

  for(i=0; *q != '\0'; i++){ //cuenta el largo de *q y lo guardo en k
    k++;
    q++;
  }
  q = q-k;

  r1 = (char*)malloc ((j+k) * sizeof(int)); //reserva memoria para el nuevo puntero a array de caracteres. que es el largo de p + q

  for(i=0; i < j; i++){ //hace que la primer parte de r1 sea p
    *r1 = *p;
    r1++;
    p++;
  }
  p = p-j;

  for(i=0; i < k; i++){ //hace que la segunda parte de r1 sea q
    *r1 = *q;
    r1++;
    q++;
  }
  q = q-k;
  r1 = r1-(j+k);

  return r1;
}

char* arrayGen(){
  int n, i;
  char c, *p1;

  printf("Char to repeat?\n"); //consulta que char quiere repetir
  scanf("%s", &c);
  printf("How many times?\n"); //consulta cuantas veces
  scanf("%d", &n);

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
