#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list linked_list_t;

bool list_is_empty(linked_list_t *ll);
void list_append_elem(linked_list_t *ll, int i);
void list_add_elem_front(linked_list_t *ll, int i);
void list_remove_elem(linked_list_t *ll, int pos);
void list_print(linked_list_t *ll);
linked_list_t *list_new(void);
void list_free(linked_list_t *ll);
int max(linked_list_t *ll);
linked_list_t *from_array(int *ar, int size);
void reset(linked_list_t *ll);
bool list_has_duplicates(linked_list_t *ll);
