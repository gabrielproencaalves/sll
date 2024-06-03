#include "sll.h"
#include <stdlib.h>
#include <string.h>

/* list structure definition */
list**
list_new(size_t usiz)
{
  list** tmp = malloc(sizeof(list**));
  *tmp = malloc(sizeof(list*));
  (*tmp)->usize = usiz;
  (*tmp)->len = 0;
  (*tmp)->index = NULL;

  return tmp;
}

/* frees the specified list */
void
list_free(list** l)
{
  if (l)
    {
      if ((*l)->index)
        free((*l)->index);

      free(*l);
      free(l);
    }
}

/* appends a new item to the list */
int
list_append(list** l, void* v)
{
  /* if list and value exists */
  if (l && v)
    {
      /* create a temporary pointer and list length */
      void* tmp;
      size_t nsize;

      /* defines the new size */
      nsize = (*l)->usize * ((*l)->len + 1);

      if ((*l)->index)
        /* reallocates l->index to new size */
        tmp = realloc((*l)->index, nsize);
      else
        tmp = malloc(nsize);

      /* if re/allocation worked correctly */
      if (tmp)
      	{
          /* move v to last tmp's index */
          memcpy((tmp + (*l)->usize * (*l)->len++), v, (*l)->usize);

          /* update l pointer to tmp */
          (*l)->index = tmp;

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
  if (l && (*l)->len > 0)
    {
      /* create a temporary pointer and list length */
      void* tmp;
      size_t nsize;

      /* defines the new size */
      nsize = (*l)->usize * --(*l)->len;

      /* reallocates to new size */
      tmp = realloc((*l)->index, nsize);

      /* if reallocation worked correctly */
      if (tmp || nsize == 0)
      	{
          /* update l pointer to tmp */
          (*l)->index = tmp;

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
  if (l && idx > 0 && idx <= (*l)->len + 1 && v)
    {
      /* create a temporary pointer and list length */
      list** tmp;

      /* real index */
      size_t ridx;

      /* an iterator */
      size_t i;

      /* instance a new list to tmp */
      tmp = list_new((*l)->usize);

      /* define real index */
      ridx = idx - 1;


      /* until idx, copy content from l to tmp */
      for (i = 0; i < ridx; i++)
        /* if error */
        if (! list_append(tmp, (*l)->index + (*l)->usize * i))
          /* return bad signal */
          return 0;

      /* insert the new value into tmp[idx] */
      if (! list_append(tmp, v))
        /* return bad signal, if error */
        return 0;

      /* until len, copy content from l to tmp */
      for (; i < (*l)->len; i++)
        /* if error */
        if (! list_append(tmp, (*l)->index + (*l)->usize * i))
          /* return bad signal */
          return 0;

      /* free old list and struct */
      free((*l)->index);
      free((*l));

      /* update l pointer */
      (*l) = (*tmp);

      /* free tmp struct ** */
      free(tmp);

      /* ok */
      return 1;
    }

  /* bad */
  return 0;
}

/* deletes the specified index of list */
int
list_del(list** l, size_t idx)
{
  /* if l is a valid pointer, idx is positive and inside length of l */
  if (l && idx > 0 && idx <= (*l)->len)
    {
      /* real index */
      int ridx;

      ridx = idx - 1;

      /* shift the items started from idx */
      memcpy((*l)->index + (*l)->usize * ridx,
             (*l)->index + (*l)->usize * idx,
             (*l)->len - idx);

      /* remove the last index element */
      if (list_pop(l))
        /* ok */
        return 1;
    }

  /* bad */
  return 0;
}

void*
list_get(list** l, size_t idx)
{
  /* if l is a valid pointer, idx is positive and inside length of l */
  if (l && idx > 0 && idx <= (*l)->len)
      return (*l)->index + (*l)->usize * (idx - 1);

  /* bad */
  return NULL;
}
