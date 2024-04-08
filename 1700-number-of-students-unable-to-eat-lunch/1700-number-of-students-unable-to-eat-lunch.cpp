class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int ans=0;
        queue<int> q;
        int top=0;
        int zero=0;
        int one=0;
        for(auto i: students){
            q.push(i);
            if(i==0)
                zero++;
            else
                one++;
        }
        
        
        while(top<sandwiches.size()){
            int temp=q.front();
            q.pop();
            if(temp==sandwiches[top]){
                top++;
                if(temp==0)
                    zero--;
                else
                    one--;
            }
            else if((sandwiches[top]==0 && zero==0) || (sandwiches[top]==1 && one==0)){
                q.push(temp);
                break;
            }
            else
                q.push(temp);
        }
        
        return q.size();
        
    }
};