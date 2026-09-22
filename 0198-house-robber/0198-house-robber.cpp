class Solution {
public:
    int helper(int i, vector<int>&nums,vector<int>&dp){
        if(i==0) return nums[i];
        if(i<0)return 0;
        if(dp[i] != -1)return dp[i];
        int pick = nums[i] + helper(i-2,nums,dp);
        int npick = helper(i-1,nums,dp);
        return dp[i]=max(pick,npick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(nums.size()-1,nums,dp);
    }
};