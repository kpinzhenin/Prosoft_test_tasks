#include <stdio.h>

int findInCharArray(char* array, size_t n, char find_c)
{
	size_t i = 0;
	for(; (i < n) && ( *(array + i) != find_c); i++){}
//	printf("inside char func = %s, size = %lu, find = %c, array_num = %d\n", array, n, find_c, i);
	
	// if reache end of array and don't find searcheable 
	if(i == n && *(array + i) != find_c)
		i = -1;
	return i;
}

int findInIntArray(int* array, size_t n, int find_c)
{
	size_t i = 0;
	for(; (i < n) && ( *(array + i) != find_c); i++){}
//	printf("\ninside int func , size = %lu, find = %d, array_num = %d\n", n, find_c, i);

	// if reache end of array and don't find searcheable 
	if(i == n && *(array + i) != find_c)
		i = -1;
	return i;
}

int findInDoubleArray(double* array, size_t n, double searched)
{
	size_t i = 0;
	for(; (i < n) && ( *(array + i) != searched); i++){}
	//printf("\ninside double func , size = %lu, find = %f, array_num = %d\n", n, searched, i);

	// if reache end of array and don't find searcheable 
	if(i == n && *(array + i) != searched)
		i = -1;
	return i;
}

// not process any type other than those listed
int unknownType(...)
{
	printf("unknown type\n");
	return -2;
}

