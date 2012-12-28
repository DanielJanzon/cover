%option nodefault noyywrap yylineno
%{
#include <string.h>
#include "main.h"
#include "grammar.h"
%}

%%
"+" |
"-" |
"*" |
"/"           { return yytext[0]; }

-?(0|[1-9][0-9]*)(\.[0-9]+)?([eE][+-]?[0-9]+)? { yylval.n = atof(yytext); return NUMBER; }

%%


