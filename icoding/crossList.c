#include "crosslist.h"
#include <stdio.h>
#include <stdlib.h>

int init_cross_list(PCrossList L, const ElemType* A, int m, int n)
{
    int i, j, k;
    OLink q, p;
    L->rows = m;
    L->cols = n;
    L->nums = 0;
    if (!(L->rowhead = (OLink*)malloc((m + 1) * sizeof(OLink))))
        return 0;
    if (!(L->colhead = (OLink*)malloc((n + 1) * sizeof(OLink))))
        return 0;
    for (i = 0; i <= m; i++)
        L->rowhead[i] = NULL;
    for (i = 0; i <= n; i++)
        L->colhead[i] = NULL;
    for (i = 0; i < m * n; i++) {
        if (A[i] == 0)
            ;
        else {
            if (!(p = (OLNode*)malloc(sizeof(OLNode))))
                return 0;
            p->row = (i / n)+1;
            p->col = (i % n)+1;
            int temp = i%n;
            p->value = A[i];
            p->right = NULL;
            L->nums++;
            p->down = NULL;
            if (L->rowhead[p->row-1] == NULL)
                L->rowhead[p->row-1] = p;
            else {
                q = L->rowhead[p->row-1];
                while (q->right != NULL)
                    q = q->right;
                q->right = p;
            }
            if (L->colhead[temp] == NULL)
                L->colhead[temp] = p;
            else {
                q = L->colhead[temp];
                while (q->down != NULL)
                    q = q->down;
                q->down = p;
            }
        }
    }
    return L->nums;
}
int del_cross_list(PCrossList L, ElemType k)
{
    int count = 0;
    for (int i = 0; i < L->rows; ++i) {
        OLink p = L->rowhead[i];
        while (p) {
            if (p->value == k) {
                OLink q;
                for (q = L->rowhead[i]; q != p && q->right != p; q = q->right) {
                }

                if (q == p) {
                    L->rowhead[i] = p->right;
                    p = L->rowhead[i];
                    count++;
                    continue;
                } else {
                    OLink tmp = q->right;
                    q->right = p->right;
                    p = p->right;
                    count++;
                    continue;
                }
            }
            p = p->right;
        }
    }
    for (int i = 0; i < L->cols; ++i) {
        OLink p = L->colhead[i];
        while (p != NULL) {
            if (p->value == k) {
                OLink q;
                for (q = L->colhead[i]; q != p && q->down != p; q = q->down) {
                }
                if (q == p) {
                    L->colhead[i] = p->down;
                    p = L->colhead[i];
                    free(q);
                    continue;
                } else {
                    OLink tmp = q->down;
                    q->down = p->down;
                    p = p->down;
                    free(tmp);
                    continue;
                }
            }
            p = p->down;
        }
    }
    return count;
}