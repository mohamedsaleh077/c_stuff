// https://codeforces.com/problemset/problem/96/A

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){

    char buffer[101] = {0};
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';


    int ones_repeats = 0;
    int zeros_repeats = 0;
    int cursor = 0;
    int dangerous= false;
    while(true){
        if(buffer[cursor] == '1'){
            ones_repeats++;
            zeros_repeats = 0;
        }
        if(buffer[cursor] == '0'){
            zeros_repeats++;
            ones_repeats = 0;
        }
        if(ones_repeats == 7 || zeros_repeats == 7){
            dangerous = true;
            break;
        }
        if(buffer[cursor] == '\0'){
            break;
        }
        cursor++;
    }
    
    if(dangerous == false){
        printf("NO");
    }else{
        printf("YES");
    }

    return 0;
}