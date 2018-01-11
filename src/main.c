#include <stdio.h>
#include <stdlib.h>

#include "../inc/func.h"

int main(int argc, char **argv)
{
	printf("Creation d'un nuplet.");

	nuplet_t n;
	
	new_nuplet(&n, 3);
	
	set(&n, 0, 1);
	set(&n, 1, 32);
	set(&n, 2, -1);
	
	printf("\n");
	disp_nuplet(&n);
	printf("Creation d'une relation.");
	
	relation_t p;
	
	new_relation(&p, 3, 10);
	insert(&p, n);
	printf("\n");
	disp_relation(&p);

	nuplet_t n2;

	new_nuplet(&n2, 3);
	
	set(&n2, 0, 2);
	set(&n2, 1, 42);
	set(&n2, 2, -15);
	insert(&p, n2);

	nuplet_t n3;

	new_nuplet(&n3, 3);
	
	set(&n3, 0, 3);
	set(&n3, 1, 62);
	set(&n3, 2, -99);

	relation_t q;
	
	new_relation(&q, 3, 10);
	insert(&q, n3);

	relation_t *res = op_union(&q, &p);
	disp_relation(res);

	free(res);

	free(p.line);
	free(q.line);

	free(n.p_val);
	free(n2.p_val);
	free(n3.p_val);

	return 0;
}
