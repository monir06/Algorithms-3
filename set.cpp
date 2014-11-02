#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> isSet;
    isSet.insert(1);
    isSet.insert(2);

    cout << isSet.count(1) << endl;
    cout << isSet.count(3) << endl;
    return 0;
}
