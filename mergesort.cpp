#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &list, int s1, int e1, int s2, int e2) {
    vector<int> result;

    int i = s1;
    int j = s2;
    while (i <= e1 && j <= e2) {
        if (list[i] < list[j]) {
            result.push_back(list[i]);
            ++i;
        } else {
            result.push_back(list[j]);
            ++j;
        }
    }

    if (j >= e2) {
        while (i <= e1) {
            result.push_back(list[i]);
            ++i;
        }
    }

    if (i >= e1) {
        while (j <= e2) {
            result.push_back(list[j]);
            ++j;
        }
    }

    copy(result.begin(), result.end(), &list[s1]);
}

void mergeSort(vector<int> &list, int start, int end) {
    if (start == end) {
        return;
    }

    int middle = (start + end)/2;
    mergeSort(list, start, middle);
    mergeSort(list, middle + 1, end);

    merge(list, start, middle, middle + 1, end);
}

int main() {
    int A[] = {5,4,3,2};
    vector<int> list(A, A + 4);
    mergeSort(list, 0, 3);
    copy(list.begin(), list.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
