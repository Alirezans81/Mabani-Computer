#include <stdio.h>

int main()
{
    char num[100] = "";
    scanf("%s", num);
    
    for (int i = 0; i < 100; i++) {
        int digitNum = -1;
        if (num[i] == '0') digitNum = 0;
        if (num[i] == '1') digitNum = 1;
        if (num[i] == '2') digitNum = 2;
        if (num[i] == '3') digitNum = 3;
        if (num[i] == '4') digitNum = 4;
        if (num[i] == '5') digitNum = 5;
        if (num[i] == '6') digitNum = 6;
        if (num[i] == '7') digitNum = 7;
        if (num[i] == '8') digitNum = 8;
        if (num[i] == '9') digitNum = 9;
        
        if (digitNum != -1) {
            printf("%d: ", digitNum);
            for (int j = 0; j < digitNum; j++) {
                printf("%d", digitNum);
            }
            printf("\n");
        }
    }

    return 0;
}