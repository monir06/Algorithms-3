#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> computePI(string pattern) {
    int PI_t[pattern.size()];
    PI_t[0] = 0;

    int len = 0;
    int i = 1;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            PI_t[i] = len;
            i++;
        } else {
            if ( len != 0 ) {
                len = PI_t[len - 1];
            } else {
                PI_t[i] = 0;
                i++;
            }
        }
    }

    vector<int> PI(PI_t, PI_t + pattern.size());
    copy(PI.begin(), PI.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return PI;
}

int match(string text, string pattern, int position, vector<int> PI, int prevMatch) {
    int k = prevMatch;

    while (pattern[k + 1] != text[position] && k > 0) {
        k = PI[k];
    }

    if (pattern[k +1] == text[position]) {
        return k + 1;
    } else {
        return 0;
    }
}

void KMPSearch (string text, string pattern) {
    if (pattern.size() > 1) {
        vector<int> PI = computePI(pattern);
        int patternLength = pattern.size();
        int textLength = text.size();

        int matchLength = 0;
        int prevMatch = 0;
        for (string::size_type i = 0; i < textLength; ++i) {
            matchLength = match(text, pattern, i, PI, prevMatch);
            if (matchLength == patternLength - 1) {
                cout << "Pattern found at position " << (i + 1) << endl;
            }
            prevMatch = matchLength;
        }
    } else if (pattern.size() == 1) {
        char c = pattern[0];
        for (string::size_type i = 0; i < text.size(); ++i) {
            if (text[i] == c) {
                cout << "Pattern found at position " << (i + 1) << endl;
            }
        }
    }

    return;
}

int main() {
    string text, pattern;
    cin >> pattern;
    cin >> text;
    KMPSearch(text, pattern);
    return 0;
}
