%{
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "inc/func.h"
%}

%union {
	int intval;
	double floatval;
	char *strval;
	int subtok;
}

%token <strval> NAME
%token <strval> STRING
%token <intval> INTNUM
%token <intval> BOOL
%token <floatval> FLOATNUM

%token SELECT
%token FROM
%token WHERE
%token AND
%token AS
%token INTNUM
%token FLOATNUM
%token BOLL
%token STRING
%token NAME
%token ANDOP
%token OR
%token COMPARISON

%left <subtok> COMPARISON /* = <> < > <= >= <=> */

%type <intval> select_expr_list
%type <intval> table_references

%start stmt_list

%%

stmt_list: stmt ';'
| stmt_list stmt ';'
;

stmt: select_stmt { emit("STMT"); evaluate_stmt(); }
;

select_stmt: SELECT select_expr_list
{ emit("SELECTNODATA %d", $2); } ;
;
| SELECT select_expr_list
FROM table_references
opt_where { emit("SELECT %d %d", $2, $4); s_select.nb_attr=$2; s_select.nb_tables=$4; }
;

select_expr_list: select_expr { $$ = 1; }
| select_expr_list ',' select_expr {$$ = $1 + 1; }
| '*' { emit("SELECTALL"); $$ = 1; }
;

select_expr: expr opt_as_alias ;

opt_as_alias: AS NAME { emit ("ALIAS %s", $2); free($2); }
| NAME { emit ("ALIAS %s", $1); free($1); }
|
;

table_references: table_reference { $$ = 1; }
| table_references ',' table_reference { $$ = $1 + 1; }
;

table_reference: table_factor;

table_factor:
NAME opt_as_alias { emit("TABLE %s", $1); add_data_str($1); }
| NAME '.' NAME opt_as_alias { emit("TABLE %s.%s", $1, $3); free($1); free($3); }
| '(' table_references ')' { emit("TABLEREFERENCES %d", $2); }
;

opt_where:
| WHERE expr { emit("WHERE"); };

expr: NAME {emit("NAME %s", $1); add_data_str($1); }
| NAME '.' NAME {emit("FIELDNAME %s.%s", $1, $3); free($1); free($3); }
| STRING {emit("STRING %s", $1); add_data_str($1); }
| INTNUM {emit("NUMBER %d", $1); add_data_int($1); }
| FLOATNUM {emit("FLOAT %g", $1); add_data_float($1); }
| BOOL {emit("BOOL %d", $1); }
;


expr: expr '+' expr { emit("ADD"); }
| expr '-' expr { emit("SUB"); }
| expr '*' expr { emit("MUL"); }
| expr '/' expr { emit("DIV"); }
| expr '%' expr { emit("MOD"); }
| expr ANDOP expr { emit("AND"); }
| expr OR expr { emit("OR"); }
| expr COMPARISON expr { emit("CMP %d", $2); add_clause($2); }

%%


tab_relation_t db;
token_val_t tab_data[50];
char* tab_instruction[50];

int cpt_data=0;
int cpt_instruction=0;

select_stmt_t s_select;
clause_t clauses[50];
int cpt_clause=0;


void add_data_int(int val){
	tab_data[cpt_data].type=is_int;
	tab_data[cpt_data].val.ival=val;
	cpt_data++;
}

void add_data_float(float val){
	tab_data[cpt_data].type=is_float;
	tab_data[cpt_data].val.fval=val;
	cpt_data++;
}

void add_data_str(char *str){
	tab_data[cpt_data].type=is_str;
	tab_data[cpt_data].val.strval=str;
	cpt_data++;
}

void add_data_instruction(char *inst){
	tab_instruction[cpt_instruction]=inst;
	cpt_instruction++;
}

int popback_data_int(){
	int ret=tab_data[cpt_data-1].val.ival;
	cpt_data--;
	return ret;
}

char* popback_data_str(){
	char* ret=tab_data[cpt_data-1].val.strval;
	cpt_data--;
	return ret;
}

token_val_t* popback_data(){
	token_val_t *ret=&tab_data[cpt_data-1];
	cpt_data--;
	return ret;
}

void add_clause(int op){
	clauses[cpt_clause].attr2=popback_data_int();
	clauses[cpt_clause].attr1=popback_data_int();
	clauses[cpt_clause].operateur=op;
	cpt_clause++;
}

void evaluate_stmt(){
	relation_t *res_r;
	relation_t *table;
	if(s_select.nb_tables>0){
		char* r_name=popback_data_str();
		//printf("popback table : %s\n",r_name);
		table=find_relation(&db,r_name);
		//disp_relation(table);
		if(cpt_clause!=0){
			for(;cpt_clause>0;cpt_clause--){
				//printf("cpt_clause = %d\n",cpt_clause);
				//printf("clause = %d; %d; %d\n",clauses[cpt_clause-1].attr1,clauses[cpt_clause-1].operateur,clauses[cpt_clause-1].attr2);
				table=op_restriction_cst(table,clauses[cpt_clause-1].attr1,clauses[cpt_clause-1].operateur,clauses[cpt_clause-1].attr2);
			}
		}
		if(s_select.nb_attr>0){
			//printf("else\n");
			int rest_size=cpt_data;
			//printf("rest_size = %d\n",rest_size);
			int attributs[cpt_data];
			for(;cpt_data>0;){
				//printf("attr = %d\n", attributs[cpt_data-1]);
				attributs[cpt_data-1]=popback_data_int();
			}
			table=op_projection(table,attributs,rest_size);
		}

	}

	disp_relation(table);
}

void emit(char *s, ...){
	return;
	extern yylineno;
	va_list ap;
	va_start(ap, s);

	vfprintf(stdout, s, ap);
	printf("\n");
}


void yyerror(const char *str)
{
	fprintf(stderr,"error: %s\n",str);
}

int yywrap()
{
	return 1;
}

int main()
{
	printf("start main\n");
	nuplet_t n6;
	new_nuplet(&n6, 3);
	set(&n6, 0, 32);
	set(&n6, 1, 1000);
	set(&n6, 2, 1001);


	nuplet_t n7;
	new_nuplet(&n7, 3);
	set(&n7, 0, 32);
	set(&n7, 1, 2000);
	set(&n7, 2, 2001);

	nuplet_t n8;
	new_nuplet(&n8, 3);
	set(&n8, 0, 33);
	set(&n8, 1, 3000);
	set(&n8, 2, 3001);

	printf("relation 5 : \n");
	relation_t g;
	new_relation(&g, 3, 10);
	insert(&g, n6);
	insert(&g, n7);
	insert(&g, n8);
	disp_relation(&g);


	new_tab_relation(&db,5);
	add_relation_tab(&db,&g);
  yyparse();
  return 0;
}
