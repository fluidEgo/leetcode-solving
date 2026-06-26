#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);
        for (int i = 1; i < n; ++i) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        int suffix_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix_product;
            suffix_product *= nums[i]; 
        }

        return answer;
    }
};
