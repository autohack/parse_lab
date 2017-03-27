%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}

%%
select					return SELECT;
drop					return DROP;
table					return TABLE;
alter					return ALTER;
add						return ADD;
create					return CREATE;
insert					return INSERT;
update					return UPDATE;
set 					return SET;
column					return COLUMN;
delete 					return DELETE;
from					return FROM;
where					return WHERE;
into 					return INTO;
values					return VALUES;
and						return AND;
or						return OR;
int   					return INT;
char 					return CHAR;
varchar					return VARCHAR;
primary 				return PRIMARY;
key						return KEY;
[;]						return *yytext;
[(]						return *yytext;
[)]						return *yytext;
[*]						return *yytext;
[,]						return *yytext;
"<="	|
">="	|
"<"		|
">"		|
[=]						return *yytext;
[\"][^\"]*[\"] 		return STRING;

[A-Za-z_][A-Z0a-z0-9_]*	return IDENTIFIER;
[0-9]+  |
[0-9]+"."[0-9]+ |
"."[0-9]+ 				return NUMBER;				
\n						return *yytext;
[ \t]+					/* ignore whitespace */;
%%
