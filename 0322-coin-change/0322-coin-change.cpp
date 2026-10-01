class Solution {
public:
    int solve(int ind, int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(ind == 0){
            if(amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }
        if(dp[ind][amount] != -1)return dp[ind][amount];
        int notpick = solve(ind-1,amount,coins,dp);
        int pick = 1e9;
        if(coins[ind]<=amount) pick = 1 + solve(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=min(notpick,pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1, 1e9));

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
        }

        for(int i=1;i<n;i++){
            for(int amnt =0;amnt<=amount;amnt++){
                int notpick = dp[i-1][amnt];
                int pick = 1e9;
                if(coins[i]<=amnt) pick = 1 + dp[i][amnt-coins[i]];
                dp[i][amnt]=min(notpick,pick);
            }
        }

        if(dp[n-1][amount] >= 1e9)
            return -1;
        return dp[n-1][amount];

    }
};