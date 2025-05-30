class Solution {
public:
    const int MOD = 1e9 + 7;
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        int n = oG.size();
        int m = oG[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        dp[1][1] = (oG[0][0] == 0) ? 1 : 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (oG[i][j] == 1 || (i == 0 && j == 0)) continue;
                dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j + 1]);
            }
        }

        return dp[n][m];
    }
};
