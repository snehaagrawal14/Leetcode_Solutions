class Solution {

    int solve(int index, int end, vector<int>& slices, int n){
        if(n<=0 || index > end)
            return 0;
        
        int include = slices[index] + solve(index+2, end, slices, n-1);
        int exclude = solve(index+1, end, slices, n);
        return max(include, exclude);
    }

    int solveMem(int index, int end, vector<int>& slices, int n, vector<vector<int>> &dp){
        if(n<=0 || index > end)
            return 0;

        if(dp[index][n] != -1)
            return dp[index][n];
        
        int include = slices[index] + solveMem(index+2, end, slices, n-1, dp);
        int exclude = solveMem(index+1, end, slices, n, dp);
        return dp[index][n] = max(include, exclude);
    }

    int solveTab(vector<int>& slices){

        int k = slices.size();

        vector<vector<int>> dp1(k+2, vector<int>(k+2, 0));
        vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));

        for(int index = k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int include = slices[index] + dp1[index+2][n-1];
                int exclude = dp1[index+1][n];
                dp1[index][n] = max(include, exclude);
            }
        }

        for(int index = k-1; index>=1; index--){
            for(int n=1; n<=k/3; n++){
                int include = slices[index] + dp2[index+2][n-1];
                int exclude = dp2[index+1][n];
                dp2[index][n] = max(include, exclude);
            }
        }

        return max(dp1[0][k/3], dp2[1][k/3]);
        
    }

public:
    int maxSizeSlices(vector<int>& slices) {

        // int n = slices.size();
        // return max(solve(0, n-2, slices, n/3), solve(1, n-1, slices, n/3)); 

        // vector<vector<int>> dp1(n, vector<int>(n, -1));
        // vector<vector<int>> dp2(n, vector<int>(n, -1));
        // return max(solveMem(0, n-2, slices, n/3, dp1), solveMem(1, n-1, slices, n/3, dp2)); 

        return solveTab(slices);

    }
};