#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7
#define MAX_MOVE 100

typedef struct Puzzle_t {
    int array[MAX_SIZE][MAX_SIZE];
    int size;
    int empty_row, empty_col;
} Puzzle;

typedef struct History_t {
    char keys[MAX_MOVE];
    int size;
} History;

void printPuzzle(Puzzle puzzle) {
    int i, j;
    for (i = 0; i < 3 * puzzle.size + 1; i++) printf("*");
    for (i = 0; i < puzzle.size; i++) {
        printf("\n*");
        for (j = 0; j < puzzle.size; j++) {
            if (puzzle.array[i][j] == 0) {
                printf("  *");
            } else {
                printf("%2d*", puzzle.array[i][j]);
            }
        }
    }
    printf("\n");
    for (i = 0; i < 3 * puzzle.size + 1; i++) printf("*");
    printf("\n");
}

int movePuzzle(Puzzle *puzzle, char moveKey) {
    int emptyRow = puzzle->empty_row;
    int emptyCol = puzzle->empty_col;
    switch (moveKey) {
        case 'U':
            if (emptyRow == 0) {
                printf("Khong len duoc. ");
                return 0;
            }
            else {
                puzzle->array[emptyRow][emptyCol] =
                    puzzle->array[emptyRow - 1][emptyCol];
                (emptyRow)--;
            }
            break;
        case 'D':
            if (emptyRow == puzzle->size - 1) {
                printf("Khong xuong duoc. ");
                return 0;
            }
            else {
                puzzle->array[emptyRow][emptyCol] =
                    puzzle->array[emptyRow + 1][emptyCol];
                (emptyRow)++;
            }
            break;
        case 'R':
            if (emptyCol == puzzle->size - 1) {
                printf("Khong sang phai duoc. ");
                return 0;
            }
            else {
                puzzle->array[emptyRow][emptyCol] =
                    puzzle->array[emptyRow][emptyCol + 1];
                (emptyCol)++;
            }
            break;
        case 'L':
            if (emptyCol == 0) {
                printf("Khong sang trai duoc. ");
                return 0;
            }
            else {
                puzzle->array[emptyRow][emptyCol] =
                    puzzle->array[emptyRow][emptyCol - 1];
                (emptyCol)--;
            }
            break;
        default:
            printf("Nhap sai thao tac. ");
            return 0;
            break;
    }
    puzzle->empty_row = emptyRow;
    puzzle->empty_col = emptyCol;
    puzzle->array[emptyRow][emptyCol] = 0;
    printPuzzle(*puzzle);
    return 1;
}

int checkDuplicate(Puzzle puzzle, int value, int i, int j) {
    int m, n;
    for (m = 0; m < i; m++) {
        for (n = 0; n < puzzle.size; n++) {
            if (value == puzzle.array[m][n]) return 1;
        }
    }
    for (n = 0; n < j; n++) {
        if (value == puzzle.array[i][n]) return 1;
    }
    return 0;
}

void pushHistory(History *rollback, char move_key) {
    rollback->keys[rollback->size] = move_key;
    rollback->size++;
}

char popHistory(History *rollback) { return rollback->keys[--rollback->size]; }

char reverseKey(char key) {
    if (key == 'U')
        return 'D';
    else if (key == 'D')
        return 'U';
    else if (key == 'L')
        return 'R';
    else if (key == 'R')
        return 'L';
    return '?';
}

void clearBuffer() {
    while ((getchar()) != '\n')
        ;
}

void clearConsole() {
    while ((getchar()) != '\n')
        ;
    char temp;
    printf("Nhap phim bat ky de thoat.");
    scanf("%c", &temp);
    system("clear");
}

int main() {
    // Init variable
    Puzzle puzzle;
    puzzle.size = -1;
    int i, j;     // index for loop
    int intTemp;  // temp interger
    char moveKey;
    History rollback;
    rollback.size = 0;
    int rollbackTimes;

    int control;  // control menu
    do {
        printf("=========================\n");
        printf("--------- PUZZLE --------\n");
        printf("=========================\n");
        printf("1 -> Nhap co cua cau hinh.\n");
        printf("2 -> Nhap gia tri cua cau hinh.\n");
        printf("3 -> Nhap cac buoc di.\n");
        printf("4 -> \n");
        printf("5 -> In cau hinh tro choi.\n");
        printf("6 -> Thoat chuong trinh.\n");
        printf("=========================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &control);
        switch (control) {
            case 1:
                // 1
                printf("Nhap co cua cau hinh game [3,7]: ");
                scanf("%d", &puzzle.size);
                while (puzzle.size < 3 || puzzle.size > 7) {
                    printf(
                        "Gia tri cua co nam trong doan [3,7].\nXin moi nhap "
                        "lai: ");
                    scanf("%d", &puzzle.size);
                }
                clearConsole();
                break;
            case 2:
                // 2
                if (puzzle.size < 0) {
                    printf("Phai nhap gia tri co cau hinh truoc.");
                    break;
                }
                for (i = 0; i < puzzle.size; i++) {
                    for (j = 0; j < puzzle.size; j++) {
                        do {
                            printf("Nhap gia tri cua o [%d][%d]: ", i + 1,
                                   j + 1);
                            scanf("%d", &intTemp);
                        } while (intTemp < 0 ||
                                 intTemp >= puzzle.size * puzzle.size ||
                                 checkDuplicate(puzzle, intTemp, i, j));
                        puzzle.array[i][j] = intTemp;
                        if (intTemp == 0) {
                            puzzle.empty_row = i;
                            puzzle.empty_col = j;
                        }
                    }
                }
                clearConsole();
                break;
            case 3:
                // 3
                clearBuffer();
                printf("Nhap di chuyen [UDRL]: ");
                scanf("%c", &moveKey);
                while (!movePuzzle(&puzzle, moveKey)) {
                    printf("Xin moi nhap lai (UDRL): ");
                    clearBuffer();
                    scanf("%c", &moveKey);
                };
                pushHistory(&rollback, moveKey);
                clearConsole();
                break;
            case 4:
                // 4
                printf("Nhap so lan rollback: ");
                scanf("%d", &rollbackTimes);
                while (rollbackTimes < 0 || rollbackTimes > rollback.size) {
                    printf("So lan rollback khong hop le.\nXin moi nhap lai: ");
                    scanf("%d", &rollbackTimes);
                }
                while (rollbackTimes--) {
                    movePuzzle(&puzzle, reverseKey(popHistory(&rollback)));
                }
                clearConsole();
                break;
            case 5:
                // 5
                printPuzzle(puzzle);
                clearConsole();
                break;
            case 6:
                // End Program
                printf("Ket thuc chuong trinh.\n");
                return 0;
                break;
            default:
                // continue
                break;
        }
    } while (control != 6);
}
