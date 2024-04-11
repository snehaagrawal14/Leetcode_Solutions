class Solution {
    
public:
    string removeKdigits(string num, int k) {
        
        stack<char> s;
        for(auto i: num){
            while(!s.empty() && k>0 && i<s.top()){
                s.pop();
                k--;
            }
            s.push(i);
        }
        
        while(k>0 && !s.empty()){
            k--;
            s.pop();
        }
        
        string ans;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        size_t pos = ans.find_first_not_of('0');
        ans = (pos == string::npos) ? "0" : ans.substr(pos);
        
        return ans;
        
    }
};