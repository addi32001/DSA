class Solution {
public:
    void solve(string curr, int open,int close,vector<string>&res,int n){
        if(curr.length()== 2*n){
            res.push_back(curr);
            return;
        }
        if(open<n)  solve(curr+'(', open+1,close,res,n);
        if(close<open) solve(curr+ ')', open, close+1,res,n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve("",0,0,res,n);
        return res;
    }
};