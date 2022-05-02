#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过


void pre_order(BiTree root){
    Stack S[Stack_Size];
    BiTree T = root;
    init_stack(S);
    while(T || !is_empty(S)){
        while(T){
            visit_node(T);
            push(S, T);
            T = T->left;
        }
        pop(S,&T);
        T = T->right;
    }
}