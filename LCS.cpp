#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void serialize(vector<int> list) {
    copy(list.begin(), list.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int LCS(string s1, string s2) {
    if (s1.size() < s2.size()) {
        int smaller_length = s1.size();
        int larger_length = s2.size();

        vector<int> current(smaller_length + 1, 0);
        vector<int> previous(smaller_length + 1, 0);

        for (int i = 1; i <= larger_length; ++i) {
            for (int j = 1; j <=smaller_length; ++j) {
                if (s1[j - 1] == s2[i - 1]) {
                    current[j] = previous[j] + 1;
                } else {
                    current[j] = max(current[j - 1], previous[j]);
                }
            }
            serialize(current);
            previous = current;
        }

        return previous[smaller_length];
    }

    int smaller_length = s2.size();
    int larger_length = s1.size();

    vector<int> current(smaller_length + 1, 0);
    vector<int> previous(smaller_length + 1, 0);

    for (int i = 1; i <= larger_length; ++i) {
        for (int j = 1; j <=smaller_length; ++j) {
            if (s2[j - 1] == s1[i - 1]) {
                current[j] = previous[j] + 1;
            } else {
                current[j] = max(current[j - 1], previous[j]);
            }
        }
        previous = current;
    }

    return previous[smaller_length];
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    cout << LCS(s1, s2);
    return 0;
}
