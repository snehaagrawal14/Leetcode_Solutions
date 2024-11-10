class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;

        string doublestring = s + s;
        
        return doublestring.find(goal)<doublestring.size();
    }
};