class Solution {
public:
    bool checkDivisibility(int n) {
        int k = n;
        int sum = 0;
        int prod = 1;
        while(k>0){
            int p = k%10;
            sum  += p;
            prod *= p;
            k = k/10;
        }
        if(n % (sum + prod)== 0)return true;
        else return false;
    }
};