#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000
#define INF (1e9)

int matrix[SIZE][SIZE];
int distance1[SIZE][SIZE];
int n, m;

#define MOVEMENTS 3
int move_x[] = {0, -1, -1};
int move_y[] = {-1, 0, -1};

bool isValid(int x, int y) {
    return (x >= 0 && y >=0 && x < n && y < m);
}

int compute_distance(int row, int col) {
    cout << row << " " << col << endl;

    if (distance1[row][col] != INF) {
        return distance1[row][col];
    }

    int answer = INF;
    for (int i = 0; i < MOVEMENTS; ++i) {
        int x = row + move_x[i];
        int y = col + move_y[i];

        if (isValid(x, y)) {
            answer = min (answer, compute_distance(x,y) + matrix[row][col]);
        }
    }

    return distance1[row][col] = answer;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            distance1[i][j] = INF;
        }
    }

    distance1[0][0] = matrix[0][0];
    compute_distance(n - 1, m - 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << distance1[i][j] << " ";
        }
        cout << endl;
    }
}
