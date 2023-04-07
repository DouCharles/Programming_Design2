#include "sudoku.h"

Sudoku::Sudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            form[i][j] = 0;
            temp[i][j] = 0;
            row[i][j] = 0;
            col[i][j] = 0;
            for (int k = 0; k < 10; k++) {
                solution[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 9; k++) {
                cell[i][j][k] = 0;
            }
        }
    }
};

//generate
void Sudoku ::generate(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            temp[3 * x + i][j] = form[3 * x + i][j];
            form[3 * x + i][j] = form[3 * y + i][j];
            form[3 * y + i][j] = temp[3 * x + i][j];
        }
    }
};
//transform
void Sudoku ::swapNum(int x, int y) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (form[i][j] == x)
                form[i][j] = y;
            else if (form[i][j] == y)
                form[i][j] = x;
        }
    }
};
void Sudoku ::swapRow(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            temp[3 * x + i][j] = form[3 * x + i][j];
            form[3 * x + i][j] = form[3 * y + i][j];
            form[3 * y + i][j] = temp[3 * x + i][j];
        }
    }
};
void Sudoku ::swapCol(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            temp[j][3 * x + i] = form[j][3 * x + i];
            form[j][3 * x + i] = form[j][3 * y + i];
            form[j][3 * y + i] = temp[j][3 * x + i];
        }
    }
};
void Sudoku ::rotate(int x) {
    for (int k = 0; k < x; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                temp[j][8 - i] = form[i][j];
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                form[i][j] = temp[i][j];
            }
        }
    }
};

void Sudoku ::flip(int x) {
    // up-down
    if (x == 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 9; j++) {
                temp[i][j] = form[i][j];
                form[i][j] = form[8 - i][j];
                form[8 - i][j] = temp[i][j];
            }
        }
    }
    //left-right
    else {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 4; j++) {
                temp[i][j] = form[i][j];
                form[i][j] = form[i][8 - j];
                form[i][8 - j] = temp[i][j];
            }
        }
    }
};

//solve
int Sudoku ::solve(int *p) {
    int c=0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int checksum=0;
            //檢查橫的(row)
            if (form[i][j] != 0)
                continue;
            for (int k = 0; k < 9; k++) {
                if (form[i][k] != 0&&solution[i][j][form[i][k]]==0) {
                    solution[i][j][form[i][k]] = 1;
                    checksum++;
                }
            }
            //檢查直的(列)
            for (int k = 0; k < 9; k++) {
                if (form[k][j] != 0&&solution[i][j][form[k][j]]==0) {
                    solution[i][j][form[k][j]] = 1;
                    checksum++;
                }
            }
            //檢查小九宮格
            for (int k = (i / 3) * 3; k < i / 3 * 3 + 3; k++) {
                for (int l = j / 3 * 3; l < j / 3 * 3 + 3; l++) {
                    if (form[k][l] != 0&&solution[i][j][form[k][l]]==0) {
                        solution[i][j][form[k][l]] = 1;
                        checksum++;
                    }
                }
            }
            //輸入未用到數字(ANS)
            if (checksum == 8) {
                for (int l = 1; l < 10; l++) {
                    if (solution[i][j][l] == 0)
                        form[i][j] = l;
                    c++;
                }
            }
            //無解 印出0 跳出
            else if (checksum == 9) {
                cout << "0\n";
                exit(1);
            }
        }
    }
    return c;
};

bool Sudoku::checkplace(int x, int y,int *p) {
    if (row[x][*(p + 9 * x + y) - 1] == 1 || col[y][*(p + 9 * x + y) - 1] == 1 || cell[x / 3][y / 3][*(p + 9 * x + y) - 1] == 1)
        return false;
    else
        return true;
}

void Sudoku::backtrace(int x, int y, int *p) {
    //cout << "x = " << x << " y =  " << y << endl;
    if (x == 9 && y == 0) {
        cout <<"1\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout <<*(p+9*i+j);
                if (j!=8)
                    cout<<" ";
            }
            cout << "\n";
        }
        exit(1);
    } else if (*(p+9*x+y) == 0) {
        for (int i = 1; i <= 9; ++i) {
            *(p+9*x+y)= i;
            if ((solution[x][y][i]==0)&&(Sudoku::checkplace(x, y,p))) { // {solution[x][y][i]&&
                row[x][*(p + 9 * x + y) - 1] = 1;
                col[y][*(p + 9 * x + y) - 1] = 1;
                cell[x / 3][y / 3][*(p + 9 * x + y) - 1] = 1;
                if (y != 8) {
                    Sudoku::backtrace(x, y + 1,p);
                } else {
                    Sudoku::backtrace(x + 1, 0,p);
                }
                row[x][*(p + 9 * x + y) - 1] = 0;
                col[y][*(p + 9 * x + y) - 1] = 0;
                cell[x / 3][y / 3][*(p + 9 * x + y) - 1] = 0;
            }
        }
        *(p+9*x+y)= 0;
        return;
    } else {
        if (y != 8) {
            Sudoku::backtrace(x, y + 1,p);
            return;
        } else {
            Sudoku::backtrace(x + 1, 0,p);
            return;
        }
    }
}
