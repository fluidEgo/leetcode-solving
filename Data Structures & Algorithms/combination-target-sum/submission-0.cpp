class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int target, int i, vector<int>& current, vector<vector<int>>& result) {
        // 1. BASE CASE: SUCCESS
        if(target==0) {result.push_back(current); return;}
        // If target is exactly 0, we found a valid combination! 
        // -> Push 'current' into 'result' and return.

        // 2. BASE CASE: FAILURE
        // If target goes below 0 OR we run out of numbers (i >= nums.size())
        // -> return immediately.
        if(target<0 || i >= nums.size()) return;
        // 3. DECISION 1: INCLUDE nums[i]
        // -> Add nums[i] to 'current'
        current.push_back(nums[i]);
        backtrack(nums, target - nums[i], i,current, result);
        current.pop_back();
        // -> Call backtrack(...) -> What happens to target? Do we change 'i'?
        // -> Remove nums[i] from 'current' (This is the actual "backtracking" step!)

        // 4. DECISION 2: SKIP nums[i] entirely
        // -> Call backtrack(...) -> We don't change target, but we move to index i + 1.
        backtrack(nums, target, i+1,current,result);
    }
};