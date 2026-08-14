class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        for(int i=0;i<k;i++){
            ans += cardPoints[i];
        }
        int sum = ans;
        int l = k-1,r = n-1;
        while(l>=0){
            sum -= cardPoints[l];
            sum += cardPoints[r];
            l--;
            r--;
            ans = max(ans,sum);

        }
        return ans;
    }
};