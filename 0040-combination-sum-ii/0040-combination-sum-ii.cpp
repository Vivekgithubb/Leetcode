class Solution {
public:
 void helper(int ind , int target , vector<int> &ds , vector<vector<int>>& ans, vector<int>& arr, int n ){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for( int i = ind ; i< n;i++){
            if( i > ind && arr[i] == arr[i-1]) continue; //to skip same elements after the current index 
            if(arr[i] > target) break; // i value croses target then since all elemets on right also wont work since the array is sorted
            ds.push_back(arr[i]);
            helper(i+1 , target-arr[i] , ds , ans , arr , n);
            ds.pop_back();
        }
    }   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
         vector<int> ds;
         int n = candidates.size();
         sort(candidates.begin(),candidates.end());
         helper(0, target , ds , ans , candidates , n );
         return ans;
    }
};