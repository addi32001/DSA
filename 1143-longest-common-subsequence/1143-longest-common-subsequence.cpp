class Solution {
public:
    int Solve(int i, int j, string str1, string str2, vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(str1[i]==str2[j]){
            return dp[i][j] = 1 + Solve(i-1,j-1,str1,str2,dp);
        }
        return dp[i][j]=max(Solve(i-1,j,str1,str2,dp), Solve(i,j-1,str1,str2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        //return Solve(n1-1,n2-1,text1,text2,dp);
        // for(int i=0;i<n1;i++){
        //     if(text1[0]==text2[i])dp[i][0] = 1;
        // }
        // for(int i=0;i<n2;i++){
        //     if(text1[i]==text2[0])dp[0][i] = 1;
        // }
        for(int i=1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = max(1 + dp[i-1][j-1],dp[i][j]);
                }       
            }
        }
        return dp[n1][n2];
    }
};