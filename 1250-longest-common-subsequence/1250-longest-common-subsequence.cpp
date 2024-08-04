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

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        // return solve(text1, text2, n-1, m-1);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solveMem(text1, text2, n-1, m-1, dp);

    }
};