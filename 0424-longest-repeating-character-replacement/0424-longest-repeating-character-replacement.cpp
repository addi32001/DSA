class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int>hash(26,0);
        int l = 0,r = 0, maxLength = 0,maxfreq = 0;
        while(r<n){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            if((r-l+1)-maxfreq > k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)- maxfreq <= k){
                maxLength = max(maxLength, r-l+1);
            }
            r++;
        }
        return maxLength;
    }
};