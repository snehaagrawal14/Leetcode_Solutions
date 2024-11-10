class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size())
            return false;
        int i = 0;
        int n = s.size();
        while(i<n && s!=goal){
            i++;
            s.insert(s.begin(), s[n-1]);
            s.pop_back();
        }
        if(s==goal)
            return true;
        return false;
    }
};