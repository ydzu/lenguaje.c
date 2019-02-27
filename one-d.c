#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
/* En esta version vamos a reservar 100 posiciones para ja[] y con la función ones vamos a ir agregandole elementos y modificando su largo*/

void printArray(char arr[]);
int in(int n, char s); /* acá la idea es que s sea el char a repetir n veces .. y lo imprime*/
void freeEnd(int n); /* esto libera n posiciones de atrás para adeltante*/
void freeStart(int n); /*esto libera n posiciones desde el principio*/
void alterno(int n, int m);

char ja[SIZE]; /* acá estoy reservando SIZE posiciones*/
char *indice = ja;
char *principio = ja;
char *multi = ja;

///BUSCAR LA FORMA DE HACERLO CON MALLOC Y FREE// /////



main()
{
  int i, renglones=20;

  for(i=0;i<renglones;i++){   /* acá vamos a ingresar chars para cana posición*/
    int* a = in(101, 2); /* acá comprobamos que por ser mayos a 100 no entra*/
    in(1, 20);
    in(1, 30);
    in(400, 4); /* acá comprobamos que no entra en el espacio restante*/
    freeEnd(0);
    freeStart(0);
    alterno(20, 11);
    printArray(ja);
    printf("\n");
  }
  /* *principio = *(principio+20);    /// comprobación de freeStart()*/
  return 1;
}


/*Imprime un array de máximo 80 caracteres. Como creo una variable numero*/
////////////////////////////////////////////////////////////////////////////////
void printArray(char arr[])
{
  int i, maximoLargo = 80;
  char *numero = (ja+200);
  char *cortador = (ja+maximoLargo);
  *cortador = '\0';

  printf("Array n%d\n",*numero);
  for(i = 0; arr[i] != '\0'; i++)
  {
      printf("%d, ", arr[i]);
  }
  printf("\n");
  *numero = (*numero+1);
}


////////////////////////////////////////////////////////////////////////////////


int* in(int n, char s)
{
  int i,j=0;

  if (ja+SIZE-indice>=n){ /*si entra ///  acá no termino de entender la suma de ja + SIZE . estas sumas no afectan a los valores del array sino a su posición? */
    for (i=0; i<n; i++){ /*el for completa el ja[] desde su posición 0 */
      *indice = s;
      indice++;
      j++;
    }
  }
  else return 0;
  /*ja[i] = '\0';*/
  *indice = '\0';
  return indice;

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
