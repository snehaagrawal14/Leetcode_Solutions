class Solution {
    
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    string base(int b, int n){
        string ans;
        while(n!=0){
            int temp=n%b;
            ans.push_back(temp+'0');
            n/=b;
        }
        return ans;
    }
    
public:
    bool isStrictlyPalindromic(int n) {
        
        for(int i=2; i<=n-2; i++){
            string temp=base(i, n);
            if(isPalindrome(temp)==false)
                return false;
        }
        return true;
        
    }
};