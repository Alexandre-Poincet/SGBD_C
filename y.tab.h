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
extern YYSTYPE yylval;
