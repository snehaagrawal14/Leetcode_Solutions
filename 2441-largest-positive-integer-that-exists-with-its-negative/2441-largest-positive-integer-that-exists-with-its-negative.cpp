class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        // make a set and will insert all negative elements of array
        set<int> s;
        for(auto i: nums){
            if(i<0){
                s.insert(i);
            }
        }
        
        // find positive largest element who's negative is present in set
        int ans = -1;
        for(auto i: nums){
            if(s.find(-i)!=s.end()){
                ans = max(ans, i);
            }
        }
        
        return ans;
        
    }
};