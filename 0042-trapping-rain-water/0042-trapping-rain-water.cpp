class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        // creating two array to store max height before and after current height
        vector<int> l_max(n, 0);
        vector<int> r_max(n, 0);
        
        // initializing l_max and r_max
        l_max[0]=height[0];
        for(int i=1; i<n; i++)
            l_max[i]=max(l_max[i-1], height[i]);
        r_max[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--)
            r_max[i]=max(r_max[i+1], height[i]);
        
        // calculating ans
        int ans=0;
        for(int i=0; i<n; i++)
            ans += min(l_max[i], r_max[i]) - height[i];
        
        return ans;
        
    }
};