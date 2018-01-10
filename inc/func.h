#ifndef FUNC_H
#define FUNC_H

typedef struct nuplet nuplet_t;
struct nuplet
{
	int *p_val;
	int size;
};


typedef struct relation relation_t;
struct relation
{
	int attsize;
	int size;
	int sizemax;

	nuplet_t *line; 
};


void set(nuplet_t *ps_n, const int col, const int val);
void new_nuplet(nuplet_t *ps_n, const int size);
void insert(relation_t *ps_r, const nuplet_t *ps_n);
void disp_relation(const relation_t *ps_r);
void disp_nuplet(const nuplet_t *n);

int get(const nuplet_t *ps_n, int col);
int compatible(const relation_t *ps_r, const nuplet_t *ps_n);
 
nuplet_t get_nuplet(const relation_t *ps_r, const int ligne);

relation_t op_union(relation_t *ps_r1, relation_t *ps_r2);
relation_t op_inter(relation_t *ps_r1, relation_t *ps_r2);
relation_t op_restriction_cst(relation_t *ps_r1, const int att, const int operateur, const int valeur); 
relation_t op_restriction_att(relation_t *ps_r1, const int att1, const int operateur, const int att2);
relation_t op_projection(relation_t *ps_r1, int* attributs, const int taille);
relation_t op_produit_cartesien(relation_t *ps_r1, relation_t *ps_r2);
relation_t op_pointure(relation_t *ps_r1, relation_t *ps_r2, const int attr1, const int attr2);

#endif // FUNC_H
