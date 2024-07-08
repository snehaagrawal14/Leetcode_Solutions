class Solution {
public:
    int findTheWinner(int n, int k) {
        
        vector<int> arr;
        for(int i=1; i<=n; i++)
            arr.push_back(i);

        int start = 0;
        while(arr.size()>1){
            int index = (start + k -1)%arr.size();
            arr.erase(arr.begin()+index);
            start = index;
        }
        return arr.back();

    }
};