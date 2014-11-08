#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> list) {
    vector<int> dp(list.size(), 0);
    int max = 1;

    dp[0] = 1;
    for (int i = 1; i < (int)list.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (list[i] > list[j]) {
                dp[i] = (dp[i] > dp[j]) ? dp[i] : dp[j];
            }
        }

        dp[i] = 1 + dp[i];

        if (dp[i] > max) {
            max = dp[i];
        }
    }

    return max;
}

int main() {
    int A[] = {1,0,3,4,5,-1,-2,-3,-4,-6,1,2,3,4,5,6,7};
    vector<int> list (A, A + 17);
    cout << LIS(list) << endl;
    return 0;
}
