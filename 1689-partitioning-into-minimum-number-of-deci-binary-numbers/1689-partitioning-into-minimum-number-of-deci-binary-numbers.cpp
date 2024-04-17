class Solution {
public:
    int minPartitions(string n) {
        
        int maxiDigit=0;
        for(auto i: n){
            int digit = i-'0';
            maxiDigit = max(maxiDigit, digit);
        }
        
        return maxiDigit;
        
    }
};