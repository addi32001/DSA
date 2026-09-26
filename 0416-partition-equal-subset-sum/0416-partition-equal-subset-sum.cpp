class Solution {
public:
    bool solve(int ind, int target, vector<int>& nums,vector<vector<int>>&dp){
        if(target == 0)return true;
        if(ind == 0)return (nums[0]==target);
        if(dp[ind][target] != -1)return dp[ind][target];
        bool notTake = solve(ind-1,target,nums,dp);
        bool take = false;
        if(nums[ind]<=target)take = solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=notTake | take;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        int k = totalSum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        //return solve(nums.size()-1,totalSum/2,nums,dp);
        for(int i=0;i<n;i++)dp[i][0] = true;
        if(nums[0]<=k)dp[0][nums[0]] = true;
        for(int ind=1;ind<n;ind++){
            for(int target = 1; target <= k;target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(nums[ind]<=target)take = dp[ind-1][target-nums[ind]];
                dp[ind][target]=notTake | take;

            }
        }
        return dp[n-1][k];
    }
};