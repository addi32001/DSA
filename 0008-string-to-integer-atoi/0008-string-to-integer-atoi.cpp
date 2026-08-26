class Solution {
public:
    int helper(string& s,int i,int sign,long long  ans){
        int n = s.size();
        if(i>=n || !isdigit(s[i]))return int(sign*ans);
        ans = ans * 10 + (s[i]-'0');

        if(sign*ans >= INT_MAX)return INT_MAX;
        if(sign*ans <= INT_MIN)return INT_MIN;

        return helper(s,i+1,sign,ans);
    }
 
    long long myAtoi(string s) {
        int n = s.length();
        int i=0;
        while(i<n && s[i]==' ')i++;
        int sign = 1;
        if((s[i]=='-' || s[i]=='+')){
            sign = (s[i]=='-')?-1:1;
            i++;
        }
        return helper(s,i,sign,0);
        
    }
};