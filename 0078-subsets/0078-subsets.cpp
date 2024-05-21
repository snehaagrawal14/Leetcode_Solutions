class Solution {
    
    void solve(vector<int>& nums, vector<int> temp, vector<vector<int>> &ans, int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        solve(nums, temp, ans, i+1);
        temp.push_back(nums[i]);
        solve(nums, temp, ans, i+1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, temp, ans, 0);
        return ans;
        
    }
};