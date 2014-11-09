#include <vector>
#include <iostream>

using namespace std;

int knapsack(int W, int n, int value[], int weight[]) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i-1] <= w) {
                dp[i][w] = max(dp[i - 1][w], value[i-1] + dp[i-1][w - weight[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout << knapsack(W, n, val, wt) << endl;
    return 0;
}
