#include <bits/stdc++.h>

using namespace std;

int main() {
    int A[] = {10,15,6,23,9,19};
    vector<int> list (A, A + 6);

    make_heap(list.begin(), list.end());
    cout << list.front() << endl;

    list.push_back(1); push_heap(list.begin(), list.end());
    cout << list.front() << endl;

    pop_heap(list.begin(), list.end()); list.pop_back();
    cout << list.front() << endl;

    return 0;
}
