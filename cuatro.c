#include <stdio.h>

main() /* cuenta digitos, espacios blancos y otros caracteres*/
{
  int c, i, nwhite, nother, ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; i++)
    ndigit[i] = 0;
  while((c = getchar()) != EOF){
    switch(c){
    case'0':case'1':case'2':case'3':case'4':
    case'5':case'6':case'7':case'8':case'9':
      ndigit[c-'0']++;
      break;
    case' ':
    case'\n':
    case'\t':
      nwhite++;
      break;
    default:
      nother++;
      break;
    }
  }

  /*acá pense que al tener el break capaz el while se interrumpía después del primer caracter*/
  /*probé sacar todos los break. también dejar el break solamente en uno de los case, como para que cuando ingrese ese caracter se corte el while y pase al printf. pero ningún éxito*/


  printf("digitos=");
  for(i = 0; i<10;i++)
    printf("%d", ndigit[i]);
  printf(", espacios blancos = %d, otros = %d\n",
    nwhite, nother);
  return 0;
}
