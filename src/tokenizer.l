%option nodefault noyywrap yylineno
%{
#include <string.h>
#include "main.h"
#include "grammar-generated.h"
%}

%%

"+" |
"-" |
"*" |
"/" |
"(" |
")"           { printf("character is '%c'\n", yytext[0]); return yytext[0]; }

-?(0|[1-9][0-9]*)(\.[0-9]+)?([eE][+-]?[0-9]+)? { yylval.number = atof(yytext); return NUMBER; }

"\n"          { return EOL; }
[ \t]         { /* Ignore whitespace */ }
.             { fprintf(stderr, "ignoring spurious character '%c'\n", *yytext); }

%%


