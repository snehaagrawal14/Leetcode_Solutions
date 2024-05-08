class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        map<int, int> ranks;
        for(auto i: score){
            ranks[i] = 0;
        }
        int j = score.size();
        for(auto &i: ranks){
            i.second = j--;
        }
        vector<string> ans(score.size());
        for(int i=0; i<score.size(); i++){
            if(ranks[score[i]]==1){
                ans[i] = "Gold Medal";
            }
            else if(ranks[score[i]]==2){
                ans[i] = "Silver Medal";
            }
            else if(ranks[score[i]]==3){
                ans[i] = "Bronze Medal";
            }
            else{
                ans[i] = to_string(ranks[score[i]]);
            }
        }
        return ans;
        
    }
};