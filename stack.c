#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

int compute_reverse_polish_notation(char *str){
    Stack num;
    init_stack(&num);
    int num1,num2,i=0;
    while(str[i]!='\0'){
        if(str[i]!=' '){
            if(str[i]>='0'&&str[i]<='9'){
                int pushnum = 0;
                while(str[i]!=' '){
                pushnum = pushnum * 10 + str[i] - '0';
                i++;
                }
                push(&num,pushnum);
            }else{
                pop(&num,&num2);
                pop(&num,&num1);
                switch(str[i]){
                    case '+':{
                        num1 += num2;
                        break;}
                    case '-':{
                        num1 -= num2;
                        break;}
                    case '*':{
                        num1 *= num2;
                        break;}
                    case '/':{
                        num1 /= num2;
                        break;}
                    case '%':{
                        num1 %= num2;
                        break;
                    }
                }
                push(&num,num1);
            }
        }
        i++;
    }
    pop(&num,&num1);
    return num1;
}