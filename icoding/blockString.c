#include "dsstring.h"// 请不要删除，否则检查不通过
#include <stdlib.h>
#include <string.h>

bool init(BLString *src, int len) {
    if (src == NULL) {
        src == (BLString *) malloc(sizeof(BLString));
    }
    blstr_init(src);
    src->len = len;
    if (len == 0) {
        return src;
    }
    int block = len / BLOCK_SIZE;
    int offset = len % BLOCK_SIZE;
    src->head = (BLString *) malloc(sizeof(BLString) * block);
    memset(src->head->ch, BLS_BLANK, sizeof(char) * BLOCK_SIZE);
    src->head->next = NULL;
    src->tail = src->head;
    Block *cnt = src->head;
    for (int i = 0; i < block; i++) {
        if (i == block - 1 && offset == 0) {
            break;
        }
        Block *p = (Block *) malloc(sizeof(Block));
        memset(p->ch, BLS_BLANK, sizeof(char) * BLOCK_SIZE);
        p->next = NULL;
        cnt->next = p;
        cnt = cnt->next;
    }
    src->tail = cnt;
    return src;
}


bool blstr_substr(BLString src, int pos, int len, BLString *sub) {
    if (len == 0)
        return false;
    if (pos > src.len || pos < 0) {
        return false;
    }
    if (pos + len >= src.len) {
        len = src.len - pos;
    }
    init(sub, len);
    Block *cnt = src.head, *cnt1 = sub->head;
    int offset = pos % BLOCK_SIZE, offset1 = 0;
    for (int i = 0; i < pos / BLOCK_SIZE; ++i) {
        cnt = cnt->next;
    }
    while (len-- && cnt->ch[offset] != BLS_BLANK) {
        cnt1->ch[offset1++] = cnt->ch[offset++];
        if (offset == BLOCK_SIZE) {
            cnt = cnt->next;
            offset = 0;
        }
        if (offset1 == BLOCK_SIZE) {
            cnt1 = cnt1->next;
            offset1 = 0;
        }
    }
    return true;
}