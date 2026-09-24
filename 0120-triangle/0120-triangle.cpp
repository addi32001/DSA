class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i== 0 && j == 0) return triangle[i][j];
        if(i < 0 || j < 0 || j >= triangle[i].size())
            return 1e9;
        if(dp[i][j] != -1)return dp[i][j];
        int up = triangle[i][j] + solve(i-1,j,triangle,dp);
        int dig = triangle[i][j] + solve(i-1,j-1,triangle,dp);

        return dp[i][j]=min(up,dig);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int ans = INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int temp = solve(m-1,i,triangle,dp);
            ans = min(ans,temp);
        }
        return ans;
    }
};