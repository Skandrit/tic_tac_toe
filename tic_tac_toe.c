#include <stdio.h>

int main() {
    int n = 0, t = 0, x, y, win;
    char c;
    char massiv[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            massiv[i][j] = '.';
        }
    }
    while (n == 0) {
        printf("  1 2 3\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i + 1);
            for (int j = 0; j < 3; j++) {
                printf("%c ", massiv[i][j]);
            }
            printf("\n");
        }
        if (t % 2 == 0) {
            printf("игрок 1 (X)\n");
        } else {
            printf("игрок 2 (O)\n");
        }
        printf("введи координату клетки:");

        if (scanf("%d %d", &x, &y) != 2) {
            printf("введи норм координаты\n");
            return 1;
        }
        if (x < 1 || x > 3 || y < 1 || y > 3) {
            printf("неверные координаты\n");
            continue;
        }
        if (massiv[x - 1][y - 1] != '.') {
            printf("клетка занята\n");
            continue;
        }
        t++;
        if (t % 2 == 1) {
            c = 'X';
        } else {
            c = 'O';
        }
        massiv[x - 1][y - 1] = c;

        win = 0;
        for (int i = 0; i < 3; i++) {
            if (massiv[i][0] == c &&
                massiv[i][1] == c &&
                massiv[i][2] == c) {
                win = 1;
            }
            if (massiv[0][i] == c &&
                massiv[1][i] == c &&
                massiv[2][i] == c) {
                win = 1;
            }
        }
        if (massiv[0][0] == c &&
            massiv[1][1] == c &&
            massiv[2][2] == c) {
            win = 1;
        }
        if (massiv[0][2] == c &&
            massiv[1][1] == c &&
            massiv[2][0] == c) {
            win = 1;
        }
        if (win == 1) {
            if (t % 2 == 1) {
                n = 1;
            } else {
                n = 2;
            }
        } else if (t == 9) {
            n = 3;
        }
    }
    if (n == 1) {
        printf("игрок 1 выиграл\n");
    } else if (n == 2) {
        printf("игрок 2 выиграл\n");
    } else if (n == 3) {
        printf("ничья\n");
    }
    return 0;
}
