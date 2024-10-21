#include <stdio.h>
#include <stdlib.h>

#include "linkedArray.h"

int main(void)
{
	Struct_list *list = CreateList();

	typedef struct {int a; int b; char c[4];} some_struct;

	int res = 0;
	res = AppendList(list,
		       	(void*)&(some_struct){.a = 1, .b = 2, .c = "tset"},
			sizeof(some_struct));
	if (res == -1) printf("Error to append...\n");

	res = AppendList(list,
		       	(void*)&(some_struct){.a = 3, .b = 4, .c = "asda"},
			sizeof(some_struct));
	if (res == -1) printf("Error to append...\n");
	
	res = AppendList(list,
		       	(void*)&(some_struct){.a = 5, .b = 6, .c = "ffff"},
			sizeof(some_struct));
	if (res == -1) printf("Error to append...\n");
	
	// test Find item of struct
	some_struct test_find = {.a=3, .b=4, .c="asda"};
	res = FindDataInList(list,(void*)&test_find);
	printf("index of item \"test_find\"=%d\n",res);

	// find to uncreate item (return -2)
	some_struct test_fail_find = {.a=1, .b=4, .c="asda"};
	res = FindDataInList(list,(void*)&test_fail_find);
	printf("index of item \"test_fail_find\"=%d\n",res);

	// test get item from index num
	void* getted_struct = GetDataItemFromList(list, 0);
	some_struct *get_some = (some_struct*)getted_struct;
	printf("struct i index [0] {.a=%d, .b=%d, .c=%s}\n", get_some->a, get_some->b, get_some->c);
	// check the link
	get_some->a = 8;
	// fail request (out of range)
	void *fail_get = GetDataItemFromList(list, 5);
	if (fail_get == NULL)
		printf("error get from index 5...\n");
	// fail request (out of range)
	fail_get = GetDataItemFromList(list, -1);
	if (fail_get == NULL)
		printf("error get from index -1...\n");

	// show list before del
	PrintList(list);
	DeleteItemInList(list,2);
	// show list after del
	PrintList(list);

	FreeList(list);

	return 0;
}
