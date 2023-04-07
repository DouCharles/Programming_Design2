#include "sudoku.h"

int main() {

    Sudoku sol;
    int num = 0;
    int c = 0;
    int *p=&sol.form[0][0];
    //輸入數獨題目
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sol.form[i][j];
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sol.form[i][j] != 0) {
                num++;
            }
        }
    }
    if (num < 17) {
        cout << "2\n";
        return 0;
    }
    //逐一找解
    c= sol.solve(p);
    while (c!=0) {
        c=0;
        c=sol.solve(p);
    }
    num = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sol.form[i][j] != 0) {
                num++;
            }
        }
    }
    if (num==81) {
        cout <<"1\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout <<*(p+9*i+j);
                if (j!=8)
                    cout<<" ";
            }
            cout << "\n";

        }
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (sol.form[i][j] != 0) {
                sol.row[i][sol.form[i][j]-1] = 1;
                sol.col[j][sol.form[i][j]-1] = 1;
                sol.cell[i / 3][j / 3][sol.form[i][j]-1] = 1;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sol.form[i][j] == 0) {
                for (int l = 1; l < 10; l++) {
                    sol.form[i][j]=l;
                    if (sol.solution[i][j][l] == 0&&sol.checkplace(i,j,p)) {
                        sol.row[i][*(p + 9 * i + j) - 1] = 1;
                        sol.col[j][*(p + 9 * i + j) - 1] = 1;
                        sol.cell[i / 3][j / 3][*(p + 9 * i + j) - 1] = 1;
                        sol.backtrace(i, j, p);
                        sol.row[i][*(p + 9 * i + j) - 1] = 0;
                        sol.col[j][*(p + 9 * i + j) - 1] = 0;
                        sol.cell[i / 3][j / 3][*(p + 9 * i + j) - 1] = 0;
                    }
                }
            }
        }
    }
    return 0;
}
