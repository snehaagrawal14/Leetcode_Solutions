class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";
        string temp=strs[0];
        for(int i=1; i<strs.size(); i++){
            string curr=strs[i];
            int j=0;
            while(j<curr.size() && j<temp.size()){
                if(curr[j]!=temp[j])
                    break;
                ans.push_back(curr[j]);
                j++;
            }
            temp="";
            swap(ans, temp);
        }
        
        ans=temp;
        return ans;
        
    }
};