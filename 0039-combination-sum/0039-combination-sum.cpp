class Solution {
public:
    set<vector<int>>st;
    void allcomb(vector<int>& arr,int i,vector<int>ans, int target,vector<vector<int>>&allCombination){
        int n = arr.size();
        if(i==n || target<0)return;

        if(target == 0){
            if(st.find(ans)==st.end()){
                allCombination.push_back(ans);
                st.insert(ans);
            }
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