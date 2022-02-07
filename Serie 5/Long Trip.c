#include <stdio.h>
#include <math.h>

long int paths = 1;
void zarb(long int x) {
    paths *= x;
}

long int factorial(int num) {
    long int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

long int cal(long int x, long int y) {
    long int result = 1;
    result *= factorial(x + y);
    result /= (factorial(x) * factorial(y));
    
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int storage[n][2];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &storage[i][0], &storage[i][1]);
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pow(storage[i][0], 2) + pow(storage[i][1], 2) > pow(storage[j][0], 2) + pow(storage[j][1], 2)) {
                int temp[2];
                temp[0] = storage[i][0];
                temp[1] = storage[i][1];
                storage[i][0] = storage[j][0];
                storage[i][1] = storage[j][1];
                storage[j][0] = temp[0];
                storage[j][1] = temp[1];
            }
        }
    }
    
    int cx = 0; 
    int cy = 0;
    for (int i = 0; i < n; i++) {
        int dx = storage[i][0] - cx;
        int dy = storage[i][1] - cy;
        
        long int cPaths = cal(dx, dy);
        zarb(cPaths);
        
        cx = storage[i][0];
        cy = storage[i][1];
    }
    
    printf("%ld", paths);

    return 0;
}