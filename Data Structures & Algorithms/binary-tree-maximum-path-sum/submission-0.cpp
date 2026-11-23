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
    int maxPathSum(TreeNode* root) {
        int best = std::numeric_limits<int>::min();
        maxGain(root, best);
        return best;
    }

private:
    int maxGain(const TreeNode* node, int& best) {
        if (!node) return 0;

        int left_gain = std::max(0, maxGain(node->left, best));
        int right_gain = std::max(0, maxGain(node->right, best));

        best = std::max(best, node->val + left_gain + right_gain);

        return node->val + std::max(left_gain, right_gain);
    }
};