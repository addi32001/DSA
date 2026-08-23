class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int cnt_1 = 0;
        int cnt_2 = 0;
        int sum = 0;
        for(int i=0;i<n/2;i++){
            if(num[i] != '?')sum += num[i]-'0';
            else cnt_1++;
        }
        for(int i=n/2;i<n;i++){
            if(num[i] != '?')sum -= num[i]-'0';
            else cnt_2++;
        }
        if((cnt_1 + cnt_2) % 2 == 1)return true; 
        
        int ans = sum + (cnt_1/2)*9 - (cnt_2/2)*9;
        return ans != 0;
        
    }
};