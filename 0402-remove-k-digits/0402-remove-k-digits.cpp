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
        
        string temp;
        while(!s.empty()){
            temp+=s.top();
            s.pop();
        }
        reverse(temp.begin(), temp.end());
        
        string ans;
        bool found=0;
        for(auto i: temp){
            if(i!='0'){
                found=true;
            }
            if(found==true)
                ans+=i;
        }
        
        return (ans.empty()) ? "0" :ans;
        
    }
};