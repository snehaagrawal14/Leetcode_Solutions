class Solution {
    
    int solve(string &s, int k, int prev, int curr, vector<vector<int>> &dp){
        if(curr>=s.size())
            return 0;
        if(dp[prev][curr]!=-1)
            return dp[prev][curr];
        int include=0;
        if(prev==0 || abs(s[curr]-prev)<=k)
            include = 1 + solve(s, k, s[curr], curr+1, dp);
        int exclude = solve(s, k, prev, curr+1, dp);
        return dp[prev][curr] = max(include, exclude);
    }
    
public:
    int longestIdealString(string s, int k) {
        
        int n=s.size();
        vector<vector<int>> dp(150, vector<int>(n+1, -1));
        return solve(s, k, 0, 0, dp);
        
    }
};