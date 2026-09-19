class Solution {
public:
    set<vector<int>>st;
    void allcomb(vector<int>& arr,int i,vector<int>ans, int target,vector<vector<int>>&allCombination){
        if (i == arr.size()) {
            if (target == 0) {
                allCombination.push_back(ans);
            }
            return;
        }
        if(target >=arr[i]){
            ans.push_back(arr[i]);
            allcomb(arr,i,ans,target-arr[i],allCombination);
            ans.pop_back();
        }
        allcomb(arr,i+1,ans,target,allCombination);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>ans;
        vector<vector<int>>allCombination;
        allcomb(arr,0,ans,target,allCombination);
        return allCombination;
    }
};