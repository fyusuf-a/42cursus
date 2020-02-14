/*#include "ft_printf.h"*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

int		i = 8;
int n = 7;

int		main()
{
	printf("d = %5.0f\n", 25.0);

	printf("d = %-05.0f\n", 25.0);

	/*printf("i=%lli\n", (long long)-1);

	printf("Strange stuff about pointers\n");

	printf("%3p\n", &i); //"0x1243138901 (no additional width)

	printf("Strange stuff about strings\n");

	printf("\"%.s\"\n", "lorette"); //""
	
	printf("\"%.0s\"\n", "lorette"); //""

	printf("\"%.2s\"\n", "lorette");  //"lo"

	printf("\"%5.s\"\n", "lorette"); //"    "

	printf("\"%5.2s\"\n", "lorette"); //"   lo"

	//Strange stuff about ints
	printf("Strange stuff about ints\n");

	printf("%.d\n", 0); //""
	printf("%.d\n", 5); //"5"

	printf("%.*d\n", 0, 0); //""
	printf("%.*d\n", 0, 3); //"3"

	printf("%.*d\n", -15, 0); //"0"
	printf("%.*d", -15, 3); //"3"*/

	return (0);
}
