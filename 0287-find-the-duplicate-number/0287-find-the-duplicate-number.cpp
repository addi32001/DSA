class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            int temp = abs(arr[i])%n;
            if(arr[temp] <0) return temp;
            arr[temp] = -arr[temp];
        }
        return -1;
    }
};