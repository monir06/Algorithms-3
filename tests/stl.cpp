#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
#include <vector>

using namespace std;

class object {
    public:
        char operator() (char c) {
            return tolower(c);
        }
};

int main() {
    int A[] = {1,2,3,4};
    vector<int> list(A, A + 4);
    transform(list.begin(), list.end(), list.begin(), bind1st(plus<int>(), 1));
    copy(list.begin(), list.end(), ostream_iterator<int>(cout, " "));
    return 0;
}


