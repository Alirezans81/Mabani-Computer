#include <stdio.h>

int main()
{
    int t1, t2, t3;
    scanf("%d %d %d", &t1, &t2, &t3);
    
    int s = t1 * t2 * t3;
    
    for (int i = 0; i < s; i++) {
        if (i % t1 == 0 && i % t2 == 0 && i % t3 == 0 && i != 0) {
            s = i;
        }
    }
    
    printf("%d", s);

    return 0;
}