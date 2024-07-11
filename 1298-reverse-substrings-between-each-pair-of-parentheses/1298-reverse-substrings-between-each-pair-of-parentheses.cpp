class Solution {
public:
    string reverseParentheses(string s) {
        
        int n = s.size();
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push({s[i], i});
            }
            else if(s[i]==')'){
                auto it = st.top();
                reverse(s.begin()+it.second, s.begin()+i+1);
                st.pop();
            }
        }

        string ans;
        for(auto i: s)
            if(i!=')' && i!='(')
                ans.push_back(i);

        return ans;

    }
};