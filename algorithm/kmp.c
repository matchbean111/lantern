#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix_table(char pattern[], int prefix[], int n) {
    prefix[0] = 0;
    int len = 0;
    int i = 1;

    while (i < n) {
        printf("i = %d, len = %d\n",i,len);
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = prefix[len - 1];
            } else {
                prefix[i] = len;
                i++;
            }
        }
    }
}

void move_prefix_table(int prefix[], int n){
    int i;
    for (i=n-1; i>0; i--) {
        prefix[i] = prefix[i-1];
    }
    prefix[0] = -1;
}

void kmp_search(char text[], char pattern[]) {
    int n = strlen(pattern);
    int* prefix = malloc(sizeof(int) * n);
    prefix_table(pattern,prefix,n);
    move_prefix_table(prefix,n);
    int m = strlen(text);


    int i = 0;
    int j = 0;
    while (i < m) {
        if (j == n-1 && text[i] == pattern[j]){
            printf("Found pattern at %d\n", i-j);
            j = prefix[j];
        }
        if (text[i] = pattern[j]) {
            i++;j++;
        } else {
            j = prefix[j];
            if (j == -1) {
                i++;j++;
            }
        }
    }
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    char text[] = "ababababcabaab";
    char pattern[] = "ababcabaa";

    kmp_search(text, pattern);

    // int prefix[9];
    // int n = 9;
    // prefix_table(pattern, prefix, n);
    // move_prefix_table(prefix, n);
    

    // printArr(prefix, n);
    // printf("%s %s %s\n",s,t, a);

    return 0;
}