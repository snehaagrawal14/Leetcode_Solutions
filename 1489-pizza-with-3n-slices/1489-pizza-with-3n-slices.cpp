class Solution {

    int solve(int index, int end, vector<int>& slices, int n, vector<vector<int>> &dp){
        if(n<=0 || index > end)
            return 0;

        if(dp[index][n] != -1)
            return dp[index][n];
        
        int include = slices[index] + solve(index+2, end, slices, n-1, dp);
        int exclude = solve(index+1, end, slices, n, dp);
        return dp[index][n] = max(include, exclude);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        return max(solve(0, n-2, slices, n/3, dp1), solve(1, n-1, slices, n/3, dp2)); 
    }
};