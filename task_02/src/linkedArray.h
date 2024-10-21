#ifndef LINKED_ARRAY_H

#define LINKED_ARRAY_H

typedef struct 
{
	size_t struct_size; // size of one item of structure
	int item_count; // count of item...need to restrict to int
	void *struct_data; // pointer to data of structure
}Struct_list;

Struct_list* CreateList();
int AppendList(Struct_list *list, void*data, size_t data_size);
int FreeList(Struct_list *list);

int PrintList(Struct_list *list);

void* GetDataItemFromList(Struct_list *list, int index);
int FindDataInList(Struct_list *list, void*searched_struct);

int DeleteItemInList(Struct_list *list, int index);
#endif

