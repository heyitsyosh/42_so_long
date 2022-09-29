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
	for (int i = 0; i++; i < 5)
	{
		*test = malloc(5);
		*test = "abcd";
		*test++;
	}
	while (test)
	{
		printf("1: %p\n", *test);
		*test++;
		printf("2: %p\n", *test);
		*test--;
		printf("3: %p\n", *test);
		printf("4: %p\n", *(test + 1));
		test++;
	}
	//didnt make a good test but just wanted to confirm that doing ++ moves by the datatype size
	//so hypothetically, i would have to (test + <size> * sizeof(whicheverdatatype))

	// 0x55b774877004
	// 0x55b77487700c
	// so a difference of 8 bits. 
}
