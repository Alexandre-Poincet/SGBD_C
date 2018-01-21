# SGBD_C

Compilation :

flex sql_parser.l
yacc -d sql_parser.y
gcc src/func.c lex.yy.c y.tab.c -o sql_parser



********* Example *********

Le programme crée la relation suivante :

RELATION === Taille 3 sur 10
==================
32 1000 1001
32 2000 2001
33 3000 3001
==================


Exemple de requete :

SELECT 0,1 FROM g WHERE 0=32;
SELECT 0,1 FROM g WHERE 0=32 AND 2=1001;
