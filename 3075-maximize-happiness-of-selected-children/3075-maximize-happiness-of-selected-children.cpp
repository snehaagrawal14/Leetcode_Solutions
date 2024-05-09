class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        long long ans = 0;
        int selected = 0;
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        for(int i=n-1; i>=0 && selected<k; i--){
            ans += (happiness[i] - selected > 0)?happiness[i] - selected:0;
            selected++;
        }
        
        return ans;
        
    }
};