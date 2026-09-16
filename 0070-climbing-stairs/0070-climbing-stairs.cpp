class Solution {
public:
    
    // int climbStrairsDP(int n,vector<int>&dp) {
    //     if(n<=2)return n;
    //     if(dp[n] != -1)return dp[n]; 
    //     dp[n] = climbStrairsDP(n-1,dp) + climbStrairsDP(n-2,dp);
    //     return dp[n];
    // }
    int climbStairs(int n){
        if(n<=2)return n;
        int curr = 2;
        int prev = 1;
        for(int i = 3;i<=n;i++){
            curr = curr + prev;
            prev = curr - prev;
        }
        return curr;
    }
};