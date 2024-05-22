#include "sll.h"
#include <stdlib.h>
#include <string.h>

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
  list** tmp;
  *tmp = malloc(sizeof(list*));
  (*tmp)->usize = usiz;
  (*tmp)->len = 0;

  return tmp;
}

/* frees the specified list */
void
list_free(list** l)
{
  if (*l)
    {
      free((*l)->index);
      free(*l);
    }
}

/* appends a new item to the list */
int
list_append(list** l, void* v)
{
  /* if list and value exists */
  if (*l && v)
    {
      /* create a temporary pointer and list length */
      list* tmp;
      size_t nsize;

      /* defines the new size */
      nsize = (*l)->usize * ((*l)->len + 1);

      /* reallocates l to new size */
      tmp = realloc(*l, nsize);

      /* if reallocation worked correctly */
      if (tmp)
      	{
          /* move v to last tmp's index */
      	  memcpy((tmp + tmp->usize * tmp->len++), v, tmp->usize);

          /* update l pointer to tmp */
          *l = tmp;

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
  if (*l)
    {
      /* create a temporary pointer and list length */
      list* tmp;
      size_t nsize;

      /* defines the new size */
      nsize = (*l)->usize * ((*l)->len - 1);

      /* reallocates to new size */
      tmp = realloc(*l, nsize);

      /* if reallocation worked correctly */
      if (tmp)
      	{
          /* update l pointer to tmp */
          *l = tmp;

          /* update and decrement list length */
          (*l)->len--;

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
  if (*l && idx > 0 && idx <= (*l)->len && v)
    {
      /* create a temporary pointer and list length */
      list* tmp;
      size_t nsize;

      /* first iterator (for tmp*) */
      size_t i;
      /* second iterator (for l*) */
      size_t j;

      /* defines the new size */
      nsize = (*l)->usize * ((*l)->len + 1);

      /* reallocates to new size */
      tmp = malloc(nsize);

      /* if is tmp a valid pointer */
      if (tmp)
        {
          /* until idx, copy content from l to tmp */
          /*for (i = j = 0; i < (idx-1); i++, j++)
            *list_index(&tmp, i) = *list_index(l, j);*/
          memcpy(list_index(&tmp, 0), list_index(l, 0), (idx - 1) * (*l)->usize);

          /* insert the new value into tmp[idx] */
          /**list_index(&tmp, idx - 1) = (*v);*/
          memcpy(list_index(&tmp, idx - 1), v, (*l)->usize);

          /* copy remaining contents */
          /*for (i += 2; i < nsize; i++, j++)
            *list_index(&tmp, i) = *list_index(l, j);*/
          memcpy(list_index(&tmp, idx),
                 list_index(l, idx - 1),
                 (nsize - idx) * (*l)->usize);
        }

      /* free old list*/
      list_free(l);

      /* update l pointer */
      *l = tmp;

      return 1;
    }

  return 0;
}
