#include <set>
#include <iostream>
#include <map>

using namespace std;

int main() {
    string word;
    cin >> word;

    map<char, int> letters;

    int current_length = 1;
    int max_length = 0;
    letters[word[0]] = 0;

    for (int i = 1; i < (int) word.size(); ++i) {
        if (letters.count(word[i])) {
            if (current_length > max_length) {
                max_length = current_length + 1;
            }

            current_length = current_length - letters[word[i]];
        } else {
            current_length++;
            letters[word[i]] = i;

            if (current_length > max_length) {
                max_length = current_length;
            }
        }
    }

    cout << max_length << endl;

    return 0;
}
