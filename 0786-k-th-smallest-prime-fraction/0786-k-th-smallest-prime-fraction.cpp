class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue< pair<double, pair<int, int>> > pq;
        
        int n= arr.size();
        for(int i=0; i<n; i++){
            pq.push({-1.0*arr[i]/arr[n-1], {i, n-1}});
        }
        
        while(--k){
            pair<int, int> index = pq.top().second;
            pq.pop();
            int i = index.first;
            int j = index.second-1;
            pq.push({-1.0*arr[i]/arr[j], {i, j}});
        }
        
        pair<int, int> index = pq.top().second;
        return {arr[index.first], arr[index.second]};
        
    }
};