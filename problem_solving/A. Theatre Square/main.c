// https://codeforces.com/problemset/problem/1/A

#include <stdio.h>
#include <stdbool.h>

int main(){
    unsigned long long int n = 0;
    unsigned long long int m = 0;
    unsigned long long int a = 0;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &a);

    unsigned long long int theater_area = n * m;
    unsigned long long int flagstone_area = a * a;
    
    unsigned long long int flagstone_amount = 1;

    if(!(flagstone_area > theater_area)){
        flagstone_amount = theater_area / flagstone_area;
    }

    if(theater_area > (flagstone_amount * flagstone_area)){
        if(theater_area % flagstone_area > 0 ){
            flagstone_amount++;
        }

        if(theater_area != (flagstone_amount * flagstone_area)){
            while(true){
                if(flagstone_amount % 4 == 0){
                    break;
                }
                flagstone_amount++;
            }
        }

    }


    if(a == 1 && n == m){
        printf("%llu", n * m);
    }else{  
        printf("%ld", flagstone_amount);
    }

    return 0;
}