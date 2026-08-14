class Solution {
public:
    int niceSubarray(vector<int>& nums, int k){
        if(k<0)return 0;
        int n = nums.size();
        int l = 0, r = 0, cnt = 0, odd_cnt = 0;
        while(r<n){
            if(nums[r]%2 != 0)odd_cnt++;
            while(odd_cnt > k){
                if(nums[l]%2 != 0)odd_cnt--;
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        
        return cnt;
    }
    

    int numberOfSubarrays(vector<int>& nums, int k) {
        return niceSubarray(nums,k) - niceSubarray(nums,k-1);
    }
};