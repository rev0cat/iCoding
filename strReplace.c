#include "dsstring.h"
#include <stdio.h>
#include <stdlib.h>

void *Memset(void *s, int c, size_t n) {
    char *p = (char *) s;
    while (n--)
        *p++ = c;
    return s;
}
char *Strncat(char *dest, const char *src, int num) {
    char *p = dest;
    while (*p)
        p++;
    while (num--)
        *p++ = *src++;
    *p = '\0';
    return dest;
}

char *Strcat(char *dest, const char *src) {
    char *p = dest;
    while (*p)
        p++;
    while (*src)
        *p++ = *src++;
    *p = '\0';
    return dest;
}

int Strlen(const char *str) {
    int len = 0;
    while ((*str) != '\0') {
        str++;
        len++;
    }
    return len;
}

int Strncmp(const char *s1, const char *s2, int num) {
    while (num--) {
        if (*s1 != *s2)
            return *s1 - *s2;
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return 0;
}

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr) {
    Memset(out, 0, outlen);
    int count = 0;
    for (int i = 0; i < Strlen(in); ++i) {
        if ((!Strncmp(in + i, oldstr, Strlen(oldstr))) && (Strlen(in) + (count+1)*Strlen(newstr) - (count+1)*Strlen(oldstr) + 1 <= outlen)) {
            //查找目标字符串
            Strncat(out, newstr, outlen);
            //把新字符串贴到缓冲区里
            i += Strlen(oldstr)-1;
            count++;
        } else {
            //如果没有找到
            Strncat(out, in + i, 1);
        }
        if (Strlen(out) + 1 >= outlen)
            break;
    }
    return count;
}