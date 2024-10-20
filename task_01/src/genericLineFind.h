#include <stdio.h>
#ifndef GENERIC_LINE_FIND_H_

#define GENERIC_LINE_FIND_H_

int findInCharArray(char* array, size_t n, char find_c);
int findInIntArray(int* array, size_t n, int find_c);
int findInDoubleArray(double* array, size_t n, double searched);
int unknownType(...);

#define FIND(PTR_ARRAY, ARRAY_SIZE, SEARCHED_ELEMENT) _Generic((PTR_ARRAY),\
		char*: findInCharArray,\
		int*:findInIntArray,\
		double*:findInDoubleArray,\
		default: unknownType\
		)(PTR_ARRAY, ARRAY_SIZE, SEARCHED_ELEMENT)


#endif

