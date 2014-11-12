#include <bits/stdc++.h>

using namespace std;

#define NOT_VISITED -1
#define SIZE 1000
#define INF (1e9)

int dp[SIZE][SIZE];
class Solution {
    public:
        int compute_dp(int n, int m, string word1, string word2) {
            if (n == 0 && m == 0) {
                return 0;
            }

            if (n == 0 && m != 0) {
                return m;
            }

            if (m == 0 && n != 0) {
                return n;
            }

            if (dp[n][m] != NOT_VISITED) {
                return dp[n][m];
            }

            int answer = INF;

            if (word1[n - 1] != word2[m - 1]) {
                answer = min (answer, compute_dp(n - 1, m - 1, word1, word2) + 1);
            } else {
                answer = min (answer, compute_dp(n - 1, m - 1, word1, word2));
            }

            answer = min(answer, (compute_dp(n - 1, m, word1, word2) + 1));
            answer = min(answer, (compute_dp(n, m -1, word1, word2) + 1));

            dp[n][m] = answer;
            return answer;
        }

        int minDistance(string word1, string word2) {
            for (int i = 0; i <= (int)word1.size(); ++i) {
                for (int j = 0; j <= (int)word2.size(); ++j) {
                    dp[i][j] = NOT_VISITED;
                }
            }

            return compute_dp(word1.size(), word2.size(), word1, word2);
        }
};

int main() {
    Solution sol = Solution();
    string first, second;
    cin >> first >> second;
    cout << sol.minDistance(first, second) << endl;
    return 0;
}
