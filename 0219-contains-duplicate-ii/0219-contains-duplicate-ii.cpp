class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(freq.count(nums[i])!=0)
                if(abs(i-freq[nums[i]])<=k)
                    return true;
            freq[nums[i]] = i;
        }
        return false;
        
    }
};