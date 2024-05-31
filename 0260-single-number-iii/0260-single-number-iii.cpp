class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> ans;
        int x = 0;
        for(auto i: nums)
            x ^= i;
        
        int mask = 1;
        while(!(mask&x))
            mask = mask<<1;
        int d1 = 0;
        int d2 = 0;
        for(auto i: nums){
            if(i & mask)
                d1 ^= i;
            else
                d2 ^= i;
        }
        ans.push_back(d1);
        ans.push_back(d2);
        return ans;
        
    }
};