#include <map>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    map<string, int> m;

    // Adding elements
    m["srijan"] = 1;
    m["srijan"]++;
    m["shetty"] = 6;

    // Iterating over the map
    for (map<string, int>::iterator i = m.begin(); i != m.end(); ++i) {
        cout << setw(10) << i->first << setw(5) << i->second << endl;
    }

    // Finding if an element is present in the map
    if ( m.count("srijan") ) {
        cout << endl;
        cout << "Srijan is present in the map" << endl;
    }

    // Removing elements
    m.erase(m.find("srijan"));
    if ( !m.count("srijan") ) {
        cout << endl;
        cout << "Srijan is not present in the map" << endl;
    }

    // Clearing the map
    m.clear();
    return 0;
}
