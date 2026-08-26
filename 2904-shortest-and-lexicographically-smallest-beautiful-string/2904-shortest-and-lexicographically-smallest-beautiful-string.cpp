#include<cstring>
class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int st = -1;
        string ans = "";
        int cnt  = 0;
        while(r<n){
            if(s[r]=='1')cnt++;
            while(cnt == k){
                while(s[l]=='0'){
                    l++;
                }
                st = l;
                string temp = s.substr(st,r-l+1);
                
               if (ans == "" || temp.length() < ans.length() || (temp.length() == ans.length() && temp < ans)) {
                    ans = temp;
                }
                l++;
                cnt--;
            
            }
            r++;
        }
        return ans;
    }
};