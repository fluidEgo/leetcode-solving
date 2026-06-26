class Solution {
public:
    string mergeAlternately(string n3, string n4) {
        string r = "";
        int n1 = n3.length();
        int n2 = n4.length();
        r.reserve(n1 + n2);

        // Run until the maximum length of both strings is reached
        for (int i = 0; i < max(n1, n2); ++i) {
            if (i < n1) {
                r.push_back(n3[i]);
            }
            if (i < n2) { // Notice: This is SEPARATE, not nested!
                r.push_back(n4[i]);
            }
        }

        return r;
    }
};