#include <stdio.h>

int main() {
    
    int x,n,final_score;
    
    scanf("%d %d", &x, &n);
    
    if (n == 7) {
        final_score = x;
    } else if(n == 0) {
        final_score = 20;
    } else {
        final_score = x - n;
    }
    
    if (final_score < 0) {
        final_score = 0; 
    }
    
    printf("%d", final_score);
    
    return 0;
}