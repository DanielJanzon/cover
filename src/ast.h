#ifndef AST_H
#define AST_H

#ifdef __cplusplus
#define CLINKAGE extern "C"
#else
#define CLINKAGE
#endif

enum ast_node_t { AST_TYPE_NUMBER, AST_TYPE_SUM, AST_TYPE_SUBTRACTION,
                  AST_TYPE_PRODUCT, AST_TYPE_QUOTE, AST_TYPE_NEGATION };

CLINKAGE struct ast *ast_new_number(double x);
CLINKAGE struct ast *ast_new_sum(struct ast *a, struct ast *b);
CLINKAGE struct ast *ast_new_subtraction(struct ast *a, struct ast *b);
CLINKAGE struct ast *ast_new_product(struct ast *a, struct ast *b);
CLINKAGE struct ast *ast_new_quote(struct ast *a, struct ast *b);
CLINKAGE struct ast *ast_new_negation(struct ast *a);

CLINKAGE void ast_free(struct ast *a);

struct ast_binary_op {
  struct ast *a;
  struct ast *b;
};

union ast_value {
  double number;
  struct ast_binary_op sum;
  struct ast_binary_op subtraction;
  struct ast_binary_op product;
  struct ast_binary_op quote;
  struct ast *negation;
};

struct ast {
  enum ast_node_t node_type;
  union ast_value value;
  struct ast *next;
};


#endif
