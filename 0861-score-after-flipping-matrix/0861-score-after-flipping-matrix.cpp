class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        // checking for rows
        for(int row=0; row<n; row++){
            if(grid[row][0]==0){
                for(int col=0; col<m; col++){
                    grid[row][col] = !grid[row][col];
                }
            }
        }
        
        // checking for columns
        for(int col=1; col<m; col++){
            int count = 0;
            for(int row=0; row<n; row++){
                count += (grid[row][col]==0)?1:0;
            }
            if(count > n-count){
                for(int row=0; row<n; row++){
                    grid[row][col] = !grid[row][col];
                }
            }
        }
        
        // storing ans
        for(int row=0; row<n; row++){
            int curr = 0;
            for(int col=0; col<m; col++){
                curr = curr<<1 | grid[row][col];
            }
            ans += curr;
        }
        
        // returning ans
        return ans;
        
    }
};