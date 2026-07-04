#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //base case 
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency map for characters in t
        vector<int> tCounts(128, 0);
        for (char c : t) {
            tCounts[c]++;
        }

        int required = t.length(); // Number of characters still needed
        int left = 0, right = 0;

        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.length()) {
            char c = s[right];
            
            // If the current character is needed, decrement required count
            if (tCounts[c] > 0) {
                required--;
            }
            // Decrement count in map (can go negative for excess chars)
            tCounts[c]--;

            // When we have a valid window (required == 0), try to shrink it from the left
            while (required == 0) {
                // Update minimum window if current is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char d = s[left];
                // Restore the count for the character leaving the window
                tCounts[d]++;
                
                // If the count becomes positive, it means we removed a needed character
                if (tCounts[d] > 0) {
                    required++;
                }
                
                // Move left pointer to shrink
                left++;
            }
            
            // Move right pointer to expand
            right++;
        }

        // Return result
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
