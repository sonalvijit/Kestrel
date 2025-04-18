#include <stdlib.h>

typedef enum{
     NODE_NUMBER,
     NODE_BINARY_OP
} NodeType;

typedef enum{
     OP_ADD,
     OP_SUB,
     OP_MUL,
     OP_DIV
} OperatorType;

typedef struct ASTNode{
     NodeType type;
     union{
          struct{
               int value;
          } number;

          struct{
               OperatorType op;
               struct ASTNode* left;
               struct ASTNode* right;
          } binary;
     };
} ASTNode;

ASTNode* create_number(int value){
     ASTNode* node = malloc(sizeof(ASTNode));
     node->type = NODE_NUMBER;
     node->number.value = value;
     return node;
}

ASTNode* create_binary_op(OperatorType op, ASTNode* left, ASTNode* right){
     ASTNode* node = malloc(sizeof(ASTNode));
     node->type = NODE_BINARY_OP;
     node->binary.op = op;
     node->binary.left = left;
     node->binary.right = right;
     return node;
}

int eval(ASTNode* node){
     if(node->type == NODE_NUMBER) return node->number.value;
     else if(node->type == NODE_BINARY_OP){
          int left = eval(node->binary.left);
          int right = eval(node->binary.right);
          switch(node->binary.op){
               case OP_ADD: return left + right;
               case OP_SUB: return (left > right) ? left - right : right - left;
               case OP_MUL: return left * right;
               case OP_DIV: return (left > right) ? left / right : right / left;
          }
     }
     return 0;
}

int main() {
     ASTNode* three = create_number(3);
     ASTNode* four = create_number(4);
     ASTNode* five = create_number(5);
 
     ASTNode* plus = create_binary_op(OP_ADD, three, four);       // 3 + 4
     ASTNode* times = create_binary_op(OP_MUL, plus, five);       // (3 + 4) * 5
 
     int result = eval(times); // Result should be 35
     printf("Result: %d\n", result);
 
     // (Freeing omitted for brevity)
     return 0;
 }
 