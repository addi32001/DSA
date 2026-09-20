class Solution {
public:
    void solve(int ind,vector<int>&ds,vector<vector<int>>&ans,int k,int n){
         if(ds.size()==k){
            if(n == 0){
                ans.push_back(ds);
                return;
            }
        }
        if(n<=0)return;


        for(int i = ind;i<10;i++){
            if(i>n)break;
            ds.push_back(i);
            solve(i+1,ds,ans,k,n-i);
            ds.pop_back();

        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        solve(1,ds,ans,k,n);
        return ans;
    }
};