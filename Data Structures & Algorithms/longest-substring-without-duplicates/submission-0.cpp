#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) { // Renamed function
        vector<int> last_seen(128, -1);
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < s.length(); ++right) {
            char curr = s[right]; // Declare 'curr' inside the loop

            // If the character was seen and is within the current window
            if (last_seen[curr] >= left) {
                left = last_seen[curr] + 1;
            }

            last_seen[curr] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
}; // Correct closing brace for the class