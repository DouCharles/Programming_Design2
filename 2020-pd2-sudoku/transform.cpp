#include "sudoku.h"
#include <cstring>
int main() {
    string a[10];
    int A, b, c;
    Sudoku su;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> su.form[i][j];
        }

    }

    scanf("%d", &A);
    scanf("%d", &b);
    if (A == 1 || A == 2 || A == 3)
        scanf("%d", &c);

    while (A != 0) {
        switch (A) {
        case 1:
            su.swapNum(b, c);
            break;
        case 2:
            su.swapRow(b, c);
            break;
        case 3:
            su.swapCol(b, c);
            break;
        case 4:
            su.rotate(b);
            break;
        case 5:
            su.flip(b);
            break;
        }
        scanf("%d", &A);
        if(A==0)
            break;
        scanf("%d", &b);
        if (A == 1 || A == 2 || A == 3)
            scanf("%d", &c);
    }

    if (A == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << su.form[i][j];
                if (j != 8)
                    cout << " ";
            }
            //if (i != 8)
            cout << endl;
        }
    }
    return 0;
}

