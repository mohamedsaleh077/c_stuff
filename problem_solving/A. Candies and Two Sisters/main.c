// https://codeforces.com/problemset/problem/1335/A
#include <stdio.h>

int main(){
    int t = 0;

    scanf("%d", &t);
    getchar();

    int n[t];

    for(int i = 0; i < t; i++){
        scanf("%d", &n[i]);
        getchar();
    }

    for(int i = 0; i < t; i++){
        if( n[i] % 2 == 1) // if odd
        {
            printf("%d\n", n[i] / 2);
        }

        if(n[i] % 2 == 0) // if even
        {
            printf("%d\n", (n[i] / 2) - 1);
        }
        // printf("%d\n", n[i]);
    }
}