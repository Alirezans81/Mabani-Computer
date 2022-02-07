#include <stdio.h>

int main()
{
    char in;
    int g_count = 0;
    int y_count = 0;
    int r_count = 0;
    
    int i = 0;
    while (i < 10) {
        scanf("%c", &in);
        
        if (in == 'G') g_count++;
        if (in == 'Y') y_count++;
        if (in == 'R') r_count++;
        
        i++;
    }
    
    if (r_count >= 3) {
        printf("Nakhor");
    } else if (r_count >= 2 && y_count >= 2) {
        printf("Nakhor");
    } else if (g_count == 0) {
        printf("Nakhor");
    } else {
        printf("Okeye");
    }
    
    return 0;
}