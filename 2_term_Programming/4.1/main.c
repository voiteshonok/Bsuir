#include <stdlib.h>
#include <stdio.h>

int getLen(char *str) {
    char *p = str;
    while (*p) {
        p++;
    }
    return p - str - 1;
}

void swap(char *a, char *b) {
    char str[81];
    int t = 0;
    while (a[t]) {
        str[t] = a[t];
        t++;
    }
    str[t] = '\0';
    t = 0;
    while (b[t]) {
        a[t] = b[t];
        t++;
    }
    a[t] = '\0';
    t = 0;
    while (str[t]) {
        b[t] = str[t];
        t++;
    }
    b[t] = '\0';
}

int main() {
    int n, curLine = 0;
    printf("how many lines?\n");
    scanf("%d", &n);
    char arr[80 * n][82];
    printf("input %d lines no longer than 80\n", n);
    char str[82];
    gets(str);
    int i;
    for (i = 0; i < n; ++i) {
        gets(str);
        int len=1+getLen(str);
        str[len]=' ';
        str[len+1]='\0';
        int ch = 0, a = -1;
        while (str[ch] != '\0') {
            if (str[ch] == ' ') {
                int j = 0, m = ch - a - 1;
                for (; j < m; ++j, ++a) {
                    arr[curLine][j] = str[a + 1];
                }
                arr[curLine][j] = '\0';
                curLine++;
                a = ch;
            }
            ch++;
        }
    }
    int j;
    for (i = 0; i < curLine - 1; ++i) {
        for (j = i + 1; j < curLine; ++j) {
            if (getLen(arr[i]) > getLen(arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (i = 0; i < curLine; ++i) {
        puts(arr[i]);
    }
    return 0;
}
