#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
#define MAXIMOIMPRESION 30
/* En esta version vamos a reservar 100 posiciones para ja[] y con la función ones vamos a ir agregandole elementos y modificando su largo*/

void printArray(char arr[]);
int in(int n, char s); /* acá la idea es que s sea el char a repetir n veces .. y lo imprime*/
void freeEnd(int n); /* esto libera n posiciones de atrás para adeltante*/
void freeStart(int n); /*esto libera n posiciones desde el principio*/
void alterno(int n, int m);

char ja[SIZE];  /*acá estoy reservando SIZE posiciones*/
char *indice = ja;
char *principio = ja;
char *multi = ja;


main()
{
  int i, renglones=20;
  in(41, 2); /* acá comprobamos que por ser mayos a 40 no entra*/

  /*
  for(i=0;i<renglones;i++){   /* acá vamos a ingresar chars para cana posición*/
    in(1, 4);
    in(1, 20);
    in(400, 4); /* acá comprobamos que no entra en el espacio restante*/
    printArray(ja);
    printf("\n");
  }
  */

  freeEnd(0);
  freeStart(0);
  alterno(10, 20);
  /* *principio = *(principio+20);    /// comprobación de freeStart()*/
  return 1;
}

/*Imprime un array de máximo 80 caracteres. Como creo una variable numero*/
////////////////////////////////////////////////////////////////////////////////
void printArray(char arr[])
{
  int i, maximoLargo = MAXIMOIMPRESION;
  char *numero = (ja+200);
  char *cortador = (ja+maximoLargo);
  *cortador = '\0';

  if((indice-ja)<=MAXIMOIMPRESION){
    printf("Array n%d\n",*numero);
  }
  else{
    printf("Array n%d (impresión parcial)\n",*numero);
  }

  for(i = 0; arr[i] != '\0'; i++)
  {
      printf("%d, ", arr[i]);
  }
  printf("\n");
  *numero = (*numero+1);
}


////////////////////////////////////////////////////////////////////////////////

/*in(int n, char s) genera un array de n po*/

int* ones(int n)
{
  int i;
  int *p;
  p = (int*) malloc(100 * sizeof(int));
  for (i=0; i<n; i++){ /*el for completa el ja[] desde su posición 0 */
    *p = 1;
    p++;
  }

  return p;
}

////////////////////////////////////////////////////////////////////////////////

void freeEnd(int n)
{
  indice -= n;
  *indice = '\0';

}

////////////////////////////////////////////////////////////////////////////////

void freeStart(int n)
{
  int i,largo;
  char j;

  largo = indice-ja;
  /*printf("El largo de ja es: %d\n", largo);*/

  for (i=0; i<=largo; i++){
    *principio = *(principio+n);
    principio++;
  }
}

////////////////////////////////////////////////////////////////////////////////

void alterno(int n, int s)
{
  int i;
  for (i=0; i<n; i++){ /*el for completa el ja[] desde su posición 0 */
    *multi = s;
    multi = multi+2;
    s++;
  }
}

////////////////////////////////////////////////////////////////////////////////
/* PARA LA VERSI'ON CON MALLOC, CONCEPTUALMENTE CREO QUE SER'IA INICIALIZAR EL JA CON UN ESPACIO GRANDE Y PODER GUARDAR AH'I LA CANTIDAD DE 1S QUE SEA NECESARIA
*/
