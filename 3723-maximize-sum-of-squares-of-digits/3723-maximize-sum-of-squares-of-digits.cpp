class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
         if (sum > 9 * num) return "";
        string ans = "";
        for(int i=1;i<=num;i++){
            if(sum>=10){
                ans += "9";
                sum -= 9;
            }
            else{
                ans += '0'+sum;
                sum -= sum;
            }
        }
        if (sum == 0)return ans;
        else return "";
    }
};