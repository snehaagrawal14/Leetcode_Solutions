class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string> ans;
        vector<int> freq(26, 0);
        vector<int> curr(26, 0);
        
        for(auto i: words[0])
            freq[i-'a']++;
        
        for(auto i: words){
            for(auto j: i){
                curr[j-'a']++;
            }
            for(int j=0; j<26; j++)
                freq[j] = min(freq[j], curr[j]);
            
            fill(curr.begin(), curr.end(), 0);
        }
        
        for(int i=0; i<26; i++){
            while(freq[i]!=0){
                string temp;
                temp.push_back(i+'a');
                ans.push_back(temp);
                freq[i]--;
            }
        }
        
        return ans;
        
    }
};