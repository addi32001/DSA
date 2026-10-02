class Solution {
public:
    int solve(int ind,int target, vector<int>& coins,vector<vector<int>>&dp){
        if(ind == 0){
            if(target % coins[0]==0)return 1;
            else return 0;
        }
        if(dp[ind][target] != -1)return dp[ind][target];
        int notTake = solve(ind-1,target,coins,dp);
        int take = 0;
        if(coins[ind]<=target)take = solve(ind,target-coins[ind],coins,dp);
        return dp[ind][target]= take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // return solve(n-1,amount,coins,dp);
        for(int i=0;i<=amount;i++){
            if(i % coins[0]==0)dp[0][i]=1;
        }
        for(int ind=1;ind<n;ind++){
            for(int target = 0;target<=amount;target++){
                long long notTake = dp[ind-1][target];
                long long take = 0;
                if(coins[ind]<=target)take = dp[ind][target-coins[ind]];
                dp[ind][target]= (take + notTake)%INT_MAX;

            }
        }
        return dp[n-1][amount];
    }
};