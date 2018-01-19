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
	new_relation(&p, 3, 10);
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
	new_relation(&q, 3, 10);
	insert(&q, n3);
	disp_relation(&q);
	printf("\n");

	printf("relation 3 UNION(p, q) :\n");
	relation_t *res = op_union(&q, &p);
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
	new_relation(&a, 3, 10);
	insert(&a, n5);
	insert(&a, n4);
	disp_relation(&a);
	printf("\n");


	printf("relation 6 INTER(a,b):\n");
	relation_t *c = op_inter(&a, res);
	disp_relation(c);
	printf("\n");


	printf("relation7 INTER(res,res):\n");
	relation_t *d = op_inter(res,res);
	disp_relation(d);
	printf("\n");


	free(res->line);
	free(res);
	free(p.line);
	free(q.line);
	free(a.line);
	free(c->line);
	free(c);
	free(d->line);
	free(d);

	free(n.p_val);
	free(n2.p_val);
	free(n3.p_val);
	free(n4.p_val);
	free(n5.p_val);

	return 0;
}
