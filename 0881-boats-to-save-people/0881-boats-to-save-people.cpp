class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        int ans = 0;
        int i = 0;
        int j = people.size()-1;
        while(i<=j){
            int sum = people[i] + people[j];
            ans++;
            if(sum > limit)
                j--;
            else{
                j--;
                i++;
            }
        }
        return ans;
        
    }
};