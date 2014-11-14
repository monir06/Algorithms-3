#include <iostream>

using namespace std;

#define SIZE 1000
#define NOT_VISITED -1
int dp[SIZE][SIZE];

int compute_dp(int coinValues[], int totalValue, int n) {
    cout << totalValue << " " << n << endl;
    if (dp[totalValue][n] != NOT_VISITED) {
        return dp[totalValue][n];
    }

    if (totalValue >= coinValues[n - 1]) {
        dp[totalValue][n] = compute_dp(coinValues, totalValue - coinValues[n - 1], n)
                                + compute_dp(coinValues, totalValue, n - 1);
    } else {
        dp[totalValue][n] = compute_dp(coinValues, totalValue, n - 1);
    }

    return dp[totalValue][n];
}

int main() {
    int coinValues[] = {2,5,3,6};
    int n = 4;
    int totalValue = 10;

    for (int i = 0; i <= totalValue; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = NOT_VISITED;
        }
    }

    for (int j = 1; j <= n; ++j) {
        dp[0][j] = 1;
    }

    cout << compute_dp(coinValues, totalValue, n);

    return 0;
}
