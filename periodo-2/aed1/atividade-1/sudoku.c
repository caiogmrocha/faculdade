#include <stdio.h>

int checkLine(int matrix[9][9], int line);
int checkColumn(int matrix[9][9], int column);

int main() {
    int q;

    scanf("%d", &q);

    int matrix[q][9][9];

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 9; j++)
            for (int k = 0; k < 9; k++)
                scanf("%d", &matrix[i][j][k]);

        int valid = 1;

        for (int j = 0; j < 9; j++) {            
            if (!checkLine(matrix[i], j) || !checkColumn(matrix[i], j))
                valid = 0;
        }
        
        printf("Instancia %d\n", i+1);

        if (valid)
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
    }
                    


    return 0;
}

int checkLine(int matrix[9][9], int line) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (matrix[line][i] == matrix[line][j] && i != j)
                return 0;
        }
    }

    return 1;
}

int checkColumn(int matrix[9][9], int column) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (matrix[i][column] == matrix[j][column] && i != j)
                return 0;
        }
    }

    return 1;
}