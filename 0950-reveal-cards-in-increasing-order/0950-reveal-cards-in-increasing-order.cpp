class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n=deck.size();
        vector<int> ans(n);
        sort(deck.begin(), deck.end(), greater<int>());
        queue<int> q;
        q.push(deck[0]);
        int i=1;
        while(i<n){
            int temp=q.front();
            q.pop();
            q.push(temp);
            q.push(deck[i++]);
        }
        
        for(int j=n-1; j>=0; j--){
            ans[j]=q.front();
            q.pop();
        }
        return ans;
        
    }
};