#include "../inc/func.h"

#include <stdio.h>

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
		ps_r->line = malloc(sizeof(*(ps_r->line)), maxsize);
		ps_r->sizemax = maxsize;
		ps_r->size = 0;
		ps_r->attsize = attsize;
	}
}

void set(nuplet_t *ps_n, const int col, const int val)
{
	if(ps_n != NULL)
	{
		ps_n->val[col] = val;
	}
}

int get(nuplet_t *ps_n, const int col)
{
	if(ps_n != NULL)
	{
		return ps_n->val[col];
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

void insert(relation_t *ps_r, const nuplet_t *ps_n)
{
	if((ps_r->size < ps_r->sizemax) && (compatible(ps_r, ps_n) == 1))
	{
		ps_r->line[ps_r->size] = n;
		ps_r->size++;
	}
}

nuplet_t get_nuplet(relation_t *ps_r, const int line){
	if(line < ps_r->size)
		return ps_r->line[line];
}

void afficheNUPLET(NUPLET n){
	int i;
	for(i=0;i<n.size;i++){
		printf("%d ", n.val[i]);
	}
}


void afficheRELATION(RELATION r){
	int i;
	printf("RELATION === Taille %d sur %d\n================== \n", r.size, r.sizemax);
	for(i=0;i<r.size;i++){
		afficheNUPLET(getNUPLET(r, i));
		printf("\n");
	}
	printf("================== \n");
}

/**
 *
 * IMPLEMENTATION DES OPERATEURS
 *
 **/

RELATION OpUnion(RELATION r1, RELATION r2){
	RELATION temp = newRELATION(r1.attsize, r1.sizemax + r2.sizemax);
	int i;
	if(r1.attsize == r2.attsize){
		for(i=0;i<r1.size;i++){
			insert(&temp, getNUPLET(r1, i));
		}
		for(i=0;i<r2.size;i++){
			insert(&temp, getNUPLET(r2, i));
		}
		return temp;
	}
}


/*
 * Programma principal
 */
int main(int argc, char **argv)
{
	printf("Creation d'un nuplet.");
	NUPLET n = newNUPLET(3);
	set(n, 0, 1);
	set(n, 1, 32);
	set(n, 2, -1);
	printf("\n");
	afficheNUPLET(n);
	printf("Creation d'une relation.");
	RELATION p = newRELATION(3, 10);
	insert(&p, n);
	printf("\n");
	afficheRELATION(p);

	NUPLET n2 = newNUPLET(3);
	set(n2, 0, 2);
	set(n2, 1, 42);
	set(n2, 2, -15);
	insert(&p, n2);


	NUPLET n3 = newNUPLET(3);
	set(n3, 0, 3);
	set(n3, 1, 62);
	set(n3, 2, -99);


	RELATION q = newRELATION(3, 10);
	insert(&q, n3);

	RELATION res = OpUnion(q, p);
	afficheRELATION(res);

	return 0;
}
