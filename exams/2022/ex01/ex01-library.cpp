#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createCavern(unsigned int m, unsigned int n) {
    Tile **cav = new Tile*[m];

    for (int i = 0; i < m; i++) {
        cav[i] = new Tile[n];
        for (int j = 0; j < n; j++)
            cav[i][j] = { .content = nothing, .explored = false };
    }

    return cav;
}

void print_lit_tile(Tile tile) {
    switch (tile.content) {
        case nothing:
            cout << " ";
            break;
        case player:
            cout << "X";
            break;
        case rock:
            cout << "#" ;
            break;
        case wumpus:
            cout << "W";
            break;
    }
}

// Task 1(b).  Implement this function
void revealCavern(Tile **cav, unsigned int m, unsigned int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            print_lit_tile(cav[i][j]);
        cout << endl;
    }
}

pair<int, int> find_player(Tile **cav, int m, int n) {
    pair<int, int> position;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (cav[i][j].content == player)
                position = { i, j };
        }
    }

    return position;
}

// check whether or not the distance between (r1, c1) and (r2, c2) is lower than limit
int check_distance(int r1, int c1, int r2, int c2, int limit) {
    return (r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2) < limit * limit;
}

// Task 1(c).  Implement this function
bool movePlayer(Tile **cav, int m, int n, int r, int c) {
    pair<int, int> old_position = find_player(cav, m, n);
    int old_r = old_position.first, old_c = old_position.second;

    if (r >= m || c >= n
        || !check_distance(r, c, old_r, old_c, 5)
        || (cav[r][c].content != nothing && cav[r][c].content != player))
        return false;

    cav[old_r][old_c].content = nothing;
    cav[r][c].content = player;

    return true;
}

// Task 1(d).  Implement this function
void drawCavern(Tile **cav, unsigned int m, unsigned int n) {
    pair<int, int> position = find_player(cav, m, n);
    int r = position.first, c = position.second;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check_distance(r, c, i, j, 4)) {
                print_lit_tile(cav[i][j]);
                cav[i][j].explored = true;
            } else  {
                if (!cav[i][j].explored) cout << '?';
                else if (cav[i][j].content == rock) cout << '#';
                else cout << "-";
            }
        }
        cout << endl;
    }
}

// Do not modify the following function.
// This code (that you don't need to read) places the player
// at location (0,0) and pseudo-randomly places some rocks
// and a Wumpus. The pseudo-random placement depends on the
// value of 'seed'.
void setupCavern(Tile **cav, unsigned int m, unsigned int n,
                 unsigned int seed) {
    mt19937 e; // Pseudo-random number generator
    e.seed(seed);

    // 1/3rd of the tiles are rocks
    unsigned int rocks = (m * n) / 3;
    for (unsigned int i = 0; i < rocks; i++) {
        cav[e()%m][e()%n].content = rock;
    }

    // We never place the Wumpus on row 0 or column 0
    unsigned int row = (e() % (m-1)) + 1;
    unsigned int col = (e() % (n-1)) + 1;
    cav[row][col].content = wumpus;

    cav[0][0].content = player;
}

// Do not modify the following function.
void deleteCavern(Tile **c, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] c[i];
    }
    delete[] c;
}
