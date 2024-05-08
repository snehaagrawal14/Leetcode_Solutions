class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        priority_queue<pair<int, int>> maxheap;
        for(int i=0; i<n; i++){
            maxheap.push({score[i],i});
        }
        
        vector<string> ans(n);
        int rank = 1;
        while(!maxheap.empty()){
            int index = maxheap.top().second;
            maxheap.pop();
            if(rank == 1){
                ans[index] = "Gold Medal";
            }
            else if(rank == 2){
                ans[index] = "Silver Medal";
            }
            else if(rank == 3){
                ans[index] = "Bronze Medal";
            }
            else{
                ans[index] = to_string(rank);
            }
            rank++;
        }
        
        return ans;
        
    }
};