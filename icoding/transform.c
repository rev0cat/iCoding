#include "bitree.h"//请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

BiTNode *transform(CSNode *root) {
    if (root == NULL)
        return NULL;

    //初始化二叉树的根节点
    BiTree broot = (BiTree) malloc(sizeof(struct Node));
    broot->data = root->data;
    broot->left = broot->right = NULL;

    //普通树、二叉树初始化、加入队列
    Queue *queue = create_queue();
    Queue *bqueue = create_queue();
    add_queue(queue, root);
    add_queue(bqueue, broot);

    while (!is_empty_queue(queue)) {
        //从普通数和二叉树中分别取出一个结点
        CSNode *node = del_queue(queue);
        BiTree bTreeNode = del_queue(bqueue);

        int i;
        BiTree former = NULL;
        //遍历普通树结点的所有孩子结点，将孩子加入队列
        for (i = 0; i < MAX_CHILDREN_NUM; i++) {
            //孩子非空
            if (node->children[i]) {
                //二叉树节点初始化并赋值
                BiTree bnode = (BiTree) malloc(sizeof(struct Node));
                bnode->left = bnode->right = NULL;
                bnode->data = node->children[i]->data;

                if (i == 0)//普通树的第一个孩子作为二叉树的左孩子
                    bTreeNode->left = bnode;
                else//后面的孩子结点作为前面结点的右孩子
                    former->right = bnode;
                former = bnode;

                add_queue(queue, node->children[i]);
                add_queue(bqueue, bnode);
            }
        }
    }
    free(queue->array);
    free(queue);
    free(bqueue->array);
    free(bqueue);
    return broot;
}