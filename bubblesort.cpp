#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void bubblesort(vector<int> &list) {
    vector<int>::iterator temp;
    for (vector<int>::iterator i = list.begin(); i != list.end(); ++i) {
        temp = min_element(i, list.end());
        swap(*i, *temp);
    }
}

int main() {
    int A[] = {5,3,2,-1,9,10};
    vector<int> list(A, A + 6);
    bubblesort(list);
    copy(list.begin(), list.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
