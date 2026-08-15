class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.length(),n = s.length();
        int l = 0, r = 0, stIdx = -1,cnt =0, minlength = INT_MAX;
        vector<int>hash(256,0);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0)cnt +=1;
            hash[s[r]]--;
            
            while(cnt == m){
                if(r-l+1<minlength){
                    minlength = r-l+1;
                    stIdx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt = cnt-1;
                l++;
            }
            r++;
        }
        return stIdx == -1 ? "" : s.substr(stIdx,minlength);
    }
};