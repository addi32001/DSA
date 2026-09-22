class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        //return helper(nums.size()-1,nums,dp);
        dp[0] = nums[0];
        if(n==1)return dp[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int take = nums[i] + dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i != 0)temp1.push_back(nums[i]);
            if(i != n-1)temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};