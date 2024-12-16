#include <stdio.h>
#include <stdlib.h>
//транспонируем 
void transposeSquare(int **matrix, int size, int startRow, int startCol) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {  
            
            int temp = matrix[startRow + i][startCol + j];
            matrix[startRow + i][startCol + j] = matrix[startRow + j][startCol + i];
            matrix[startRow + j][startCol + i] = temp;
        }
    }
}
//сколько нулей и их замена
int countAndReplaceZeros(int **matrix, int rows, int cols) {
    int zeroCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }
//сама замена
    if (zeroCount > rows) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = zeroCount;  
                }
            }
        }
    }

    return zeroCount;
}

int main() {
    int rows, cols;

    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d %d", &rows, &cols);
//память на матрицу
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int zeroCount = countAndReplaceZeros(matrix, rows, cols);

    int firstZeroRow = -1, firstZeroCol = -1;
    for (int i = 0; i < rows && firstZeroRow == -1; i++) {
        for (int j = 0; j < cols && firstZeroCol == -1; j++) {
            if (matrix[i][j] == 0) {
                firstZeroRow = i;
                firstZeroCol = j;
                break;
            }
        }
    }
//если 1-й == 0
    if (firstZeroRow != -1 && firstZeroCol != -1) {
        int squareSize = (rows - firstZeroRow < cols - firstZeroCol) ? 
                         (rows - firstZeroRow) : (cols - firstZeroCol);
        transposeSquare(matrix, squareSize, firstZeroRow, firstZeroCol);
    }
//изменение
    printf("Измененная матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
//убрать память!
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("Количество нулей в исходной матрице: %d\n", zeroCount);

    return 0;
}