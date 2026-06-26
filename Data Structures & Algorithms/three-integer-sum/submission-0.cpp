#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      set<vector<int>> unique;
      int n=nums.size();

      for(int i=0; i<n-1; ++i){
        unordered_set<int> seen;
        for (int j=i+1;j<n;++j){
            int c=-(nums[i]+nums[j]);

            if(seen.count(c)){
                vector<int> triplet={nums[i],nums[j],c};
                sort(triplet.begin(),triplet.end());
                unique.insert(triplet);
            }
            seen.insert(nums[j]);
            }
        }
      return vector<vector<int>>(unique.begin(),unique.end());
    }
};