#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class predicate {
    public:
        predicate(const T &n) : value(n) {}

        bool operator() (const T & element) const {
            return element ++;
        }

    private:
        T value;
};

int main() {
    int A[] = {1,2,3,4,5};
    vector<int> B(A, A + 5);

    replace(B.begin(), B.end(), 2, 3);
    cout << B[1];
    return 0;
}
