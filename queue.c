#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

bool init_queue(LinkQueue *LQ)
{
	(*LQ) = (LinkQueue*)malloc(sizeof(LinkQueue));
	(*LQ)->next = (*LQ);
	if ((*LQ) != NULL){
	    return 1;
	}
	return 0;
}

bool enter_queue(LinkQueue *LQ, ElemType x)
{
	LinkQueueNode* p;
	LinkQueueNode* new;
	new = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	p = (*LQ);
	if(new!=NULL){
	new->data = x;
	new->next = p->next;
	p->next = new;
	(*LQ) = new;
	return 1;
	}
	else{return 0;}
}

bool leave_queue(LinkQueue *LQ, ElemType *x)
{
	LinkQueueNode *p;
	if((*LQ)->next == (*LQ)){
	    return 0;
	}
	p = (*LQ);
	if(p->next->next == p){
	    *x = (*LQ)->data;
	    p = p->next;
	    p->next = p;
	    free (*LQ);
	    (*LQ) = p;
	}else{
	    p = p->next->next;
	    (*LQ)->next->next = p->next;
	    *x = p->data;
	    free(p);
	}
    return 1;
}