#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // We can safely initialize lowest to INT_MAX, or nums[0] 
        // because we will constantly update it during the search.
        int lowest = 2147483647; 

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Determine which half is perfectly sorted
            if (nums[left] <= nums[mid]) { 
                // 1. The LEFT half is perfectly sorted.
                // 2. The smallest value in this half is guaranteed to be nums[left].
                // 3. Update our global tracker.
                lowest = min(lowest, nums[left]);
                
                // 4. Since we've extracted the minimum from this half, 
                // we discard it and search the right side for an even smaller number.
                left = mid + 1; 
            } else { 
                // 1                . The RIGHT half is perfectly sorted.
                // 2. The smallest value in this half is guaranteed to be nums[mid].
                // 3. Update our global tracker.
                lowest = min(lowest, nums[mid]);
                // 4. Discard the right half and search the left side.
                right = mid - 1; 
            }
        }
        
        return lowest;
    }
};