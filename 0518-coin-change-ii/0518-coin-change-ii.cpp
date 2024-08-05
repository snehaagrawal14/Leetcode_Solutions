class Solution {

    int solve(vector<int> &coins, int amount, int i){
        if(amount == 0)
            return 1;
        if(amount < 0 || i < 0)
            return 0;
        int include = solve(coins, amount-coins[i], i);
        int exclude = solve(coins, amount, i-1);
        return include + exclude;
    }

    int solveMem(vector<int> &coins, int amount, int i, vector<vector<int>> &dp){
        if(amount == 0)
            return 1;
        if(amount < 0 || i < 0)
            return 0;
        if(dp[amount][i]!=-1)
            return dp[amount][i];
        int include = solveMem(coins, amount-coins[i], i, dp);
        int exclude = solveMem(coins, amount, i-1, dp);
        return dp[amount][i] = include + exclude;
    }

    int solveTab(vector<int> &coins, int amt){
        int n = coins.size();
        vector<vector<int>> dp(amt+1, vector<int>(n+1, 0));
        for(int i=0; i<=n; i++)
            dp[0][i] = 1;
        
        for(int amount = 0; amount<=amt; amount++){
            for(int i=1; i<=n; i++){
                int include = 0;
                if(amount-coins[i-1]>=0)
                    include = dp[amount-coins[i-1]][i];
                int exclude = dp[amount][i-1];
                dp[amount][i] = include + exclude;
            }
        }
        return dp[amt][n];
    }

    int solveSpace(vector<int> &coins, int amt){
        int n = coins.size();
        vector<int> curr(amt+1, 0);
        vector<int> prev(amt+1, 0);
        curr[0] = prev [0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int amount = 0; amount<=amt; amount++){
                int include = 0;
                if(amount-coins[i-1]>=0)
                    include = curr[amount-coins[i-1]];
                int exclude = prev[amount];
                curr[amount] = include + exclude;
            }
            prev = curr;
        }
        return curr[amt];
    }

public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        // return solve(coins, amount, coins.size()-1);
        // vector<vector<int>> dp(amount+1, vector<int>(n, -1));
        // return solveMem(coins, amount, n-1, dp);
        // return solveTab(coins, amount);
        return solveSpace(coins, amount);

    }
};