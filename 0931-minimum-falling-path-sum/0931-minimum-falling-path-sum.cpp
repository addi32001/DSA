class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n = matrix.size();
        if(j<0 || j==n) return 1e9;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        int dg_left = matrix[i][j] + solve(i+1,j-1,matrix,dp);
        int d = matrix[i][j] + solve(i+1,j,matrix,dp);
        int dg_right = matrix[i][j] + solve(i+1,j+1,matrix,dp);
        return dp[i][j]=min(dg_left,min(d, dg_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,0));
        // for(int j=0;j<n;j++){
        //     int temp = solve(0,j,matrix,dp);
        //     ans = min(ans,temp);
        // }
        for(int j = 0;j<n;j++)dp[n-1][j] = matrix[n-1][j];

        for(int i= n-2;i>=0;i--){
            for(int j = 0;j<n;j++){
                    int d = 1e9;
                    int dg_left = 1e9;
                    int dg_right = 1e9;
                    if(j>0)dg_left = matrix[i][j] +dp[i+1][j-1]; 
                    d = matrix[i][j] + dp[i+1][j];
                    if(j<n-1)dg_right = matrix[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(dg_left,min(d, dg_right));
            }
        }
        for(int j = 0;j<n;j++){
            ans = min(ans,dp[0][j]);
        }
        return ans;
    }
};