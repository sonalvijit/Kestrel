mod_ty make_module(Parser *p, stmt_ty stmt) {
     printf("Parsed module with a statement\n");
     return NULL;
 }
 
 stmt_ty make_let_stmt(Parser *p, char* name, expr_ty value) {
     printf("Variable %s initialized\n", name);
     return NULL;
 }
 
 expr_ty make_binop(Parser *p, expr_ty left, char* op, expr_ty right) {
     printf("Binary operation\n");
     return NULL;
 }
 