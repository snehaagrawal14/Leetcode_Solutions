class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> s;
        for(auto i: logs){
            if(i=="../" && !s.empty())
                s.pop();
            else if(i=="./")
                continue;
            else if(i!="../")
                s.push(i);
        }
        return s.size();
        
    }
};