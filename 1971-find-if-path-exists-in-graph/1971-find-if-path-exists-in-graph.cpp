class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, list<int>> adj;
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        set<int> visited;
        queue<int> q;
        q.push(source);
        visited.insert(source);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp==destination)
                return true;
            for(auto i: adj[temp]){
                if(!visited.contains(i)){
                    visited.insert(i);
                    q.push(i);
                }
            }
        }
        
        return false;
        
        
    }
};