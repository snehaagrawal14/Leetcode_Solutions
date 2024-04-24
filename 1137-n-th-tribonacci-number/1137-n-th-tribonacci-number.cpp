class Solution {
public:
    int tribonacci(int n) {
        int a=0;
        int b=1;
        int c=1;
        if(n==0)
            return a;
        if(n<3)
            return 1;
        int d=a+b+c;
        for(int i=3; i<=n; i++){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};