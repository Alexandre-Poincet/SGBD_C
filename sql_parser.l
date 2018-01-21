%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}
%%
SELECT {return SELECT;}
FROM {return FROM;}
WHERE {return WHERE;}
AND {return ANDOP;}
AS { return AS; }

-?[0-9]+ { yylval.intval = atoi(yytext); return INTNUM; }
-?[0-9]+"."[0-9]* |
-?"."[0-9]+ |
-?[0-9]+E[-+]?[0-9]+ |
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]+E[-+]?[0-9]+ { yylval.floatval = atof(yytext) ; return FLOATNUM; }

TRUE { yylval.intval = 1; return BOOL; }
FALSE { yylval.intval = 0; return BOOL; }

'(\\.|''|[^'\n])*' |
\"(\\.|\"\"|[^"\n])*\" { yylval.strval = strdup(yytext); return STRING; }

[A-Za-z][A-Za-z0-9_]* { yylval.strval = strdup(yytext); return NAME; }
`[^`/\\.\n]+`           { yylval.strval = strdup(yytext+1);
                          yylval.strval[yyleng-2] = 0;
                          return NAME; }

[-+&~|^/%*(),.;!] { return yytext[0]; }
"&&" { return ANDOP; }
"||" { return OR; }


"=" {yylval.subtok=4; return COMPARISON; }
"<=>" {yylval.subtok=12; return COMPARISON; }
">=" {yylval.subtok=6; return COMPARISON; }
">" {yylval.subtok=2; return COMPARISON; }
"<=" {yylval.subtok=5; return COMPARISON; }
"<" {yylval.subtok=1; return COMPARISON; }
"!=" |
"<>" {yylval.subtok=3; return COMPARISON; }

[ \t\n]
.               { yyerror("mystery character '%c'", *yytext); }
%%
