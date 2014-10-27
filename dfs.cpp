#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, bool visited[], const vector<vector<int> > & adjList) {
    visited[start] = true;

    vector<int> neighbours = adjList[start];
    for ( vector<int>::iterator i = neighbours.begin(); i != neighbours.end(); i++ ) {
        if ( ! visited[*i] ) {
            dfs( *i, visited, adjList);
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

    bool visited[6];
    for (int i = 0; i < 7; ++i) {
        visited[i] = false;
    }


    for (int i = 0; i < 7; ++i) {
        cout << visited[i] << "\t";
    }
    cout << endl;

    return 0;
}
