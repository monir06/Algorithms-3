#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dfs (int rooms[1002][1002], bool visited[1002][1002], int S, int i, int j, int length) {
    if (i > S || j > S || i < 1 || j < 1) {
        return length;
    }

    visited[i][j] = true;

    int path;
    if (i - 1 >= 1 && (rooms[i-1][j] == rooms[i][j] + 1) && !visited[i-1][j]) {
        path = dfs(rooms, visited, S, i - 1, j, length + 1);
    } else if ( i + 1 <= S && (rooms[i + 1][j] == rooms[i][j] + 1) && !visited[i+1][j]) {
        path = dfs(rooms, visited, S, i + 1, j, length + 1);
    } else if (j - 1 >= 1 && (rooms [i][j-1] == rooms[i][j] + 1) && !visited[i][j-1]) {
        path = dfs(rooms, visited, S, i, j - 1, length + 1);
    } else if (j + 1 <= S && (rooms[i][j + 1] == rooms[i][j] + 1) && !visited[i][j+1]) {
        path = dfs(rooms, visited, S, i, j + 1, length + 1);
    } else {
        path = length + 1;
    }

    visited[i][j] = false;

    return path;

}

int main() {
    int T;
    cin >> T;

    int S;
    int i, j;
    int path;
    int max_path;
    int max_room;

    int rooms[1002][1002];
    bool visited[1002][1002];
    memset(visited, false, sizeof(visited));

    for (int test = 0; test < T; ++test) {
        cin >> S;

        for (i = 1; i <= S; ++i) {
            for (j = 1; j <= S; ++j) {
                cin >> rooms[i][j];
            }
        }

        max_room = rooms[1][1];
        max_path = 0;
        for (i = 1; i <= S; ++i) {
            for (j = 1; j <=S; ++j) {
                path = dfs (rooms, visited, S, i, j, 0);

                if (path == max_path && rooms[i][j] <= max_room) {
                    max_path = path;
                    max_room = rooms[i][j];
                } else if (path > max_path) {
                    max_path = path;
                    max_room = rooms[i][j];
                }
            }
        }

        cout << "Case #" << (test + 1) << ": " << max_room << " " << max_path << endl;
    }

    return 0;
}
