#ifndef SLL_H
#define SLL_H

#define list_index(listpp, idx)       \
  ((listpp*) + (listpp*)->usize * (idx))

/* list structure definition */
typedef struct list_ list;

/* returns a recently created list */
list**
list_new(size_t);

/* frees the specified list */
void
list_free(list**);

/* appends a new item to the list */
int
list_append(list**, void*);

/* pops the last list item */
int
list_pop(list**);

/* inserts a new item on specified index of list */
int
list_set(list**, size_t, void*);

/* deletes the specified index of list */
int
list_del(list**, size_t);

#endif /* SLL_H */
