class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int remaining = 0;
        int drink = 0;
        while(numBottles){
            drink += numBottles;
            int empty = remaining + numBottles;
            remaining = empty % numExchange;
            numBottles = empty / numExchange;
        }
        return drink;

    }
};