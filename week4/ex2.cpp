#include <bits/stdc++.h>

using namespace std;

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

void print_maze(tile **playground, int n, int m, int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (x == j && y == i) cout << "O";
            else if (playground[i][j].type == wood) cout << " ";
            else cout << "*";
        }
        cout << endl;
    }
}

int main() {
    tile **playground;
    char command;
    int n, m, x, y;

    cin >> n >> m;
    x = m / 2; y = n / 2;
    playground = new tile*[n];
    for (int i = 0; i < n; i++) playground[i] = new tile[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == n - 1 || (i == 0 && j != 3) || j == m - 1);
            if (playground[i][j].isWall) playground[i][j].type = stone;
            else playground[i][j].type = wood;
        }
    }

    print_maze(playground, n, m, x, y);

    while (true) {
        cin >> command;
        if (command == 'q') break;
        else if (command == 'r' && x < m - 1 && !playground[y][x + 1].isWall) x++;
        else if (command == 'l' && x > 0 && !playground[y][x - 1].isWall) x--;
        else if (command == 'u' && y > 0 && !playground[y - 1][x].isWall) y--;
        else if (command == 'd' && x < n - 1 && !playground[y + 1][x].isWall) y++;
        print_maze(playground, n, m, x, y);
    }

    return 0;
}
