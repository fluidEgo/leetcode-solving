#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public: // Added so the method can be accessed externally
    int maxProfit(const vector<int>& prices) { // Fixed typo: maxProffit -> maxProfit
        if (prices.size() < 2) return 0;       // Fixed: Added () to size

        int left = 0;
        int right = 1;
        int max_profit = 0;
        
        while (right < prices.size()) {
            if (prices[left] < prices[right]) { // Fixed typo: price -> prices
                int curr = prices[right] - prices[left];
                max_profit = max(max_profit, curr); // Fixed: max -> max_profit
            } else {
                left = right;
            }
            right++;
        }
        
        return max_profit;
    }
};