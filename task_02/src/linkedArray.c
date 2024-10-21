#include <stdio.h>
#include <stdlib.h>

#include "linkedArray.h"

//declaration of static func
void write_data_to_item(char* ptr_item, char* ptr_data, size_t size_data);
// global func
Struct_list* CreateList(void)
{
	Struct_list* list = malloc(sizeof(Struct_list));
	
	// check allocation
	if(list == NULL)
		return NULL;

	// init list
	list->struct_data = NULL;
	list->struct_size = 0;
	list->item_count = 0;

	return list;
}


int AppendList(Struct_list *list, void*data, size_t data_size)
{
	// check input
	if(list == NULL)
		return -1;

	if (data == NULL)
		return -1;

	// check data size for not empty list
	if (list->item_count != 0 && list->struct_size != data_size)
	{
		printf("Error size of new item \n");
		return -1;
	}
	
	// append
	// if it first item
	if(list->item_count == 0)
	{
		list->struct_data = malloc(data_size);
		
		if (list->struct_data == NULL)
			return -1;
		write_data_to_item((char*)list->struct_data, (char*)data, data_size);
		list->item_count++;
		list->struct_size = data_size;
	}
	else
	{
		list->item_count++;
		list->struct_data = realloc(list->struct_data,
			       	list->struct_size *list->item_count);
		// to shift to end of data array
		size_t offset_to_end = (list->item_count - 1) * list->struct_size;
		char *ptr_to_end = (char*)list->struct_data + offset_to_end;
		
		write_data_to_item(ptr_to_end, (char*)data, data_size);
	}
	return 0;
}

int FreeList(Struct_list *list)
{
	if (list == NULL)
		return -1;
	
	free(list->struct_data);
	free((void*)list);
	return 0;
}

void* GetDataItemFromList(Struct_list *list, int index)
{
	// check input
	if (list == NULL)
		return NULL;
	if (index > (list->item_count - 1) || index < 0)
		return NULL;
	
	char* ptr_to_searched_data = (char*)list->struct_data + (list->struct_size * index);
	return (void*)ptr_to_searched_data;
}

int FindDataInList(Struct_list *list, void*searched_struct)
{
	//check input
	if (list == NULL)
		return -1;
	// nothing to find
	if (searched_struct == NULL)
		return -1;

	int i_list = 0;
	for (; i_list < list->item_count; i_list++)
	{
		char *ptr_to_item = (char*)list->struct_data+ (list->struct_size * i_list);
		size_t i_item = 0;
		char* ptr_data = (char*)searched_struct;
		for(; (i_item < list->struct_size) && (*ptr_to_item == *ptr_data);
			       	i_item++, ptr_data++, ptr_to_item++){}
		
		// if match find
		if(i_item == list->struct_size)
			return i_list;
	}
	return -2; // incorrect val
}
int DeleteItemInList(Struct_list *list, int index)
{
	if (list == NULL)
		return -1;
	if (index > (list->item_count - 1) || index < 0)
		return -1;
	// last element erase just from realloc
	if (index < (list->item_count - 1))
	{
		char* ptr_to_erase = (char*)list->struct_data + (list->struct_size * index);
	
		// source pointer to write
		char* ptr_to_write = (char*)list->struct_data + (list->struct_size * (index + 1));
		// count of data to write
		size_t write_size = (list->item_count - (index + 1)) * list->struct_size; 
		write_data_to_item(ptr_to_erase, ptr_to_write, write_size);
	}
	void* tmp = realloc(list->struct_data, list->item_count - 1);

	// check realloc res
	if (tmp == NULL )
		return -1;

	list->struct_data = tmp;
	list->item_count--;

	return 0;
}

int PrintList(Struct_list *list)
{
	if (list == NULL)
		return -1;

	printf("List contain:\n");
	for(int i_list = 0;i_list < list->item_count; i_list++)
	{
		char *ptr_to_item = (char*)list->struct_data+ (list->struct_size * i_list);
		printf("\t{%d}:", i_list);

		for(size_t i_item = 0; i_item < list->struct_size; i_item++)
			printf(" [0x%x]",*(ptr_to_item + i_item));
		printf("\n");
	}
	return 0;
}
// definition of static func
void write_data_to_item(char* ptr_item, char* ptr_data, size_t size_data)
{
	for(size_t i = 0; i < size_data; i++)
	{
		*(ptr_item) = *(ptr_data);
		ptr_item++;
		ptr_data++;
	}
}
