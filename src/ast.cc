#include <cstdlib>
#include <cmath>
#include <iostream>

#include "ast.h"

extern "C" void yyerror(const char *s, ...);

static struct ast* new_ast(enum ast_node_t type)
{
  struct ast *node = new ast;

  if(!node) {
    yyerror("out of memory");
    exit(EXIT_FAILURE);
  }

  node->node_type = type;
  node->next = NULL;
  return node;
}

extern "C" struct ast *ast_new_number(double x)
{
  struct ast *node = new_ast(AST_TYPE_NUMBER);
  node->value.number = x;
  return node;
}

extern "C" struct ast *ast_new_sum(struct ast *a, struct ast *b)
{
  struct ast *node = new_ast(AST_TYPE_SUM);
  node->value.sum.a = a;
  node->value.sum.b = b;
  return node;
}

extern "C" struct ast *ast_new_subtraction(struct ast *a, struct ast *b)
{
  struct ast *node = new_ast(AST_TYPE_SUBTRACTION);
  node->value.subtraction.a = a;
  node->value.subtraction.b = b;
  return node;
}

extern "C" struct ast *ast_new_product(struct ast *a, struct ast *b)
{
  struct ast *node = new_ast(AST_TYPE_PRODUCT);
  node->value.product.a = a;
  node->value.product.b = b;
  return node;
}

extern "C" struct ast *ast_new_quote(struct ast *a, struct ast *b)
{
  struct ast *node = new_ast(AST_TYPE_QUOTE);
  node->value.quote.a = a;
  node->value.quote.b = b;
  return node;
}

extern "C" struct ast *ast_new_negation(struct ast *a)
{
  struct ast *node = new_ast(AST_TYPE_NEGATION);
  node->value.negation = a;
  return node;
}

extern "C" void ast_free(struct ast *a)
{
}

extern "C" double ast_eval(struct ast *a)
{
  switch(a->node_type) {
    case AST_TYPE_NUMBER: {
      return a->value.number;
    }
    case AST_TYPE_SUM: {
      return ast_eval(a->value.sum.a) + ast_eval(a->value.sum.b);
    }
    case AST_TYPE_SUBTRACTION: {
      return ast_eval(a->value.subtraction.a) - ast_eval(a->value.subtraction.b);
    }
    case AST_TYPE_PRODUCT: {
      return ast_eval(a->value.product.a) * ast_eval(a->value.product.b);
    }
    case AST_TYPE_QUOTE: {
      return ast_eval(a->value.quote.a) / ast_eval(a->value.quote.b);
    }
    case AST_TYPE_NEGATION: {
      return -ast_eval(a->value.negation);
    }
      default: std::cout << "error: unhandled node type " << a->node_type << std::endl;
      return NAN;
    }
}

 
