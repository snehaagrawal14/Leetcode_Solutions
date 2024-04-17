class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int totalSum = (n * (n+1))/2;
        if(m>n)
            return totalSum;
        
        int numberOfTerms = n/m;
        int lastTerm = numberOfTerms * m;
        int firstTerm = m;
        int divisible = (numberOfTerms * (firstTerm + lastTerm)) / 2;
        int notDivisible = totalSum - divisible;
        
        return notDivisible - divisible;
        
    }
};