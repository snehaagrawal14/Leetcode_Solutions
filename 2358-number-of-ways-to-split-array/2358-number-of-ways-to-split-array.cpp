class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> leftSum(n-1, 0);
        int index = 0;
        long long sum = 0;
        for(int i=0; i<n-1; i++){
            sum += nums[i];
            leftSum[index++] = sum;
        }
        vector<long long> rightSum(n-1, 0);
        index = n-2;
        sum = 0;
        for(int i=n-1; i>0; i--){
            sum += nums[i];
            rightSum[index--] = sum;
        }

        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(leftSum[i] >= rightSum[i])
                ans++;
        }

        return ans;
    }
};