class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double sum = 0;
        int time = customers[0][0];
        for(auto i: customers){
            if(time>=i[0]){
                sum += (time + i[1] - i[0]);
                time += i[1];
            }
            else{
                sum += i[1];
                time = i[0] + i[1];
            }
        }
        cout<<sum;

        return sum/customers.size();

    }
};