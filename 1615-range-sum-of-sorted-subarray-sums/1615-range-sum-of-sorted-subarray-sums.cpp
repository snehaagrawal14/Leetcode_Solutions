class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        int m = 1000000007;
        
        vector<int> subarray_sum;
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum= (sum + nums[j])%m;
                subarray_sum.push_back(sum);
            }
        }
        
        sort(subarray_sum.begin(), subarray_sum.end());
        long long ans = 0;
        for(int i=left-1; i<right; i++)
            ans= (ans + subarray_sum[i])%m;
        return ans;
        
    }
};