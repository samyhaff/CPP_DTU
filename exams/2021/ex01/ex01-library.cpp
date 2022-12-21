#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {
    Square **chessboard = new Square*[n];

    for (int i = 0; i < n; i++) {
        chessboard[i] = new Square[n];
        for (int j = 0; j < n; j++)
            chessboard[i][j] = { .piece = none, .team = nobody };
    }

    return chessboard;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j].piece == none)
                cout << "_ ";
            else if (c[i][j].piece == rook && c[i][j].team == black)
                cout << "R ";
            else if (c[i][j].piece == bishop && c[i][j].team == black)
                cout << "B ";
            else if (c[i][j].piece == bishop && c[i][j].team == white)
                cout << "b ";
            else if (c[i][j].piece == rook && c[i][j].team == white)
                cout << "r ";
        }
        cout << endl;
    }
}

bool valid_move(Square **c, unsigned int n,
                int r1, int c1, int r2, int c2) {
    if (c[r1][c1].piece == none
        || (r1 == r2 && c1 == c2)
        || c[r1][c1].team == c[r2][c2].team) {
        return false;
    } else if (c[r1][c1].piece == bishop && abs(r1 - r2) == abs(c1 - c2)
            || c[r1][c1].piece == rook && (r1 == r2 || c1 == c2)) {
        return true;
    } else {
        return false;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n,
          int r1, int c1, int r2, int c2) {
    if (valid_move(c, n, r1, c1, r2, c2)) {
        c[r2][c2] = c[r1][c1];
        c[r1][c1] = {.piece = none, .team = nobody};
        return true;
    } else {
        return false;
    }
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n,
                int row, int col) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (valid_move(c, n, i, j, row,  col))
                return true;
        }
    }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}
