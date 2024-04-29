#include <sll.h>
#include <stdlib.h>

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
list**
list_new(size_t usiz)
{
  list* tmp = malloc(sizeof(list));
  tmp->usize = usiz;
  tmp->len = 0;

  return &tmp;
}

/* frees the specified list */
void
list_free(list** l)
{
  if (l*)
    {
      free((l*)->index);
      free(l*);
    }
}

/* appends a new item to the list */
int
list_append(list** l, void* v)
{
  if (l* && v)
    {
      list* tmp;
      size_t nsize;

      nsize = (l*)->usize * ((l*)->len + 1);
      tmp = realloc(l*, nsize);

      if (tmp)
	{
	  memcpy((tmp + tmp->usize * tmp->len++), v, tmp->usize);

	  l* = tmp;

	  return 1;
	}
    }

  return 0;
}

/* pops the last list item */
int
list_pop(list** l)
{
  if (l*)
    {
      list* tmp;
      size_t nsize;

      nsize = (l*)->usize * ((l*)->len - 1);
      tmp = realloc(l*, nsize);

      if (tmp)
	{
	  l* = tmp;
	  (l*)->len--;

	  return 1;
	}
    }

  return 0;
}

/* inserts a new value on specified index of list */
int
list_set(list** l, size_t i, void* v)
{
  if (l* && i > 0)
    {
      list* tmp;
      size_t nsize;

      nsize = (l*)->usize * ((l*)->len + 1);
      tmp = malloc(nsize);

      if (tmp)
        {

        }
    }
}
