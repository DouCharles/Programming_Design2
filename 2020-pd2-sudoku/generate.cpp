#include "sudoku.h"

int main() {
    Sudoku g;
    int k[9][9] = {
        {0, 9, 4, 0, 0, 0, 8, 3, 0},
        {0, 0, 2, 3, 0, 6, 7, 4, 0},
        {0, 5, 7, 2, 8, 0, 1, 0, 0},
        {2, 0, 0, 4, 0, 0, 0, 0, 0},
        {5, 0, 1, 7, 6, 0, 4, 2, 9},
        {0, 0, 0, 9, 2, 8, 0, 6, 0},
        {1, 3, 0, 0, 0, 0, 9, 8, 0},
        {0, 4, 6, 8, 3, 1, 0, 5, 0},
        {0, 0, 8, 0, 0, 0, 0, 0, 0}
    };

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            g.form[i][j]=k[i][j];
        }
    }
    srand(time(NULL));
    int x = rand() % 3;
    int y = rand() % 3;
    while (x==y) {
        x = rand() % 3;
        y = rand() % 3;
    }
    g.generate(x,y);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << g.form[i][j];
            if (j!=8)
                cout << " ";
        }
        if (i!=8)
            cout << "\n";
    }

    return 0;
}
