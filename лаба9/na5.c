#include <stdio.h>
#include <stdlib.h>

int findFirstZero(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= 0; j--) {
            if (matrix[i][j] == 0) return i * size + j;
        }
    }
    return -1;
}

void transposeSquare(int **matrix, int size, int startRow, int startCol, int squareSize) {
    for (int i = 0; i < squareSize; i++) {
        for (int j = 0; j < squareSize; j++) {
            int temp = matrix[startRow + i][startCol + j];
            matrix[startRow + i][startCol + j] = matrix[startRow + j][startCol + squareSize - 1 - i];
            matrix[startRow + j][startCol + squareSize - 1 - i] = temp;
        }
    }
}

int main() {
    int size;
    scanf("%d", &size);

    int matrix = (int )malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) matrix[i] = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int zeroIndex = findFirstZero(matrix, size);
    if (zeroIndex != -1) {
        int zeroRow = zeroIndex / size;
        int zeroCol = zeroIndex % size;
        int squareSize = 1;
        while (zeroRow + squareSize <= size && zeroCol - squareSize + 1 >= 0) squareSize++;
        squareSize--;
        transposeSquare(matrix, size, zeroRow, zeroCol - squareSize + 1, squareSize);
    }

    int zeroCount = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 0) zeroCount++;
        }
    }
    printf("Количество нулей:%d\n", zeroCount);

    if (zeroCount > size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] == 0) matrix[i][j] = size;
            }
        }
        zeroIndex = findFirstZero(matrix, size);
        if (zeroIndex != -1) {
            int zeroRow = zeroIndex / size;
            int zeroCol = zeroIndex % size;
            int squareSize = 1;
            while (zeroRow + squareSize <= size && zeroCol - squareSize + 1 >= 0) squareSize++;
            squareSize--;
            transposeSquare(matrix, size, zeroRow, zeroCol - squareSize + 1, squareSize);
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    for (int i = 0; i < size; i++) free(matrix[i]);
    free(matrix);

    return 0;
}