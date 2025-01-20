class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, int> row, col;
        vector<pair<int, int>> index(n*m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                index[mat[i][j]-1] = {i, j};
            }
        }
        for(int i=0; i<arr.size(); i++){
            auto currIndex = index[arr[i]-1];
            row[currIndex.first]++;
            col[currIndex.second]++;
            if(row[currIndex.first]==m || col[currIndex.second]==n)
                return i;
        }
        return -1;

    }
};