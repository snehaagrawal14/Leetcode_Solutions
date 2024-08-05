class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string, int> freq;
        for(auto i: arr)
            freq[i]++;
        
        for(auto i: arr){
            if(freq[i]==1 && k==1)
                return i;
            else if(freq[i]==1)
                k--;
        }
        return "";

    }
};