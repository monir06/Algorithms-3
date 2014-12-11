#include <queue>
#include <iostream>

#define SIZE 105
#define POINTS 22
#define INFY 1e9
#define MAX_BITMASK 1000005
#define NOT_VISITED -1

using namespace std;

int W, H;
char maze[SIZE][SIZE];
int distances[POINTS][SIZE][SIZE];
int dp[POINTS][MAX_BITMASK];
int checkpoints_count;
vector<pair <int, int> > checkpoints;
queue<pair <int, int> > q;

// Check if a particular position is inside the maze
bool isValid(int i, int j) {
    return (i >= 0 && j >= 0 && i < H && j < W);
}

// Execute a BFS and store the values in the corresponding index
void bfs(int index, pair<int, int> startPoint) {
    // All distances are initialized to zero initially
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            distances[index][i][j] = INFY;
        }
    }

    // Push the first element into the array
    distances[index][startPoint.first][startPoint.second] = 0;
    q.push(make_pair(startPoint.first, startPoint.second));

    int x, y;
    pair <int, int> current;
    while (!q.empty()) {
        current = q.front(); q.pop();
        x = current.first;
        y = current.second;

        if (isValid(x, y + 1) && maze[x][y + 1] != '#' && distances[index][x][y + 1] == INFY) {
            distances[index][x][y + 1] = distances[index][x][y] + 1;
            q.push(make_pair(x, y + 1));
        }

        if (isValid(x, y - 1) && maze[x][y - 1] != '#' && distances[index][x][y - 1] == INFY) {
            distances[index][x][y - 1] = distances[index][x][y] + 1;
            q.push(make_pair(x, y - 1));
        }

        if (isValid(x + 1, y) && maze[x + 1][y] != '#' && distances[index][x + 1][y] == INFY) {
            distances[index][x + 1][y] = distances[index][x][y] + 1;
            q.push(make_pair(x + 1, y));
        }

        if (isValid(x - 1, y) && maze[x - 1][y] != '#' && distances[index][x - 1][y] == INFY) {
            distances[index][x - 1][y] = distances[index][x][y] + 1;
            q.push(make_pair(x - 1, y));
        }
    }
}

// This recursively computes the shortest path
int compute_dp(int current_checkpoint, int checkpoint_bitmask) {
    if (dp[current_checkpoint][checkpoint_bitmask] != NOT_VISITED) {
        return dp[current_checkpoint][checkpoint_bitmask];
    }

    // Loop over all checkpoints except this one
    int answer = INFY;
    for (int i = 0; i < checkpoints_count; ++i) {
        if (i == current_checkpoint) {
            continue;
        }

        // If a particular checkpoint is set
        if ((1 << i) & checkpoint_bitmask) {
            answer = min (answer,
                            compute_dp(i, checkpoint_bitmask - (1 << current_checkpoint)) +
                            distances[current_checkpoint + 1][checkpoints[i].first][checkpoints[i].second]
                         );
        }

    }

    // Store before returning
    dp[current_checkpoint][checkpoint_bitmask] = answer;
    return answer;
}

// The orienteering class
class Orienteering {
    public:
        void main();
};

void Orienteering::main() {
    cin >> W >> H;

    // Take Input from the user
    int start_count = 0;
    int goal_count = 0;
    pair<int, int> start, goal;

    string inputLine;
    for (int i = 0; i < H; ++i) {
        cin >> inputLine;
        for (int j = 0; j < W; ++j) {
            maze[i][j] = inputLine[j];

            if (maze[i][j] == 'S') {
                start_count++;
                start = make_pair(i, j);
            } else if (maze[i][j] == 'G') {
                goal_count++;
                goal = make_pair(i, j);
            } else if (maze[i][j] == '.' || maze[i][j] == '#') {
                continue;
            } else if (maze[i][j] == '@') {
                checkpoints.push_back(make_pair(i, j));
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    // Consider the goal to be a checkpoint as well
    checkpoints.push_back(goal);
    checkpoints_count = checkpoints.size();

    // Execute BFS from the start
    bfs(0, start);

    // Now execute BFS for each of the checkpoints
    for (int i = 0; i < checkpoints_count; ++i) {
        bfs((i + 1), checkpoints[i]);
    }

    // All dp should be initially not visited
    for (int i = 0; i < checkpoints_count; ++i) {
        for (int j = 0; j < (1 << checkpoints_count); ++j) {
            dp[i][j] = NOT_VISITED;
        }
    }

    // Visiting a checkpoint only going through itself equals the distance from start
    for (int i = 0; i < checkpoints_count; ++i) {
        dp[i][(1 << i)] = distances[0][checkpoints[i].first][checkpoints[i].second];
    }

    // Now we recursively compute the answer
    int answer = compute_dp(checkpoints_count - 1, (1 << checkpoints_count) - 1);

    // If we do not reach the goal then we print -1
    if (answer == INFY) {
        cout << -1 << endl;
        return;
    }

    cout << answer << endl;
}

// The main driver program
int main(int argc, char* argv[]) {
    Orienteering o;
    o.main();
    return 0;
}
