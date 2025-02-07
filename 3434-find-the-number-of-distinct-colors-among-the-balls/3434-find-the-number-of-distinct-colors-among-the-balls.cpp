class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        unordered_map<int, int> balls;
        unordered_map<int, int> colors;
        for(auto i: queries){
            if(balls.count(i[0])!=0){
                colors[balls[i[0]]]--;
                if(colors[balls[i[0]]]==0)
                    colors.erase(balls[i[0]]);
            }
            balls[i[0]] = i[1];
            colors[i[1]]++;
            ans.push_back(colors.size());
        }
        return ans;
    }
};