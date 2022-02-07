#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

////>>>> tools

//-- returing a random number between two numbers
int randomgen(int lower, int upper) {
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

//-- making a distance array like this:(parameters be 0 and 0)
// 0  1  2
// 1  1  2
// 2  2  2
int distance[3][3];
void distanceArray(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int dx = x - i;
            if (dx < 0) dx *= -1;
            int dy = y - j;
            if (dy < 0) dy *= -1;
            
            if (dx < dy) distance[i][j] = dy;
            else distance[i][j] = dx;
            
            if (distance[i][j] < 0) distance[i][j] *= -1;
        }
    }
}

////>>>> board functions

//-- clearing the board with putting <<->> in every cell
void clearBoard() {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = '-';
        }
    }
}

// printing the board in console
void show() {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// checking if anyone has won
int checkBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') {
                distanceArray(i, j);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (distance[k][l] == 1 && board[k][l] == 'x') {
                            int dx = k - i;
                            int dy = l - j;
                            dx = i - dx;
                            dy = j - dy;
                            if (board[dx][dy] == 'x' && dx >= 0 && dy >= 0 && dx <= 2 && dy <= 2) return 1;
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'y') {
                distanceArray(i, j);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (distance[k][l] == 1 && board[k][l] == 'y') {
                            int dx = k - i;
                            int dy = l - j;
                            dx = i - dx;
                            dy = j - dy;
                            if (board[dx][dy] == 'y' && dx >= 0 && dy >= 0 && dx <= 2 && dy <= 2) return 2;
                        }
                    }
                }
            }
        }
    }
    
    int isFull = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') isFull = 0;
        }
    }
    if (isFull == 1) return -1;

    return 0;
}

////>>>> making move functions

//-- computer
void putX() {
    int hasPlayed = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 'x') {
                distanceArray(i, j);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (distance[k][l] == 1 && board[k][l] == 'x') {
                            int dx = k - i;
                            int dy = l - j;
                            dx = i - dx;
                            dy = j - dy;
                            if (board[dx][dy] == '-' && hasPlayed == 0 && dx >= 0 && dy >= 0 && dx <= 2 && dy <= 2) {
                                board[dx][dy] = 'x';
                                hasPlayed = 1;
                            }
                        }

                        if (distance[k][l] == 2 && board[k][l] == 'x') {
                            if (((float)(i + k) / 2) == ((i + k) / 2) && ((float)(j + k) / 2) == ((i + k) / 2)) {
                                int dx = (i + k) / 2;
                                int dy = (j + l) / 2;
                                if (board[dx][dy] == '-' && hasPlayed == 0) {
                                    board[dx][dy] = 'x';
                                    hasPlayed = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 'y') {
                distanceArray(i, j);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (distance[k][l] == 1 && board[k][l] == 'y') {
                            int dx = k - i;
                            int dy = l - j;
                            dx = i - dx;
                            dy = j - dy;
                            if (board[dx][dy] == '-' && hasPlayed == 0 && dx >= 0 && dy >= 0 && dx <= 2 && dy <= 2) {
                                board[dx][dy] = 'x';
                                hasPlayed = 1;
                            }
                        }

                        if (distance[k][l] == 2 && board[k][l] == 'y') {
                            if (((float)(i + k) / 2) == ((i + k) / 2) && ((float)(j + k) / 2) == ((i + k) / 2)) {
                                int dx = (i + k) / 2;
                                int dy = (j + l) / 2;
                                if (board[dx][dy] == '-' && hasPlayed == 0) {
                                    board[dx][dy] = 'x';
                                    hasPlayed = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (hasPlayed == 0 && board[1][1] == '-') {
        board[1][1] = 'x';
        hasPlayed = 1;
    }
    
    if (hasPlayed == 0) {
        int x = -1;
        int y = -1;
        int condition = 1;
        do {
            x = randomgen(0, 2);
            y = randomgen(0, 2);

            distanceArray(x, y);
            int isfound = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (distance[i][j] == 1 && board[i][j] != '-') {
                        isfound = 1;

                        int dx = i - x;
                        int dy = j - y;
                        dx = x - dx;
                        dx = y - dx;
                        if (board[dx][dy] == '-' && dx >= 0 && dy >= 0 && dx <= 2 && dy <= 2) condition = 0;
                    }
                }
            }
            if (isfound == 0) condition = 0;

        } while(board[x][y] != '-' && condition == 1);
        
        board[x][y] = 'x';
    }
}

//-- user
void putY(int x,int y) {
    if (board[x][y] == '-') board[x][y] = 'y';
}

////>>>> determining the turn and the winner

int main()
{
    clearBoard();
    
    int random = 25;
    while (random == 25) {
        random = randomgen(1, 50);
    }
    
    int who_is_first = 0;
    if (random < 25) who_is_first = 1; //computer
    if (random > 25) who_is_first = 2; //user
    
    do {
        system("clear");
        
        if (who_is_first == 1) {
            putX();
            
            if (checkBoard() == 0) {
                show();
                int x = -1;
                int y = -1;
                printf("Enter coordinates of your choice.\nx(from 0 to 2): ");
                scanf("%d", &x);
                printf("y(from 0 to 2): ");
                scanf("%d", &y);
                putY(x, y);
            }
        }
        
        if (who_is_first == 2) {
            show();
            int x = -1;
            int y = -1;
            printf("Enter coordinates of your choice.\nx(from 0 to 2): ");
            scanf("%d", &x);
            printf("y(from 0 to 2): ");
            scanf("%d", &y);
            putY(x, y);
            
            if (checkBoard() == 0) {
                putX();
            }
            
            printf("%d \n", checkBoard());
        }
        
    } while (checkBoard() == 0);
    
    system("clear");
    show();
    
    if (checkBoard() == 1) printf("You lost!");
    if (checkBoard() == 2) printf("You won!");
    if (checkBoard() == -1) printf("Draw!");

    return 0;
}