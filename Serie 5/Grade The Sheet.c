#include <stdio.h>

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    
    char shape[m][n];
    for (int i = 0; i < m; i++) {
        scanf("%s", shape[i]);
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < k; i++) {
            for (int l = 0; l < n; l++) {
                for (int s = 0; s < k; s++) printf("%c", shape[j][l]);
            }
            printf("\n");
        }
    }

    return 0;
}