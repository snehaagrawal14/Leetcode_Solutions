class Solution {
public:
    string makeGood(string s) {
        
        stack<char> st;
        for(int i=s.size()-1; i>=0; i--){
            if(!st.empty() && (st.top()==s[i]-32 || st.top()==s[i]+32))
                st.pop();
            else
                st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};