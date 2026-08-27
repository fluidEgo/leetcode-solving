class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        sort(nums.begin(), nums.end()); 
        
        backtrack(nums, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int target, int i, vector<int>& current, vector<vector<int>>& result) {
        // 1. BASE CASE: SUCCESS
        if (target == 0) {
            result.push_back(current); 
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            
            if (nums[j] > target) {
                break; 
            }
            current.push_back(nums[j]);

            backtrack(nums, target - nums[j], j, current, result);
            
            current.pop_back();
        }
    }
};