#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nx;
    scanf("%d", &nx);
    long int xs[nx];
    for (int i = 0; i < nx; i++) {
        long int xd = 0;
        scanf("%ld", &xd);
        int isAlreadyIn = 0;
        for (int j = 0; j < i; j++) {
            if (xd == xs[j]) {
                isAlreadyIn = 1;
                i--;
            }
        }
        if (isAlreadyIn == 0) xs[i] = xd;
    }
    
    int ny;
    scanf("%d", &ny);
    long int ys[ny];
    for (int i = 0; i < ny; i++) {
        long int yd = 0;
        scanf("%ld", &yd);
        int isAlreadyIn = 0;
        for (int j = 0; j < i; j++) {
            if (yd == ys[j]) {
                isAlreadyIn = 1;
                i--;
            }
        }
        if (isAlreadyIn == 0) ys[i] = yd;
    }
    
    long int *eshterak = malloc(1 * sizeof(long int));
    int eshterakCounter = 0;
    
    long int *ejtema = malloc(1 * sizeof(long int));
    int ejtemaCounter = 0;
    
    long int *tafazol = malloc(1 * sizeof(long int));
    int tafazolCounter = 0;
    
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            if (xs[i] == ys[j]) {
                eshterak[eshterakCounter] = xs[i];
                eshterakCounter++;
                eshterak = realloc(eshterak, (eshterakCounter + 1) * sizeof(long int));
                
                ejtema[ejtemaCounter] = xs[i];
                ejtemaCounter++;
                ejtema = realloc(ejtema, (ejtemaCounter + 1) * sizeof(long int));
            }
        }
    }
    
    for (int i = 0; i < nx; i++) {
        int isAlreadyIn = 0;
        for (int j = 0; j < eshterakCounter; j++) {
            if (xs[i] == eshterak[j]) isAlreadyIn = 1;
        }
        if (isAlreadyIn == 0) {
            ejtema[ejtemaCounter] = xs[i];
            ejtemaCounter++;
            ejtema = realloc(ejtema, (ejtemaCounter + 1) * sizeof(long int));
            
            tafazol[tafazolCounter] = xs[i];
            tafazolCounter++;
            tafazol = realloc(tafazol, (tafazolCounter + 1) * sizeof(long int));
        }
    }
    for (int i = 0; i < ny; i++) {
        int isAlreadyIn = 0;
        for (int j = 0; j < eshterakCounter; j++) {
            if (ys[i] == eshterak[j]) isAlreadyIn = 1;
        }
        if (isAlreadyIn == 0) {
            ejtema[ejtemaCounter] = ys[i];
            ejtemaCounter++;
            ejtema = realloc(ejtema, (ejtemaCounter + 1) * sizeof(long int));
        }
    }
    
    int temp;
    for (int i = 0; i < ejtemaCounter - 1; i++) {
        for (int j = i + 1; j < ejtemaCounter; j++) {
            if (ejtema[i] > ejtema[j]) {
                temp = ejtema[i];
                ejtema[i] = ejtema[j];
                ejtema[j] = temp;
            }
        }
    }
    for (int i = 0; i < eshterakCounter - 1; i++) {
        for (int j = i + 1; j < eshterakCounter; j++) {
            if (eshterak[i] > eshterak[j]) {
                temp = eshterak[i];
                eshterak[i] = eshterak[j];
                eshterak[j] = temp;
            }
        }
    }
    for (int i = 0; i < tafazolCounter - 1; i++) {
        for (int j = i + 1; j < tafazolCounter; j++) {
            if (tafazol[i] > tafazol[j]) {
                temp = tafazol[i];
                tafazol[i] = tafazol[j];
                tafazol[j] = temp;
            }
        }
    }
    
    if (ejtemaCounter == 0) printf("null");
    else for (int i = 0; i < ejtemaCounter; i++) printf("%ld ", ejtema[i]);
    printf("\n");
    
    if (eshterakCounter == 0) printf("null");
    else for (int i = 0; i < eshterakCounter; i++) printf("%ld ", eshterak[i]);
    printf("\n");
    
    if (tafazolCounter == 0) printf("null");
    else for (int i = 0; i < tafazolCounter; i++) printf("%ld ", tafazol[i]);
    printf("\n");

    return 0;
}