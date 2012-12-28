#include <iostream>

#include "grammar-generated.h"

struct ast *g_command = NULL;

extern "C" {
  int yyparse();
}

int main() {
  return yyparse();
}
