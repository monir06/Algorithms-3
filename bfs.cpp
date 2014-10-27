#include <iostream>
#include <vector>
#include <queue>

#define NOT_VISITED -1

using namespace std;

void bfs(int start, int distance[], const vector<vector<int> > adjList) {
    queue<int> processingQueue;
    distance[start] = 0;
    processingQueue.push(start);

    while (!processingQueue.empty()) {
        int element = processingQueue.front();
        processingQueue.pop();

        // Now go through the neighbours
        vector<int> neighbours = adjList[element];
        for (vector<int>::iterator i = neighbours.begin(); i != neighbours.end(); i++) {
            if ( distance[*i] == NOT_VISITED) {
                distance[*i] = distance[element] + 1;
                processingQueue.push(*i);
            }
        }
    }
}

int main() {
    vector<vector<int> > adjList;
    vector<int> level;

    int zeroth[] = {1};
    level = vector<int>(zeroth, zeroth + 1);
    adjList.push_back(level);

    int first[] = {0,2,3};
    level = vector<int>(first, first + 3);
    adjList.push_back(level);

    int second[] = {1,3,4};
    level = vector<int>(second, second + 3);
    adjList.push_back(level);

    int third[] = {1,2,5};
    level = vector<int>(third, third + 3);
    adjList.push_back(level);

    int fourth[] = {2,5,6};
    level = vector<int>(fourth, fourth + 3);
    adjList.push_back(level);

    int fifth[] = {3,4};
    level = vector<int>(fifth, fifth + 2);
    adjList.push_back(level);

    int sixth[] = {4};
    level = vector<int>(sixth, sixth + 1);
    adjList.push_back(level);

    int distance[6];
    for (int i = 0; i < 7; ++i) {
        distance[i] = NOT_VISITED;
    }

    bfs(3, distance, adjList);

    for (int i = 0; i < 7; ++i) {
        cout << distance[i] << "\t";
    }
    cout << endl;

    return 0;
}
