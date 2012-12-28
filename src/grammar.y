%{
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "ast.h"

extern struct ast *g_command;
int yylex(void);

void yyerror(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  va_end(ap);
}

%}

%union {
  struct ast *ast;
  double number;
}

%token EOL
%token <number> NUMBER 
%type <ast> factor term expression 

%destructor { ast_free($$); } <ast>

%start command 

%%
command:
  | command expression EOL {
        printf("parsed complete expression: %lf\n", ast_eval($2));
    }
;

expression:
  factor
  | expression '+' factor {
        printf("parsed sum\n");
        $$ = ast_new_sum($1, $3);
    }
  | expression '-' factor {
        $$ = ast_new_subtraction($1, $3);
    }
;

factor:
    term
  | factor '*' term {
        $$ = ast_new_product($1, $3); 
    }
  | factor '/' term {
        $$ = ast_new_quote($1, $3);
    }
;

term:
    NUMBER {
      printf("parsed number-term '%lf'\n", $1);
      $$ = ast_new_number($1);
    }
  | '(' expression ')' {
      $$ = $2;
    }
  | '-' term {
      $$ = ast_new_negation($2);
    }
;

%%

