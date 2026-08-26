class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int sign = 1;
        long long p = x;
        if(p<0){
            sign = -1;
            p = p * -1;
        }
        while(p > 0){
            
            int digit = p%10;
            if(ans>INT_MAX/10 || ans < INT_MIN/10){
                return 0;
            }
            ans = ans *10 + digit;
            p = p/10;
        }
        return sign * ans;
    }
};