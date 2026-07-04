#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int maxCount = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            count[s[right] - 'A']++;
            
            // Slightly cleaned up the maxCount update for readability
            if (count[s[right] - 'A'] > maxCount) {
                maxCount = count[s[right] - 'A'];
            }
            
            // Check if the current window is invalid
            if ((right - left + 1) > maxCount + k) {
                // Need to decrease the left character and shift the window
                count[s[left] - 'A']--;
                left++;
            }
            
            // Update maxLength AFTER the window has been validated/shifted
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};