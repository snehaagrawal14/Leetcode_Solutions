class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        string top = "ab";
        int top_score = x;
        string bot = "ba";
        int bot_score = y;
        if(y > x){
            swap(top, bot);
            swap(top_score, bot_score);
        }

        string st;
        int score = 0;
        for(auto i: s){
            if(!st.empty() && i==top[1] && st.back() == top[0]){
                score += top_score;
                st.pop_back();
            }
            else{
                st.push_back(i);
            }
        }
        s = st;
        st.clear();
        for(auto i: s){
            if(!st.empty() && i==bot[1] && st.back() == bot[0]){
                score += bot_score;
                st.pop_back();
            }
            else{
                st.push_back(i);
            }
        }
        return score;

    }
};