#include <sll.h>

struct list_
{
  /* The whole list length */
  size_t len;

  /* The size of each unit inside list */
  size_t usize;

  /* The list itself and his values */
  void* index;
};

/* list structure definition */
list*
list_new(size_t usiz)
{
  list* tmp = malloc(sizeof(list));
  tmp->usize = usiz;
  tmp->len = 0;

  return tmp;
}

/* frees the specified list */
void
list_free(list* l)
{
  if (l)
    {
      free(l->index);
      free(l);
    }
}

/* appends a new item to the list */
int
list_append(list* l, void* v)
{
  if (l && 
}
