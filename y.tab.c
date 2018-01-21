/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "sql_parser.y"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "inc/func.h"
#line 8 "sql_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int intval;
	double floatval;
	char *strval;
	int subtok;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 40 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NAME 257
#define STRING 258
#define INTNUM 259
#define BOOL 260
#define FLOATNUM 261
#define SELECT 262
#define FROM 263
#define WHERE 264
#define AND 265
#define AS 266
#define BOLL 267
#define ANDOP 268
#define OR 269
#define COMPARISON 270
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    3,    4,    4,    1,    1,    1,    6,    8,
    8,    8,    2,    2,    9,   10,   10,   10,    5,    5,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,
};
static const YYINT yylen[] = {                            2,
    2,    3,    1,    2,    5,    1,    3,    1,    2,    2,
    1,    0,    1,    3,    1,    2,    4,    3,    0,    2,
    1,    3,    1,    1,    1,    1,    3,    3,    3,    3,
    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    3,    0,   23,   24,   26,   25,    8,
    0,    6,    0,    0,    1,    0,    0,    0,   11,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    2,
   22,    0,    0,    0,   13,   15,    7,   10,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   16,    0,    0,
    0,    5,    0,   18,    0,   14,   17,
};
static const YYINT yydgoto[] = {                          2,
   11,   34,    3,    4,   52,   12,   13,   29,   35,   36,
};
static const YYINT yysindex[] = {                      -253,
   -7, -253,  -46,    0,  -32,    0,    0,    0,    0,    0,
  -40,    0,  -22,  -31,    0, -230,  -39, -207,    0, -219,
 -207, -207, -207, -207, -207, -207, -207, -207,    0,    0,
    0,  -30,  -39,  -25,    0,    0,    0,    0,  -13,  -13,
   -6,  -13,  -13,  -13,  -13,  -13, -213,    0,    2, -207,
  -39,    0, -217,    0,  -13,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,  -37,    0,    0,    0,    0,    0,
   -3,    0,  -33,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,   -2,    0,    0,    0,    0,  -41,    3,
  -42,    4,   11,   15,   22,   23,    0,    0,    0,    0,
    0,    0,    1,    0,   -1,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   28,   63,    0,    0,   46,   62,  -20,   17,    0,
};
#define YYTABLESIZE 289
static const YYINT yytable[] = {                         21,
   33,   34,   32,   18,   21,   21,   21,   21,    1,   21,
   12,   48,   15,   16,   28,   47,   34,   32,   51,   24,
   25,   21,   26,   28,   27,   12,   31,   30,   24,   25,
   28,   26,   57,   27,   10,   24,   25,   38,   26,   19,
   27,   12,   54,   53,   12,   51,   33,   29,   20,    5,
    6,    7,    8,    9,   27,    4,   19,   20,   28,   12,
   49,   33,   29,   37,   14,   30,   31,   56,    0,   27,
    0,    0,    0,   28,    0,    0,    0,    0,    0,    0,
   30,   31,   39,   40,   41,   42,   43,   44,   45,   46,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   55,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   34,   32,    0,   32,    0,   21,
   34,   32,   17,   34,   32,   21,   19,   34,   21,   12,
   21,   21,   21,    0,   19,   20,    0,    0,   50,    0,
    0,    0,    0,   20,    0,   21,   22,   23,    0,    5,
    6,    7,    8,    9,   21,   22,   23,    0,    0,   33,
   29,   21,   22,    0,   12,   33,   29,   27,   33,   29,
    0,   28,    0,   27,    0,    0,   27,   28,   30,   31,
   28,    0,    0,    0,   30,   31,    0,   30,   31,
};
static const YYINT yycheck[] = {                         37,
   40,   44,   44,   44,   42,   43,   44,   45,  262,   47,
   44,   32,   59,   46,   37,   46,   59,   59,   44,   42,
   43,   59,   45,   37,   47,   59,  257,   59,   42,   43,
   37,   45,   53,   47,   42,   42,   43,  257,   45,  257,
   47,   41,   41,  257,   44,   44,   44,   44,  266,  257,
  258,  259,  260,  261,   44,   59,   59,   59,   44,   59,
   33,   59,   59,   18,    2,   44,   44,   51,   -1,   59,
   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   59,   21,   22,   23,   24,   25,   26,   27,   28,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   50,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  257,   -1,  257,   -1,  257,
  263,  263,  263,  266,  266,  263,  257,  270,  266,  263,
  268,  269,  270,   -1,  257,  266,   -1,   -1,  264,   -1,
   -1,   -1,   -1,  266,   -1,  268,  269,  270,   -1,  257,
  258,  259,  260,  261,  268,  269,  270,   -1,   -1,  257,
  257,  268,  269,   -1,  264,  263,  263,  257,  266,  266,
   -1,  257,   -1,  263,   -1,   -1,  266,  263,  257,  257,
  266,   -1,   -1,   -1,  263,  263,   -1,  266,  266,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 270
#define YYUNDFTOKEN 283
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,0,0,
0,0,0,"';'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"NAME","STRING","INTNUM","BOOL","FLOATNUM","SELECT","FROM","WHERE","AND",
"AS","BOLL","ANDOP","OR","COMPARISON",0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : stmt_list",
"stmt_list : stmt ';'",
"stmt_list : stmt_list stmt ';'",
"stmt : select_stmt",
"select_stmt : SELECT select_expr_list",
"select_stmt : SELECT select_expr_list FROM table_references opt_where",
"select_expr_list : select_expr",
"select_expr_list : select_expr_list ',' select_expr",
"select_expr_list : '*'",
"select_expr : expr opt_as_alias",
"opt_as_alias : AS NAME",
"opt_as_alias : NAME",
"opt_as_alias :",
"table_references : table_reference",
"table_references : table_references ',' table_reference",
"table_reference : table_factor",
"table_factor : NAME opt_as_alias",
"table_factor : NAME '.' NAME opt_as_alias",
"table_factor : '(' table_references ')'",
"opt_where :",
"opt_where : WHERE expr",
"expr : NAME",
"expr : NAME '.' NAME",
"expr : STRING",
"expr : INTNUM",
"expr : FLOATNUM",
"expr : BOOL",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr ANDOP expr",
"expr : expr OR expr",
"expr : expr COMPARISON expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 105 "sql_parser.y"


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
#line 439 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 48 "sql_parser.y"
	{ emit("STMT"); evaluate_stmt(); }
break;
case 4:
#line 52 "sql_parser.y"
	{ emit("SELECTNODATA %d", yystack.l_mark[0].intval); }
break;
case 5:
#line 56 "sql_parser.y"
	{ emit("SELECT %d %d", yystack.l_mark[-3].intval, yystack.l_mark[-1].intval); s_select.nb_attr=yystack.l_mark[-3].intval; s_select.nb_tables=yystack.l_mark[-1].intval; }
break;
case 6:
#line 59 "sql_parser.y"
	{ yyval.intval = 1; }
break;
case 7:
#line 60 "sql_parser.y"
	{yyval.intval = yystack.l_mark[-2].intval + 1; }
break;
case 8:
#line 61 "sql_parser.y"
	{ emit("SELECTALL"); yyval.intval = 1; }
break;
case 10:
#line 66 "sql_parser.y"
	{ emit ("ALIAS %s", yystack.l_mark[0].strval); free(yystack.l_mark[0].strval); }
break;
case 11:
#line 67 "sql_parser.y"
	{ emit ("ALIAS %s", yystack.l_mark[0].strval); free(yystack.l_mark[0].strval); }
break;
case 13:
#line 71 "sql_parser.y"
	{ yyval.intval = 1; }
break;
case 14:
#line 72 "sql_parser.y"
	{ yyval.intval = yystack.l_mark[-2].intval + 1; }
break;
case 16:
#line 78 "sql_parser.y"
	{ emit("TABLE %s", yystack.l_mark[-1].strval); add_data_str(yystack.l_mark[-1].strval); }
break;
case 17:
#line 79 "sql_parser.y"
	{ emit("TABLE %s.%s", yystack.l_mark[-3].strval, yystack.l_mark[-1].strval); free(yystack.l_mark[-3].strval); free(yystack.l_mark[-1].strval); }
break;
case 18:
#line 80 "sql_parser.y"
	{ emit("TABLEREFERENCES %d", yystack.l_mark[-1].intval); }
break;
case 20:
#line 84 "sql_parser.y"
	{ emit("WHERE"); }
break;
case 21:
#line 86 "sql_parser.y"
	{emit("NAME %s", yystack.l_mark[0].strval); add_data_str(yystack.l_mark[0].strval); }
break;
case 22:
#line 87 "sql_parser.y"
	{emit("FIELDNAME %s.%s", yystack.l_mark[-2].strval, yystack.l_mark[0].strval); free(yystack.l_mark[-2].strval); free(yystack.l_mark[0].strval); }
break;
case 23:
#line 88 "sql_parser.y"
	{emit("STRING %s", yystack.l_mark[0].strval); add_data_str(yystack.l_mark[0].strval); }
break;
case 24:
#line 89 "sql_parser.y"
	{emit("NUMBER %d", yystack.l_mark[0].intval); add_data_int(yystack.l_mark[0].intval); }
break;
case 25:
#line 90 "sql_parser.y"
	{emit("FLOAT %g", yystack.l_mark[0].floatval); add_data_float(yystack.l_mark[0].floatval); }
break;
case 26:
#line 91 "sql_parser.y"
	{emit("BOOL %d", yystack.l_mark[0].intval); }
break;
case 27:
#line 95 "sql_parser.y"
	{ emit("ADD"); }
break;
case 28:
#line 96 "sql_parser.y"
	{ emit("SUB"); }
break;
case 29:
#line 97 "sql_parser.y"
	{ emit("MUL"); }
break;
case 30:
#line 98 "sql_parser.y"
	{ emit("DIV"); }
break;
case 31:
#line 99 "sql_parser.y"
	{ emit("MOD"); }
break;
case 32:
#line 100 "sql_parser.y"
	{ emit("AND"); }
break;
case 33:
#line 101 "sql_parser.y"
	{ emit("OR"); }
break;
case 34:
#line 102 "sql_parser.y"
	{ emit("CMP %d", yystack.l_mark[-1].subtok); add_clause(yystack.l_mark[-1].subtok); }
break;
#line 753 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
