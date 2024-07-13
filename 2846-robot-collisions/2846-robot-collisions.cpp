class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<vector<int>> robots;

        for(int i=0; i<n; i++)
            robots.push_back({positions[i], healths[i], directions[i], i});

        sort(robots.begin(), robots.end());

        vector<vector<int>> stack;
        for(auto &i: robots){
            if(stack.empty() || i[2]=='R' || stack.back()[2]=='L'){
                stack.push_back(i);
                continue;
            }
            bool add = true;
            while(!stack.empty() && i[2]=='L' && stack.back()[2]=='R'){
                int last_health = stack.back()[1];
                if(last_health < i[1]){
                    i[1] -= 1;
                    stack.pop_back();
                }
                else if(last_health > i[1]){
                    stack.back()[1] -= 1;
                    add = false;
                    break;
                }
                else{
                    stack.pop_back();
                    add = false;
                    break;
                }
            }
            if(add)
                stack.push_back(i);
        }

        vector<int> ans;
        sort(stack.begin(), stack.end(), [](vector<int>& a, vector<int>& b) {
            return a[3] < b[3];
        });

        for (auto& i : stack) {
            ans.push_back(i[1]);
        }

        return ans;

    }
};