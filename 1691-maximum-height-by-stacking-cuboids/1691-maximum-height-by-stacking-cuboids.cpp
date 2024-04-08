class Solution {
    
    bool check(vector<int> a, vector<int> b){
        if(a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2])
            return true;
        return false;
    }
    
    
    int solveSpace(int n, vector<vector<int>> &a){
        vector<int> nextRow(n+1, 0);
        vector<int> currRow(n+1, 0);
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include=0;
                if(prev==-1 || check(a[prev], a[curr])){
                    include= a[curr][2] +nextRow[curr+1];
                }
                int exclude=nextRow[prev+1];
                currRow[prev+1] = max(include, exclude);
            }
            nextRow=currRow;
        }
        return currRow[0];
    }
    
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        
        for(auto &i: cuboids){
            sort(i.begin(), i.end());
        }
        
        sort(cuboids.begin(), cuboids.end());
        
        return solveSpace(cuboids.size(), cuboids);
        
    }
};