class Solution {

    int solve(string &a, string &b, int i, int j){
        if(i<0 || j<0)
            return 0;
        int include = 0;
        if(a[i]==b[j])
            include = 1 + solve(a, b, i-1, j-1);
        int exclude = max(solve(a, b, i-1, j), solve(a, b, i, j-1));
        return max(include, exclude);
    }

    int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int include = 0;
        if(a[i]==b[j])
            include = 1 + solveMem(a, b, i-1, j-1, dp);
        int exclude = max(solveMem(a, b, i-1, j, dp), solveMem(a, b, i, j-1, dp));
        return dp[i][j] = max(include, exclude);
    }

    int solveTab(string a, string b){
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int include = 0;
                if(a[i-1]==b[j-1])
                    include = 1 + dp[i-1][j-1];
                int exclude = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(include, exclude);
            }
        }
        return dp[n][m];
    }

    int solveSpace(string a, string b){
        int n = a.size();
        int m = b.size();
        vector<int> curr(m+1, 0);
        vector<int> prev(m+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int include = 0;
                if(a[i-1]==b[j-1])
                    include = 1 + prev[j-1];
                int exclude = max(prev[j], curr[j-1]);
                curr[j] = max(include, exclude);
            }
            prev = curr;
        }
        return prev[m];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        // return solve(text1, text2, n-1, m-1);
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveMem(text1, text2, n-1, m-1, dp);
        // return solveTab(text1, text2);
        return solveSpace(text1, text2);
    }
};