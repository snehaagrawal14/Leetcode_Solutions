class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n=groupSizes.size();
        vector<vector<int>> ans;
        vector<vector<int>> group(n + 1);
        for(int i = 0; i<n; i++){
            group[groupSizes[i]].push_back(i);
            if(group[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back({});
                swap(ans.back(), group[groupSizes[i]]);
            }
        }
        
        return ans;
        
    }
};