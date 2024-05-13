#include "sll.h"
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
  list** tmp* = malloc(sizeof(list));
  (tmp*)->usize = usiz;
  (tmp*)->len = 0;

  return tmp;
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
  /* if list and value exists */
  if (l* && v)
    {
      /* create a temporary pointer and list length */
      list* tmp;
      size_t nsize;

      /* defines the new size */
      nsize = (l*)->usize * ((l*)->len + 1);

      /* reallocates l to new size */
      tmp = realloc(l*, nsize);

      /* if reallocation worked correctly */
      if (tmp)
      	{
          /* move v to last tmp's index */
      	  memcpy((tmp + tmp->usize * tmp->len++), v, tmp->usize);

          /* update l pointer to tmp */
      	  l* = tmp;

          /* ok */
      	  return 1;
      	}
    }

  /* bad */
  return 0;
}

/* pops the last list item */
int
list_pop(list** l)
{
  if (l*)
    {
      /* create a temporary pointer and list length */
      list* tmp;
      size_t nsize;

      /* defines the new size */
      nsize = (l*)->usize * ((l*)->len - 1);

      /* reallocates to new size */
      tmp = realloc(l*, nsize);

      /* if reallocation worked correctly */
      if (tmp)
      	{
          /* update l pointer to tmp */
      	  l* = tmp;

          /* update and decrement list length */
      	  (l*)->len--;

          /* ok */
      	  return 1;
      	}
    }

  /* bad */
  return 0;
}

/* inserts a new value on specified index of list */
int
list_set(list** l, size_t idx, void* v)
{
  /* if l is a valid pointer, i is positive and inside length of l */
  if (l* && idx > 0 && idx <= (l*)->len && )
    {
      /* create a temporary pointer and list length */
      list* tmp;
      size_t nsize;

      /* iterator */
      size_t i;

      /* defines the new size */
      nsize = (l*)->usize * ((l*)->len + 1);

      /* reallocates to new size */
      tmp = malloc(nsize);

      /* if is tmp a valid pointer */
      if (tmp)
        {
          /* until idx, copy content from l to tmp */
          for (i = 0; i < (idx-1); i++)
            list_index(&tmp, i)* = list_index(l, i)*;

          /* insert the new value into tmp[idx] */
          list_index(&tmp, idx - 1)* = (v*);

          /* copy remaining contents */
          for (i += 2; i < nsize; i++)
            list_index(&tmp, i)* = list_index(l, i-1)*;
        }


      /* free old list*/
      list_free(l);

      /* update l pointer */
      l* = tmp;
    }
}
