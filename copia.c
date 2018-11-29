/* copiador */

#include <stdio.h>

int main()
{
	int c;
	int nc;

	nc = 0;


	while ((c = getchar()) != '\n'){
		putchar(c);
		printf("\n%d\n", nc);
		++nc;
	}

}
