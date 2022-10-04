#include <bits/stdc++.h>

using namespace std;

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

#define NROWS 12
#define NCOLS 16

void print_maze(tile playground[][NCOLS], int x, int y) {
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (x == j && y == i) cout << "O";
            else if (playground[i][j].type == wood) cout << " ";
            else cout << "*";
        }
        cout << endl;
    }
}

int main() {
    tile playground[NROWS][NCOLS];
    char command;
    int x = 5, y = 5;

    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == NROWS - 1 || (i == 0 && j != 3) || j == NCOLS - 1);
            if (playground[i][j].isWall) playground[i][j].type = stone;
            else playground[i][j].type = wood;
        }
    }

    print_maze(playground, x, y);

    while (true) {
        cin >> command;
        if (command == 'q') break;
        else if (command == 'r' && x < NCOLS - 1 && !playground[y][x + 1].isWall) x++;
        else if (command == 'l' && x > 0 && !playground[y][x - 1].isWall) x--;
        else if (command == 'u' && y > 0 && !playground[y - 1][x].isWall) y--;
        else if (command == 'd' && x < NROWS - 1 && !playground[y + 1][x].isWall) y++;
        print_maze(playground, x, y);
    }

    return 0;
}
