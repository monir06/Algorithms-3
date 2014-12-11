#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    int GBus;
    int A, B;
    int i;
    int cities;
    int city;

    for (int test = 0; test < T; ++test) {
        vector<int> P(5001, 0);
        cin >> GBus;

        for (i = 0; i < GBus; ++i) {
            cin >> A >> B;

            for (int i = A; i <= B; ++i) {
                P[i] += 1;
            }
        }

        cout << "Case #" << (test + 1) << ": ";
        cin >> cities;
        for (i = 0; i < cities; ++i) {
            cin >> city;
            cout << P[city] << " ";
        }
        cout << endl;
    }

    return 0;
}
