class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int digitsum = 0;
            while(nums[i]>0){
                digitsum = digitsum  + nums[i]%10;
                nums[i] = nums[i]/10;
            }
            if(i==digitsum)return i;
        }
        return -1;
    }
};