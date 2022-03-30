#include "tsmatrix.h"
#include <stdio.h>
#include <stdlib.h>

bool initMatrix(TSMatrix *src, int rows, int cols) {
    src->m = rows;
    src->n = cols;
    for (int i = 0; i < 100; ++i) {
        src->data[i].e = 0;
        src->data[i].i = 0;
        src->data[i].j = 0;
    }
}

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ) {
    if (pM->m == pN->m && pM->n == pN->n) {
        int a, b, cnt = 0, i = 0, j = 0, k = 0;
        initMatrix(pQ, pM->m, pM->n);
        for (a = 0; a < MAXSIZE; a++) {
            if (pM->data[i].e + pN->data[j].e != 0 && pM->data[i].i == pN->data[j].i && pM->data[i].j == pN->data[j].j) {
                pQ->data[k].e = pM->data[i].e + pN->data[j].e;
                pQ->data[k].i = pM->data[i].i;
                pQ->data[k].j = pM->data[i].j;
                i++;
                j++;
                k++;
                cnt++;
                continue;
            }
            if (pM->data[i].i < pN->data[j].i || (pM->data[i].i == pN->data[j].i && pM->data[i].j < pN->data[j].j)) {
                if(i >= pM->len){
                    pQ->data[k].e = pN->data[j].e;
                    pQ->data[k].i = pN->data[j].i;
                    pQ->data[k].j = pN->data[j].j;
                    cnt++;
                    j++;
                    k++;
                    continue;
                }
                pQ->data[k].e = pM->data[i].e;
                pQ->data[k].i = pM->data[i].i;
                pQ->data[k].j = pM->data[i].j;
                cnt++;
                i++;
                k++;
                continue;
            }
            if (pM->data[i].i > pN->data[j].i || (pM->data[i].i == pN->data[j].i && pM->data[i].j > pN->data[j].j)) {
                if(j >= pN->len){
                    pQ->data[k].e = pM->data[i].e;
                    pQ->data[k].i = pM->data[i].i;
                    pQ->data[k].j = pM->data[i].j;
                    cnt++;
                    i++;
                    k++;
                    continue;
                }
                pQ->data[k].e = pN->data[j].e;
                pQ->data[k].i = pN->data[j].i;
                pQ->data[k].j = pN->data[j].j;
                cnt++;
                j++;
                k++;
                continue;
            }
            if (pM->data[i].e + pN->data[j].e == 0 && pM->data[i].i == pN->data[j].i && pM->data[i].j == pN->data[j].j) {
                i++;
                j++;
                continue;
            }
        }
        pQ->len = cnt;
        return true;
    } else {
        return false;
    }
}
