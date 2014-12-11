#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;

    int n;
    int i;

    map<string, string> itenary;
    map<string, int> locations;
    map<string, int>::iterator locations_iterator;

    string src, dest;
    string origin, end;
    string first, second;

    for (int test = 0; test < T; ++test) {
        cin >> n;

        for(i = 0; i < n; ++i) {
            cin >> src >> dest;
            itenary[src] = dest;

            if (!locations.count(src)) {
                locations[src] = 1;
            } else {
                locations[src] += 1;
            }

            if (!locations.count(dest)) {
                locations[dest] = -1;
            } else {
                locations[dest] -= 1;
            }
        }

        for (locations_iterator = locations.begin(); locations_iterator != locations.end(); ++locations_iterator) {
            if (locations_iterator->second == 1) {
                origin = locations_iterator->first;
            }

            if (locations_iterator->second == -1) {
                end = locations_iterator->first;
            }
        }

        cout << "Case #" << (test + 1) << ": ";
        first = origin;
        second = itenary[first];

        while (second != end) {
            cout << first << "-" << second << " ";
            first = second;
            second = itenary[first];
        }

        cout << first << "-" << second << " ";
        cout << endl;

        itenary.clear();
        locations.clear();
    }

    return 0;
}
