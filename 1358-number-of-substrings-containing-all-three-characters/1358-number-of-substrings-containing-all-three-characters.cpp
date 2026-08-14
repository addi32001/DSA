class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int>lastMin(3,-1);
        int cnt = 0;
        for(int i=0;i<n;i++){
            lastMin[s[i]-'a'] = i;
            cnt += 1 + min(lastMin[0],min(lastMin[1],lastMin[2]));
        }
        return cnt;
    }
};