#include <bits/stdc++.h>

using namespace std;
#define MIN -1

int main() {
    int n = 8;
    int value[] = {3, 5, 8, 9, 10, 17, 17, 20};

    int dp[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i], dp[i - j - 1] + value[j]);
        }
    }

    cout << dp[n];

    return 0;
}
