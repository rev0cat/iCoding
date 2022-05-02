#include "bitree.h"//请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool path(BiTNode* root, BiTNode* node, Stack* s){
    BiTree T = root,p = NULL;
    if(T == NULL || node == NULL|| !is_empty(s))
        return false;
    while (T||!is_empty(s)){
        while (T){
            push(s,T);
            if (T == node)
                return true;
            T = T->left;
        }
        top(s,&T);
        if (!T->right||T->right == p){
            p =T;
            pop(s,&T);
            T = NULL;
        } else{
            T = T->right;
        }
    }
    return false;
}