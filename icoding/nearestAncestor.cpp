#include "bitree.h" //请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

BiTNode* nearest_ancestor(BiTree root, BiTNode* p, BiTNode* q)
{
    Stack s1, s2;
    BiTNode* ancNode;
    init_stack(&s1);
    init_stack(&s2);

    path(root, p, &s1);
    path(root, q, &s2);

    if (s1.elem[0] != s2.elem[0])
        return NULL;

    ancNode = s1.elem[0];

    for (int i = 1; i < s1.top && i < s2.top; i++) {
        if (s1.elem[i] != s2.elem[i])
            return ancNode;
        ancNode = s1.elem[i];
    }
    return ancNode;
}