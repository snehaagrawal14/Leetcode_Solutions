class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n=s.size();
        stack<int> st;
        unordered_set<int> bad;
        for(int i=0; i<n; i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                if(st.empty())
                    bad.insert(i);
                else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            bad.insert(st.top());
            st.pop();
        }
        
        string ans;
        
        for(int i=0; i<n; i++){
            if(!bad.contains(i))
                ans+=s[i];
        }
        
        return ans;
        
    }
};