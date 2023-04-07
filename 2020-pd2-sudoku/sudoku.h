#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdbool>
using namespace std;

class Sudoku {
  public:
    int form[9][9];
    int temp[9][9];
    int solution[9][9][10];
    int row[9][9], col[9][9], cell[3][3][9];
    Sudoku();

    // generate
    void generate(int x,int y);

    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    int solve(int *p);
    bool checkplace(int x,int y,int *p);
    void backtrace(int x,int y,int *p);
};

#endif // SUDOKU_H
