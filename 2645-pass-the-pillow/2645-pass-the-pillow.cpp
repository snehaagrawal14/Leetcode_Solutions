class Solution {
public:
    int passThePillow(int n, int time) {
        
        bool rl = (time/(n-1))%2;
        int pos = time%(n-1);
        if(rl)
            return n-pos;
        return pos+1;

    }
};