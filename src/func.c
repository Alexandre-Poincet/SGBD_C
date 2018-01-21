#include "../inc/func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void concatene_nuplet(nuplet_t *ps_res, nuplet_t *ps_a, nuplet_t *ps_b)
{
	int i;
	int j;

	for(i = 0; i < ps_a->size && i < ps_res->size; i++)
	{
		ps_res->p_val[i] = ps_a->p_val[i];
	}

	for(j = 0; j < ps_b->size && i+j < ps_res->size; j++)
	{
		ps_res->p_val[i + j] = ps_b->p_val[j];
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

int cmp_nuplet(const nuplet_t *p_tmp1, const nuplet_t *p_tmp2)
{
	int i = 0;
	int ret = 0;

	if(p_tmp1->size != p_tmp2->size)
	{
		return -1;
	}

	for(; i < p_tmp1->size; i++)
	{
		if(p_tmp1->p_val[i] != p_tmp2->p_val[i])
		{
			ret = -1;
		}
	}

	return ret;
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

relation_t *op_inter(relation_t *ps_r1, relation_t *ps_r2)
{
	relation_t *ps_temp = malloc(sizeof(*ps_temp));

	if(ps_temp == NULL)
	{
		return NULL;
	}

	int sizemax = (ps_r1->sizemax > ps_r2->sizemax) ? ps_r2->sizemax : ps_r1->sizemax;

	new_relation(ps_temp, ps_r1->attsize, sizemax);

	int i, j;

	for(i = 0; i < ps_r1->size; i++)
	{
		nuplet_t tmp1 = get_nuplet(ps_r1, i);

		for(j = 0; j < ps_r2->size; j++)
		{
			nuplet_t tmp2 = get_nuplet(ps_r2, j);

			if(cmp_nuplet(&tmp1, &tmp2) == 0)
			{
				insert(ps_temp, tmp1);
			}
		}
	}

	return ps_temp;
}

relation_t *op_restriction_cst(relation_t *ps_r1, const int att, const int operateur, const int valeur)
{
	// 4 = ; >= 6; > 2; <= 5; < 1; != 3

	int i = 0;
	relation_t *ps_temp = malloc(sizeof(*ps_temp));

	if(ps_temp == NULL)
	{
		return NULL;
	}

	new_relation(ps_temp, ps_r1->size, ps_r1->sizemax);

	printf("%d\n", ps_r1->size);

	for(i = 0; i < ps_r1->size; i++)
	{
		printf("%d\n", i);
		nuplet_t tmp1 = get_nuplet(ps_r1, i);

		switch(operateur)
		{
			case 4:
				if(tmp1.p_val[att] == valeur)
				{
					insert(ps_temp, tmp1);
				}
				break;
			case 6:
				if(tmp1.p_val[att] >= valeur)
				{
					insert(ps_temp, tmp1);
				}
				break;
			case 2:
				if(tmp1.p_val[att] > valeur)
				{
					insert(ps_temp, tmp1);
				}
				break;
			case 5:
				if(tmp1.p_val[att] <= valeur)
				{
					insert(ps_temp, tmp1);
				}
				break;
			case 1:
				if(tmp1.p_val[att] < valeur)
				{
					insert(ps_temp, tmp1);
				}
				break;
			case 3:
				if(tmp1.p_val[att] != valeur)
				{
					insert(ps_temp, tmp1);
				}
				break;
		}
	}

	return ps_temp;
}

relation_t *op_restriction_att(relation_t *ps_r1, const int att1, const int operateur, const int att2)
{
	// 4 = ; >= 6; > 2; <= 5; < 1; != 3

	relation_t *p_temp = malloc(sizeof(*p_temp));

	int i, j, k, bool = 1;

	if(p_temp == NULL)
	{
		return NULL;
	}

	new_relation(p_temp, ps_r1->attsize, ps_r1->sizemax);

	for(i = 0; i < ps_r1->size; i++)
	{
		nuplet_t tmp1 = get_nuplet(ps_r1, i);

		for(j = 0; j < ps_r1->size; j++)
		{
			nuplet_t tmp2 = get_nuplet(ps_r1, j);

			switch(operateur)
			{
				case 4:
					if(tmp1.p_val[att1] == tmp2.p_val[att2])
					{
						for(k = 0; k < p_temp->size; k++)
						{
							nuplet_t tmp3 = get_nuplet(p_temp, k);

							if(cmp_nuplet(&tmp3, &tmp2) == 0)
							{
								bool = 0;
								break;
							}

							else
							{
								bool = 1;
							}
						}

						if(bool)
						{
							insert(p_temp, tmp2);
						}
					}
					break;
				case 6:
					if(tmp1.p_val[att1] >= tmp2.p_val[att2])
					{
						for(k = 0; k < p_temp->size; k++)
						{
							nuplet_t tmp3 = get_nuplet(p_temp, k);

							if(cmp_nuplet(&tmp3, &tmp2) == 0)
							{
								bool = 0;
								break;
							}

							else
							{
								bool = 1;
							}
						}

						if(bool)
						{
							insert(p_temp, tmp2);
						}
					}
					break;
				case 2:
					if(tmp1.p_val[att1] > tmp2.p_val[att2])
					{
						for(k = 0; k < p_temp->size; k++)
						{
							nuplet_t tmp3 = get_nuplet(p_temp, k);

							if(cmp_nuplet(&tmp3, &tmp2) == 0)
							{
								bool = 0;
								break;
							}

							else
							{
								bool = 1;
							}
						}

						if(bool)
						{
							insert(p_temp, tmp2);
						}
					}
					break;
				case 5:
					if(tmp1.p_val[att1] <= tmp2.p_val[att2])
					{
						for(k = 0; k < p_temp->size; k++)
						{
							nuplet_t tmp3 = get_nuplet(p_temp, k);

							if(cmp_nuplet(&tmp3, &tmp2) == 0)
							{
								bool = 0;
								break;
							}

							else
							{
								bool = 1;
							}
						}

						if(bool)
						{
							insert(p_temp, tmp2);
						}
					}
					break;
				case 1:
					if(tmp1.p_val[att1] < tmp2.p_val[att2])
					{
						for(k = 0; k < p_temp->size; k++)
						{
							nuplet_t tmp3 = get_nuplet(p_temp, k);

							if(cmp_nuplet(&tmp3, &tmp2) == 0)
							{
								bool = 0;
								break;
							}

							else
							{
								bool = 1;
							}
						}

						if(bool)
						{
							insert(p_temp, tmp2);
						}
					}
					break;
				case 3:
					if(tmp1.p_val[att1] != tmp2.p_val[att2])
					{
						for(k = 0; k < p_temp->size; k++)
						{
							nuplet_t tmp3 = get_nuplet(p_temp, k);

							if(cmp_nuplet(&tmp3, &tmp2) == 0)
							{
								bool = 0;
								break;
							}

							else
							{
								bool = 1;
							}
						}

						if(bool)
						{
							insert(p_temp, tmp2);
						}
					}
					break;
			}
		}
	}

	return p_temp;
}

relation_t *op_produit_cartesien(relation_t *ps_r1, relation_t *ps_r2)
{
	int i,j;
	relation_t *ps_tmp = malloc(sizeof(*ps_tmp));

	if(ps_tmp == NULL)
	{
		return NULL;
	}

	new_relation(ps_tmp, ps_r1->attsize + ps_r2->attsize, ps_r1->sizemax * ps_r2->sizemax);

	for(i = 0; i < ps_r1->size; i++)
	{
		nuplet_t tmp1 = get_nuplet(ps_r1, i);

		for(j = 0; j < ps_r2->size; j++)
		{
			nuplet_t tmp2 = get_nuplet(ps_r2, j);

			nuplet_t tmp3;

			new_nuplet(&tmp3, tmp1.size + tmp2.size);

			concatene_nuplet(&tmp3, &tmp1, &tmp2);

			insert(ps_tmp, tmp3);
		}
	}

	return ps_tmp;
}

relation_t *op_jointure(relation_t *ps_r1, relation_t *ps_r2, const int attr1, const int attr2){
	int i = 0;
	int j = 0;

	relation_t *ps_tmp = malloc(sizeof(*ps_tmp));

	if(ps_tmp == NULL)
	{
		return NULL;
	}

	new_relation(ps_tmp, ps_r1->attsize+ps_r2->attsize, ps_r1->size+ps_r1->size);
	sort_relation(ps_r1,attr1,0,ps_r1->size);
	sort_relation(ps_r2,attr2,0,ps_r2->size);

	for(i = 0; i < ps_r1->size; i++)
	{
		nuplet_t tmp1 = ps_r1->line[i];
		int matched=0;
		for(j = 0; j < ps_r2->size; j++){
			nuplet_t tmp2 = ps_r2->line[j];
			if(tmp1.p_val[attr1]==tmp2.p_val[attr2]){
				nuplet_t n;
				new_nuplet(&n, ps_r1->attsize+ps_r2->attsize);
				int z;
				for(z=0; z<tmp1.size;z++){
					set(&n, z, tmp1.p_val[z]);
				}
				for(z=0; z<tmp2.size;z++){
					set(&n, tmp1.size+z, tmp2.p_val[z]);
				}
				insert(ps_tmp, n);
				matched=1;
			}
			else if(matched){
				continue;
			}
		}
	}
	return ps_tmp;
}

relation_t *op_projection(relation_t *ps_r1, int* attributs, const int taille){
	int i,j;
	relation_t *ps_tmp = malloc(sizeof(*ps_tmp));

	if(ps_tmp == NULL)
	{
		return NULL;
	}

	new_relation(ps_tmp, taille, ps_r1->size);

	for(i = 0; i < ps_r1->size; i++)
	{
		nuplet_t tmp1 = ps_r1->line[i];
		nuplet_t n;
		new_nuplet(&n, taille);
		for(int j=0; j<taille;j++){
			set(&n,j,tmp1.p_val[attributs[j]]);
		}
		insert(ps_tmp,n);
	}
	return ps_tmp;
}

// ===== Sorting relation_t ======

void sort_relation(relation_t *ps_r1, int attr, int l, int r)
{
	// Bubble sort
	int i, j;
	int n=ps_r1->size;
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-i-1; j++)
			if ((ps_r1->line[j]).p_val[attr] > (ps_r1->line[j+1]).p_val[attr])
				invert_nuplet(&(ps_r1->line[j]), &(ps_r1->line[j+1]));
}

void copy_nuplet(nuplet_t *ps_n_dest, nuplet_t *ps_n_src){
	if(ps_n_dest != NULL && ps_n_src != NULL)
	{
		ps_n_dest->p_val =  calloc(sizeof(int), ps_n_src->size);
		memcpy(ps_n_dest->p_val, ps_n_src->p_val, sizeof(int)*ps_n_src->size);
		ps_n_dest->size = ps_n_src->size;
	}
}

void invert_nuplet(nuplet_t *ps_n1, nuplet_t *ps_n2){
	if(ps_n1 != NULL && ps_n2 != NULL && ps_n1->size==ps_n2->size)
	{
		int* tmp;
		tmp=ps_n1->p_val;
		ps_n1->p_val=ps_n2->p_val;
		ps_n2->p_val=tmp;
	}
}
