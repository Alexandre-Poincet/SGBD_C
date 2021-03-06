#include <stdio.h>
#include <stdlib.h>

#include "../inc/func.h"

int main(int argc, char **argv)
{
	printf("nuplet 1 :\n");
	nuplet_t n;
	new_nuplet(&n, 3);
	set(&n, 0, 1);
	set(&n, 1, 32);
	set(&n, 2, -1);
	disp_nuplet(&n);
	printf("\n");

	printf("relation 1 : \n.");
	relation_t p;
	new_relation(&p, 3, 10, "aaa", "a");
	insert(&p, n);
	disp_relation(&p);
	printf("\n");

	printf("nuplet 2 :\n");
	nuplet_t n2;
	new_nuplet(&n2, 3);
	set(&n2, 0, 2);
	set(&n2, 1, 42);
	set(&n2, 2, -15);
	insert(&p, n2);
	disp_nuplet(&n2);
	printf("\n");

	printf("nuplet 3 :\n");
	nuplet_t n3;
	new_nuplet(&n3, 3);
	set(&n3, 0, 3);
	set(&n3, 1, 62);
	set(&n3, 2, -99);
	disp_nuplet(&n3);
	printf("\n");

	printf("relation 2 :\n");
	relation_t q;
	new_relation(&q, 3, 10, "bbb", "b");
	insert(&q, n3);
	disp_relation(&q);
	printf("\n");

	printf("relation 3 UNION(p, q) :\n");
	relation_t *res = op_union(&q, &p, "res", "r");
	disp_relation(res);
	printf("\n");

	printf("nuplet 4 :\n");
	nuplet_t n4;
	new_nuplet(&n4, 3);
	set(&n4, 0, 1);
	set(&n4, 1, 32);
	set(&n4, 2, -1);
	disp_nuplet(&n4);
	printf("\n");

	printf("nuplet 5 :\n");
	nuplet_t n5;
	new_nuplet(&n5, 3);
	set(&n5, 0, 0);
	set(&n5, 1, 6);
	set(&n5, 2, 9);
	disp_nuplet(&n5);
	printf("\n");

	printf("relation 4 :\n");
	relation_t a;
	new_relation(&a, 3, 10, "ccc", "c");
	insert(&a, n5);
	insert(&a, n4);
	disp_relation(&a);
	printf("\n");



	printf("nuplet 6 :\n");
	nuplet_t n6;
	new_nuplet(&n6, 3);
	set(&n6, 0, 32);
	set(&n6, 1, 1000);
	set(&n6, 2, 1001);
	disp_nuplet(&n2);
	printf("\n");

	printf("nuplet 7 :\n");
	nuplet_t n7;
	new_nuplet(&n7, 3);
	set(&n7, 0, 32);
	set(&n7, 1, 2000);
	set(&n7, 2, 2001);
	disp_nuplet(&n7);
	printf("\n");

	printf("nuplet 8 :\n");
	nuplet_t n8;
	new_nuplet(&n8, 3);
	set(&n8, 0, 33);
	set(&n8, 1, 3000);
	set(&n8, 2, 3001);
	disp_nuplet(&n8);
	printf("\n");

	printf("relation 5 : \n");
	relation_t g;
	new_relation(&g, 3, 10, "ddd", "d");
	insert(&g, n6);
	insert(&g, n7);
	insert(&g, n8);
	disp_relation(&g);


	printf("relation 6 INTER(a,res):\n");
	relation_t *c = op_inter(&a, res, "eee", "e");
	disp_relation(c);
	printf("\n");

	printf("relation7 INTER(res,res):\n");
	relation_t *d = op_inter(res,res, "fff", "f");
	disp_relation(d);
	printf("\n");

	printf("relation 8 RES_CST(res, 0) : \n");
	relation_t *x = op_restriction_cst(res, 1, 4, 32, "ggg", "g");
	disp_relation(x);
	printf("\n");

	printf("relaiton 9 RES_CST(res) : \n");
	relation_t *y = op_restriction_cst(res, 2, 6, -70, "hhh", "h");
	disp_relation(y);
	printf("\n");

	printf("relation 10 RES_ATT(res, 32)");
	relation_t *z = op_restriction_att(res, 0, 6, 2, "iii", "i");
	disp_relation(z);
	printf("\n");

	printf("relation 11 RES_ATT(a)\n");
	relation_t *zz = op_restriction_att(&a, 0, 6, 2, "jjj", "j");
	disp_relation(zz);
	printf("\n");

	printf("relation 12 REST_PROD_CAR(res,a)\n");
	relation_t *zzz = op_produit_cartesien(res, &a, "kkk", "k");
	disp_relation(zzz);
	printf("\n");

	printf("relation 13 JOINTURE(relation 5, relation 12 , attr 0, attr 1)\n");
	relation_t *yy = op_jointure(&g, zzz, 0, 1, "lll", "l");
	disp_relation(yy);
	printf("\n");

	printf("relation 14 PROJECTION(relation 13, [0,1,6], 3)\n");
	int attrs[3]={0,1,6};
	relation_t *yyy = op_projection(yy, attrs, 3, "mmm", "m");
	disp_relation(yyy);
	printf("\n");

	int i;

	for(i = 0; i < zzz->size; i++)
	{
		nuplet_t tmp = get_nuplet(zzz, i);
		free(tmp.p_val);
	}
	for(i = 0; i <yy->size; i++)
	{
		nuplet_t tmp = get_nuplet(yy, i);
		free(tmp.p_val);
	}
	for(i = 0; i < yyy->size; i++)
	{
		nuplet_t tmp = get_nuplet(yyy, i);
		free(tmp.p_val);
	}

	free(zzz->line);
	free(zzz);
	free(zz->line);
	free(zz);
	free(z->line);
	free(z);
	free(y->line);
	free(y);
	free(x->line);
	free(x);
	free(res->line);
	free(res);
	free(p.line);
	free(q.line);
	free(a.line);
	free(c->line);
	free(c);
	free(d->line);
	free(d);
	free(g.line);
	free(yy->line);
	free(yy);
	free(yyy->line);
	free(yyy);

	free(n.p_val);
	free(n2.p_val);
	free(n3.p_val);
	free(n4.p_val);
	free(n5.p_val);
	free(n6.p_val);
	free(n7.p_val);

	return 0;
}
