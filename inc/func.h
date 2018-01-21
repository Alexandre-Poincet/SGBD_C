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
void new_relation(relation_t *ps_r, const int attsize, const int maxsize);
void insert(relation_t *ps_r, const nuplet_t ps_n);
void concatene_nuplet(nuplet_t *ps_res, nuplet_t *ps_a, nuplet_t *ps_b);
void copy_nuplet(nuplet_t *ps_n_dest, nuplet_t *ps_n_src);
void invert_nuplet(nuplet_t *ps_n1, nuplet_t *ps_n2);
void disp_relation(const relation_t *ps_r);
void disp_nuplet(const nuplet_t *n);

int get(const nuplet_t *ps_n, int col);
int cmp_nuplet(const nuplet_t *p_tmp1, const nuplet_t *p_tmp2);
int compatible(const relation_t *ps_r, const nuplet_t *ps_n);

void sort_relation(relation_t *ps_r1, int attr, int l, int r);

nuplet_t get_nuplet(const relation_t *ps_r, const int ligne);

relation_t *op_union(relation_t *ps_r1, relation_t *ps_r2);
relation_t *op_inter(relation_t *ps_r1, relation_t *ps_r2);
relation_t *op_restriction_cst(relation_t *ps_r1, const int att, const int operateur, const int valeur);
relation_t *op_restriction_att(relation_t *ps_r1, const int att1, const int operateur, const int att2);
relation_t *op_projection(relation_t *ps_r1, int* attributs, const int taille);
relation_t *op_produit_cartesien(relation_t *ps_r1, relation_t *ps_r2);
relation_t *op_jointure(relation_t *ps_r1, relation_t *ps_r2, const int attr1, const int attr2);

#endif // FUNC_H
