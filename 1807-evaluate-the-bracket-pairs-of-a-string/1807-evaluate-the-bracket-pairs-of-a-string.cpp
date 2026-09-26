class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        map<string,string>mpp;
        for(int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                i++;
                string temp = "";
                while(s[i] !=')'){
                    temp += s[i];
                    i++;
                }
                if(mpp.find(temp)==mpp.end())ans += '?';
                else ans +=mpp[temp];
            }else{
                ans +=s[i];
            }
        }
        return ans;
    }
};