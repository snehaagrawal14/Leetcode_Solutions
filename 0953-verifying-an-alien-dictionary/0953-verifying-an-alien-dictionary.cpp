class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int dict[26] = {0};
        for(int i=0; i<order.size(); i++){
            dict[order[i]-'a'] = i;
        }
        
        for(int i=1; i<words.size(); i++){
            
            int j;
            for(j=0; j<words[i].size() && j<words[i-1].size() && words[i][j]==words[i-1][j]; j++);
            if(j<words[i-1].size() && j>=words[i].size())
                return false;
            if(j<words[i].size() && j<words[i-1].size() && dict[words[i-1][j]-'a'] > dict[words[i][j]-'a'])
                return false;
            
        }
        return true;
        
    }
};