class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        unordered_set<int> bad;
        int n=s.size();
        int brackets=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(')
                brackets++;
            else if(s[i]==')'){
                if(brackets==0)
                    bad.insert(i);
                else
                    brackets--;
            }
        }
        
        
        for(int i=n-1; i>=0 && brackets>0; i--){
            if(s[i]=='('){
                brackets--;
                bad.insert(i);
            }
        }
        
        string ans;
        for(int i=0; i<n; i++){
            if(!bad.contains(i))
                ans+=s[i];
        }
        
        return ans;
        
    }
};