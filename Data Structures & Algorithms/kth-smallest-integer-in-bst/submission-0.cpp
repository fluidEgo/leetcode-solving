/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    [[nodiscard]] int kthSmallest(const TreeNode* root, int k) const {
        std::vector<const TreeNode*> stk;
        const TreeNode* curr = root;

        while (curr != nullptr || !stk.empty()) {
            while (curr != nullptr) {
                stk.emplace_back(curr);
                curr = curr->left;
            }

            curr = stk.back();
            stk.pop_back();

            --k;
            if (k == 0) {
                return curr->val;
            }
            curr = curr->right;
        }

        return -1;
    }
};
