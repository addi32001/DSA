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
        vector<vector<int>>dp(n,vector<int>((totalSum/2)+1,-1));
        return solve(nums.size()-1,totalSum/2,nums,dp);
    }
};