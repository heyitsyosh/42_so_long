#include <stdio.h>
#include <stdlib.h>

// int main()
// {
// 	char **test;

// 	test = malloc(sizeof(char *) * 5);
// 	while (test)
// 	{
// 		*test = malloc(5);
// 		printf("%p\n", test);
// 		*test++;
// 		printf("%p\n", test);
// 	}
// }

int main()
{
	char **test;

	test = malloc(sizeof(char *) * 5);
	*test = malloc(5);
	while (*test)
	{
		*test = malloc(5);
		printf("%p\n", *test);
		*test++ = malloc(3);
		*test = "ab";
		*test--;
		printf("%p\n", *(test + 1));
		*test++;
	}
	//didnt make a good test but just wanted to confirm that doing ++ moves by the datatype size
	//so hypothetically, i would have to (test + <size> * sizeof(whicheverdatatype))
}
