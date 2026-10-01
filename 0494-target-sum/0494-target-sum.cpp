class Solution {
public:
    int f(int index,vector<int>& nums,int target,vector<vector<int>>&dp){
        if (index == 0 && target == 0 && nums[0] == 0) {
            return 2;
        }
        if (index == 0 && (target == 0 || target == nums[0])) {
            return 1;
        }

        if (index == 0) {
            return 0;
        }
        if(dp[index][target] != -1)return dp[index][target];
        int notTake = f(index-1,nums,target,dp);
        int take  = 0;
        if(nums[index]<=target)take = f(index-1,nums,target-nums[index],dp);
        return dp[index][target]=take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        
        int diff = totalSum-target;
        if(diff<0 || diff%2!=0)return 0;
        vector<vector<int>>dp(n,vector<int>(diff+1,-1));
        return  f(n-1,nums,diff/2,dp);
    }
};