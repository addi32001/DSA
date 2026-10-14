class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i=1;i<=num;i++){
            if(sum>=10){
                ans += "9";
                sum -= 9;
            }
            else{
                ans += to_string(sum);
                sum -= sum;
            }
        }
        if(sum == 0)return ans;
        else return "";
    }
};