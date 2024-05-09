class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        long long ans = 0;
        priority_queue<int> happy;
        for(auto i: happiness)
            happy.push(i);
        int selected = 0;
        while(selected < k && !happy.empty()){
            ans += (happy.top()-selected > 0)?happy.top()-selected:0;
            selected++;
            happy.pop();
        }
        return ans;
        
    }
};