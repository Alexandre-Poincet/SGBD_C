#include "../inc/func.h"

#include <stdio.h>
#include <stdlib.h>

void new_nuplet(nuplet_t *ps_n, const int size)
{
	if(ps_n != NULL)
	{
		ps_n->p_val =  calloc(sizeof(int), size);
		ps_n->size = size;
	}
}

void new_relation(relation_t *ps_r, const int attsize, const int maxsize)
{
	if(ps_r != NULL)
	{
		ps_r->line = calloc(sizeof(*(ps_r->line)), maxsize);
		ps_r->sizemax = maxsize;
		ps_r->size = 0;
		ps_r->attsize = attsize;
	}
}

void set(nuplet_t *ps_n, const int col, const int val)
{
	if(ps_n != NULL)
	{
		ps_n->p_val[col] = val;
	}
}

int get(const nuplet_t *ps_n, const int col)
{
	if(ps_n != NULL)
	{
		return ps_n->p_val[col];
	}

	return -1;
}

int compatible(const relation_t *ps_r, const nuplet_t *ps_n)
{
	if(ps_r != NULL && ps_n != NULL)
	{
		if(ps_r->attsize == ps_n->size)
			return 1;
		else
			return 0;
	}

	return -1;
}

void insert(relation_t *ps_r, const nuplet_t s_n)
{
	if((ps_r->size < ps_r->sizemax) && (compatible(ps_r, &s_n) == 1))
	{
		ps_r->line[ps_r->size] = s_n;
		ps_r->size++;
	}
}

nuplet_t get_nuplet(const relation_t *ps_r, const int line)
{
	if(line < ps_r->size)
		return ps_r->line[line];
}

void disp_nuplet(const nuplet_t *ps_n)
{
	int i;

	for(i = 0; i < ps_n->size; i++)
	{
		printf("%d ", ps_n->p_val[i]);
	}
}


void disp_relation(const relation_t *ps_r)
{
	int i;
	nuplet_t tmp;

	printf("RELATION === Taille %d sur %d\n================== \n", ps_r->size, ps_r->sizemax);
	
	for(i = 0; i < ps_r->size; i++)
	{
		tmp = get_nuplet(ps_r, i);
		disp_nuplet(&tmp);
		printf("\n");
	}
	printf("================== \n");
}

relation_t *op_union(relation_t *ps_r1, relation_t *ps_r2)
{
	relation_t *ps_temp = malloc(sizeof(*ps_temp));

	if(ps_temp == NULL)
	{
		return NULL;
	}

	new_relation(ps_temp, ps_r1->attsize, ps_r1->sizemax + ps_r2->sizemax);

	int i;
	
	if(ps_r1->attsize == ps_r2->attsize)
	{
		for(i = 0; i < ps_r1->size; i++)
		{
			insert(ps_temp, get_nuplet(ps_r1, i));
		}
		
		for(i = 0; i < ps_r2->size; i++)
		{
			insert(ps_temp, get_nuplet(ps_r2, i));
		}

		return ps_temp;
	}
}
