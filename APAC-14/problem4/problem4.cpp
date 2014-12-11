#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int getRow(char location) {
    return (location - 'A') + 1;
}

int getCol(char location) {
    return (location - '0');
}

int main() {
    int T;
    cin >> T;

    int i;
    int n;
    string input;
    char piece;
    string location;
    map<string, char> locations;

    int size = 8;
    bool board[10][10];
    memset(board, false, sizeof(board));
    int row, col;
    int count;

    map<string, char>::iterator location_iterator;

    for (int test = 0; test < T; ++test) {
        cin >> n;

        for(i = 0; i < n; ++i) {
            cin >> input;
            piece = input[3];
            location.push_back(input[0]);
            location.push_back(input[1]);

            locations[location] = piece;
            board[getRow(location[0])][getCol(location[1])] = true;

            location.clear();
        }

        count = 0;
        for (location_iterator = locations.begin(); location_iterator != locations.end(); ++location_iterator) {
            row = getRow(location_iterator->first[0]);
            col = getCol(location_iterator->first[1]);

            if (location_iterator->second == 'K') {

                if ((row + 1 <= size) && board[row + 1][col]) {
                    count++;
                }

                if ((col + 1 <= size) && board[row][col + 1]) {
                    count++;
                }

                if ((col + 1 <= size) && (row + 1 <= size) && board[row + 1][col + 1]) {
                    count++;
                }

                if ((row - 1 >= 1) && board[row - 1][col]) {
                    count++;
                }

                if ((col - 1 >= 1) && board[row][col - 1]) {
                    count++;
                }

                if ((col - 1 >= 1) && (row - 1 >= 1) && board[row - 1][col - 1]) {
                    count++;
                }

                if ((col - 1 >= 1) && (row + 1 <= size) && board[row + 1][col - 1]) {
                    count++;
                }

                if ((col + 1 <= size) && (row - 1 >= 1) && board[row - 1][col + 1]) {
                    count++;
                }
            } else if (location_iterator->second == 'P') {
                if ((col - 1 >= 1) && (row + 1 <= size) && board[row + 1][col - 1]) {
                    count++;
                }

                if ((col + 1 <= size) && (row + 1 <= size) && board[row + 1][col + 1]) {
                    count++;
                }
            }
        }

        cout << "Case #" << (test + 1) << ": " << count << endl;

        memset(board, false, sizeof(board));
        locations.clear();
    }

    return 0;
}
