#include <string.h>

#include "genericLineFind.h"

#define TEST_CHAR_ARRAY_MSG "\tFIND \'%c\': [%d]\n"
#define TEST_INT_ARRAY_MSG "\tFIND %d:[%d]\n"
#define TEST_DOUBLE_ARRAY_MSG "\tFIND %f:[%d]\n"

int main(void)
{
	// test char array
	char test_string[] = "some string";
	size_t string_len = strlen(test_string);
	printf("FIND in char array \"%s\":\n",test_string);
	printf(TEST_CHAR_ARRAY_MSG ,'o',
			FIND((char*)&test_string[0], string_len, 'o'));

	printf(TEST_CHAR_ARRAY_MSG,'g',
			FIND((char*)&test_string[0], string_len, 'g'));

	printf(TEST_CHAR_ARRAY_MSG, 'a',
			FIND((char*)&test_string[0], string_len, 'a'));

	// test for int array
	int int_arr[] = {1, 2, -3, 4, 5, 6, 7};
	printf("FIND in int array");
	for(size_t i = 0; i < (sizeof(int_arr) / sizeof(int)); i++)
		printf(" [%d]", int_arr[i]);
	printf(":\n");

	printf(TEST_INT_ARRAY_MSG, -3,
		FIND((int*)&int_arr[0], sizeof(int_arr) / sizeof(int), -3));
	printf(TEST_INT_ARRAY_MSG, 7,
		FIND((int*)&int_arr[0], sizeof(int_arr) / sizeof(int), 7));
	printf(TEST_INT_ARRAY_MSG, 10,
		FIND((int*)&int_arr[0], sizeof(int_arr) / sizeof(int), 10));

	// test for double array
	double double_arr[] = {1.0, 2.0, 3.0, 4.5, 3.14};
	printf("FIND in double array");
	for(size_t i = 0; i < (sizeof(double_arr) / sizeof(double)); i++)
		printf(" [%f]", double_arr[i]);
	printf(":\n");

	printf(TEST_DOUBLE_ARRAY_MSG, 1.0,
		FIND((double*)&double_arr[0], sizeof(double_arr) / sizeof(double), 1.0));
	printf(TEST_DOUBLE_ARRAY_MSG, 3.14,
		FIND((double*)&double_arr[0], sizeof(double_arr) / sizeof(double), 3.14));
	printf(TEST_DOUBLE_ARRAY_MSG, -1.23,
		FIND((double*)&double_arr[0], sizeof(double_arr) / sizeof(double), -1.23));


	// unknown type
	typedef struct {int a; int b;} some_struct;
	some_struct test_struct = {10, 11};

	// others arg of func with unknown type doesn't metter
	FIND(&test_struct, 13, 14);
	return 0;
}
